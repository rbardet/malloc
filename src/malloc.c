#include "malloc.h"

void *ft_malloc(size_t size) {
	if (size == 0) {
		return (NULL);
	}


	type __type = alloc_type(size);
	if (__type == LARGE) {
		return (alloc_zone(__type, size, size));
	}

	void *free = find_free_zone(__type, size);
	if (!free) {
		size_t zone_size = alloc_size(__type);
		free = alloc_zone(__type, zone_size, size);
	}
	return (free);
}
