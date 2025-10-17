#include "malloc.h"

int main(void) {
	char *str = "CHAINE 1";
	char *str2 = ft_malloc(sizeof(char) * (strlen(str) + 1));
	int i = 0;
	printf("ENUM SIZE: %lu\n", sizeof(type));
	printf("HEADER SIZE: %lu\n", sizeof(t_header));
	while (str[i]) {
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	printf("%s\n", str2);
	char *str3 = "CHAINE 2";
	char *str4 = ft_malloc(sizeof(char) * (strlen(str3) + 1));
	i = 0;
	while (str3[i]) {
		str4[i] = str3[i];
		i++;
	}
	str4[i] = '\0';
	printf("%s\n", str4);
	printf("%s\n", str2);
	show_alloc_mem();
	return (0);
}
