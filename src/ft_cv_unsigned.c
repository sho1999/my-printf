/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:43:03 by smuramat          #+#    #+#             */
/*   Updated: 2022/04/25 19:40:26 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_str(char *str);

static	char	*to_figure(char *x, unsigned int number, unsigned int len)
{
	while (number > 0)
	{
		x[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (x);
}

static unsigned int	ft_len(unsigned int n)
{
	size_t				len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_cv_unsigned(unsigned int main_u)
{
	char					*res_p;
	size_t					len;
	unsigned int			number;

	number = 0;
	len = ft_len(main_u);
	res_p = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res_p))
		return (0);
	res_p[len--] = '\0';
	if (main_u == 0)
		res_p[0] = '0';
	else
		number = main_u;
	res_p = to_figure(res_p, number, len);
	len = ft_put_str(res_p);
	free(res_p);
	return (len);
}
