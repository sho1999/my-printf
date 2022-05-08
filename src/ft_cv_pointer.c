/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:17:22 by smuramat          #+#    #+#             */
/*   Updated: 2022/04/25 19:44:24 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_zero(void)
{
	char	symbol[3];

	symbol[0] = '0';
	symbol[1] = 'x';
	symbol[2] = '0';
	write(1, symbol, 3);
	return (3);
}

int	ft_print_pointer(char *result)
{
	char	symbol[2];

	symbol[0] = '0';
	symbol[1] = 'x';
	write(1, symbol, 2);
	write(1, result, ft_strlen(result));
	return (ft_strlen(result) + 2);
}

static int	ft_num_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_cv_pointer(unsigned long int main_p)
{
	char	*res;
	int		check;
	int		len;

	if (main_p == 0)
		return (ft_zero());
	len = ft_num_len(main_p);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = '\0';
	while (main_p > 0)
	{
		check = main_p % 16;
		if (check > 9)
			res[len - 1] = check - 10 + 'a';
		else
			res[len - 1] = check + '0';
		main_p /= 16;
		len--;
	}
	len = ft_print_pointer(res);
	free(res);
	return (len);
}
