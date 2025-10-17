#include "malloc.h"

t_zone *zone = NULL;

void *find_free_zone(type __type, size_t size) {
	(void)size;
	t_zone *tmp = zone;
	while (tmp) {
		if (tmp->header.__type == __type) {
			void *mem = tmp->map;
			mem += tmp->header.free;
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

void *alloc_zone(type __type, size_t size) {
	void *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, NO_FILE, NO_OFFSET);
	if (map == MAP_FAILED) {
		return (NULL);
	}

	t_zone *node = (t_zone *)map;
	memset(node, 0, sizeof(t_zone));

	node->map = map;
	node->header.__type = __type;
	node->header.size = size;
	node->header.free = size - sizeof(t_zone);
	node->next = NULL;
	add_to_memory(node);
	return (map);
}
