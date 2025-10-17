#include "malloc.h"

t_zone *zone = NULL;

void *find_free_zone(type __type, size_t size) {
	t_zone *tmp = zone;
	while (tmp) {
		if (tmp->header.__type == __type && tmp->header.free >= size) {
			void *mem = tmp->map;
			mem += tmp->header.size - tmp->header.free + 40;
			tmp->header.free -= size;
			return (mem);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void add_to_memory(t_zone *node) {
	if (!zone) {
		zone = node;
		return ;
	}

	t_zone *tmp = zone;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = node;
	return ;
}

void *alloc_zone(type __type, size_t size, size_t ogsize) {
	void *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, NO_FILE, NO_OFFSET);
	if (map == MAP_FAILED) {
		return (NULL);
	}

	t_zone *node = (t_zone *)map;
	node->map = map;
	node->header.__type = __type;
	node->header.size = size;
	node->start = map;
	node->end = map + size;
	node->header.free = size - (sizeof(t_zone)) + ogsize;
	node->next = NULL;
	add_to_memory(node);
	return (map + sizeof(t_zone) + ogsize);
}
