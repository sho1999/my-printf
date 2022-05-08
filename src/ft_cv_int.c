/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:30:01 by smuramat          #+#    #+#             */
/*   Updated: 2022/04/25 19:40:18 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_str(char *str);

static void	ft_flag_chack(int flag)
{
	if (flag == 1)
		write(1, " ", 1);
	else if (flag == 2)
		write(1, "+", 1);
}

int	ft_cv_int(int n, int flag)
{
	int		len;
	char	*num;
	int		sign;

	sign = 1;
	len = 0;
	num = ft_itoa(n);
	ft_flag_chack(flag);
	len = ft_put_str(num);
	free(num);
	return (len);
}
