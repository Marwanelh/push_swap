/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-hou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:37:44 by mael-hou          #+#    #+#             */
/*   Updated: 2025/12/01 17:42:32 by mael-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**free_all(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**fill_words(char const *s, char c, char **res_arr)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res_arr[i] = ft_substr(s - len, 0, len);
			if (!res_arr[i])
				return (free_all(res_arr));
			i++;
		}
		else
			s++;
	}
	res_arr[i] = NULL;
	return (res_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res_arr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	res_arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res_arr)
		return (NULL);
	return (fill_words(s, c, res_arr));
}
