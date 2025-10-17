#ifndef MALLOC_H
# define MALLOC_H

#include "../libft/src/libft.h"
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>

#define NO_FILE -1
#define NO_OFFSET 0
#define PAGE_SiZE sysconf(_SC_PAGESIZE)
#define TINY_ALLOC 512
#define TINY_ZONE PAGE_SiZE * 16
#define SMALL_ALLOC 2048
#define SMALL_ZONE PAGE_SiZE * 32

typedef enum {
	TINY,
	SMALL,
	LARGE,
	UNDEFINED
}	type;

typedef struct {
	type __type;
	size_t size;
	size_t free;
}	t_header;

typedef struct s_zone {
	t_header header;
	void *map;
	struct s_zone *next;
}	t_zone;

extern t_zone *zone;

void *ft_malloc(size_t size);
type alloc_type(size_t size);
void *alloc_zone(type __type, size_t size);
size_t alloc_size(type __type);
void *find_free_zone(type __type, size_t size);

#endif
