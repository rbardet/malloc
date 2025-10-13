#ifndef MALLOC_H
# define MALLOC_H

#include "../libft/src/libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>


void ft_free(void *ptr);

#endif
