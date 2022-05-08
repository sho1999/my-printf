/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:00:33 by smuramat          #+#    #+#             */
/*   Updated: 2021/12/13 22:50:19 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
struct s_variables {
	size_t	i;
	size_t	j;
	int		index;
};

static int	*malloc_error(char **malloc)
{
	unsigned int	i;

	i = 0;
	while (malloc[i])
	{
		free(malloc[i]);
		i++;
	}
	free(malloc);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish, char **test)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
	{
		malloc_error(test);
		return (NULL);
	}
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	struct s_variables	S;
	char				**split;

	S.i = 0;
	S.j = 0;
	S.index = -1;
	if (!(s))
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (NULL);
	while (S.i <= ft_strlen(s))
	{
		if (s[S.i] != c && S.index < 0)
			S.index = S.i;
		else if ((s[S.i] == c || S.i == ft_strlen(s)) && S.index >= 0)
		{
			split[S.j++] = word_dup(s, S.index, S.i, split);
			S.index = -1;
		}
		S.i++;
	}
	split[S.j] = 0;
	return (split);
}
