/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroyer <sroyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:07 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/19 11:10:14 by sroyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*get_word(char *str, char *charset, int index)
{
	int		i;
	char	*word;

	i = index;
	while (str[i] && !is_in_charset(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i - index) + 1);
	if (word == NULL)
		return (0);
	i = index;
	while (str[i] && !is_in_charset(str[i], charset))
	{
		word[i - index] = str[i];
		i++;
	}
	word[i - index] = '\0';
	return (word);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i] && !is_in_charset(str[i], charset))
			count++;
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;

	strs = malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i] && !is_in_charset(str[i], charset))
		{
			strs[j] = get_word(str, charset, i);
			j++;
		}
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	strs[j] = NULL;
	return (strs);
}

/*#include <stdio.h>
int	main(void)
{
	char **strs = ft_split(" whew  ddd o\t world   ", " \t");
	int i = 0;
	while (strs[i] != NULL)
	{
		printf("%s : %d\n", strs[i], i);
		i++;
	}
	return (0);
}*/