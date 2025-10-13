#ifndef MALLOC_H
# define MALLOC_H

#include "../libft/src/libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NO_FILE -1
#define NO_OFFSET 0
#define TINY_MALLOC_SIZE
#define TINY_BLOCK
#define SMALL_BLOCK_SIZE
#define SMALL_BLOCK
#define LARGE_BLOCK_SIZE
#define LARGE_BLOCK
#define MALLOC_ERROR "Malloc: failed to allocate memory\n"

void *ft_malloc(size_t size);

#endif
