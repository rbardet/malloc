#include "malloc.h"

void *ft_malloc(size_t size) {
	void *heap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, NO_FILE, NO_OFFSET);
	if (heap == MAP_FAILED) {
		return (NULL);
	}

	return (heap);
}
