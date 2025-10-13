#include "malloc.h"

char	*strtruc(char *s)
{
	int		a;
	char	*dest;
	int		longueur;

	a = 0;
	if (!s)
		return (NULL);
	longueur = ft_strlen(s);
	dest = ft_malloc(sizeof(char) * (longueur + 1));
	if (!dest)
		return (NULL);
	while (s[a] != '\0')
	{
		dest[a] = s[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

int main(void) {
	char *str = "SALUT";
	char *str2 = strtruc(str);

	printf("%s\n", str2);
	return (EXIT_SUCCESS);
}
