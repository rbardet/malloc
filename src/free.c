#include "malloc.h"

void ft_free(void *ptr) {
	if (!ptr) {
		return ;
	}

	printf("%p\n", ptr);
	return ;
}
