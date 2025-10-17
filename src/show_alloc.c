#include "malloc.h"

void print_type(type __type) {
	if (__type == TINY) {
		ft_printf("TINY");
	} else if (__type == SMALL) {
		ft_printf("SMALL");
	} else {
		ft_printf("LARGE");
	}
}

void show_alloc_mem() {
	t_zone *tmp = zone;
	while (tmp) {
		print_type(tmp->header.__type);
		ft_printf(" : %p\n", tmp->map);
		tmp = tmp->next;
	}
}
