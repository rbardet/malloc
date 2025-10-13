/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_fixed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ...                                                           +#+
	+:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:55:00 by ...               #+#    #+#             */
/*   Updated: 2025/02/17 15:55:00 by ...              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s, char *set)
{
	int		start;
	int		end;
	int		len;
	char	*res;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (s[start] && is_in_set(s[start], set))
		start++;
	end = ft_strlen(s);
	while (end > start && is_in_set(s[end - 1], set))
		end--;
	len = end - start;
	if (len <= 0)
		return (ft_strdup(""));
	res = ft_substr(s, start, len);
	return (res);
}
