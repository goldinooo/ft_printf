/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:23:44 by retahri           #+#    #+#             */
/*   Updated: 2024/11/21 09:46:07 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_all(const char s, va_list holder)
{
	int	len;

	len = 0;
	if (s == 'i' || s == 'd')
		len += ft_putnbr(va_arg(holder, int));
	else if (s == 'c')
		len += ft_putchar(va_arg(holder, int));
	else if (s == 's')
		len += ft_putstr(va_arg(holder, char *));
	else if (s == 'x')
		len += ft_putnbr_base(va_arg(holder, unsigned int), 16);
	else if (s == 'X')
		len += ft_putnbr_base_m(va_arg(holder, unsigned int), 16);
	else if (s == '%')
		len += ft_putchar('%');
	else if (s == 'u')
		len += ft_putnbr_base(va_arg(holder, unsigned int), 10);
	else if (s == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		len += 2;
		len += ft_putnbr_base(va_arg(holder, unsigned long), 16);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = ft_all(*(++str), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (ft_putchar(*str) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(vargs);
	return (len);
}

// int main()
// {
// 	int len;

// 	len = ft_printf("%d\n",1);
// 	printf("%d\n", len);
// 	len = printf("%d\n", 1);
// 	printf("%d", len);
// }