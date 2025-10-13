#include "malloc.h"

int main(void) {
	char *ptr = malloc(sizeof(char) * (100));
	ft_free(ptr);
	return (0);
}
