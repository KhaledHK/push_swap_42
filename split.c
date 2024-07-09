/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:12:05 by khaled            #+#    #+#             */
/*   Updated: 2024/06/30 23:28:16 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isblanck(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*skipe_blanck(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int	word_count(char *str)
{
	int		n;

	n = 0;
	while (*str != '\0')
	{
		str = skipe_blanck(str);
		if (*str != '\0' && !isblanck(*str))
		{
			n++;
			while (!isblanck(*str) && *str != '\0')
				str++;
		}
	}
	return (n);
}

static char	*get_next_word(char *s)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == ' ')
		++cursor;
	while ((s[cursor + len] != ' ') && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != ' ') && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = word_count(s);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s);
	}
	result_array[i] = NULL;
	return (result_array);
}
