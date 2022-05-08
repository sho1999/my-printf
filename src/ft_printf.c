/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:17:22 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/06 20:40:10 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_char(int c);
int	ft_put_str(char *str);
int	ft_put_percent(void);

struct s_printf {
	size_t	space_len;
	int		print_len;
};

static size_t	ft_put_space(const char *style, size_t *flag)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	*flag = 1;
	while (style[i] == ' ' || style[i] == '+' || style[i] == '#')
	{
		if (style[i] == '+')
			*flag = 2;
		if (style[i] == '#')
			*flag = 3;
		len++;
		i++;
	}
	return (len);
}

static int	ft_style(va_list args, const char *style, size_t flag)
{
	int	print_len;

	print_len = 0;
	if (*style == 'c')
		print_len += ft_put_char(va_arg(args, int));
	else if (*style == 'd' || *style == 'i')
		print_len += ft_cv_int(va_arg(args, int), flag);
	else if (*style == 's')
		print_len += ft_put_str(va_arg(args, char *));
	else if (*style == 'p')
		print_len += ft_cv_pointer(va_arg(args, unsigned long int));
	else if (*style == 'u')
		print_len += ft_cv_unsigned(va_arg(args, unsigned int));
	else if (*style == 'x' || *style == 'X')
		print_len += ft_cv_HEX(va_arg(args, unsigned int), *style, flag);
	else if (*style == '%')
		print_len += ft_put_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	struct s_printf	s;
	va_list			args;
	size_t			i;
	size_t			flag;

	s.print_len = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			s.space_len = 0;
			flag = 0;
			if (str[i + 1] == ' ' || str[i + 1] == '+' || str[i + 1] == '#')
				s.space_len = ft_put_space(str + i + 1, &flag);
			s.print_len += ft_style(args, str + i + s.space_len + 1, flag);
			i += s.space_len + 1;
		}
		else
			s.print_len += ft_put_char(str[i]);
		i++;
	}
	va_end(args);
	return (s.print_len);
}
