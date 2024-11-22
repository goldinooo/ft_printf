/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:24:28 by retahri           #+#    #+#             */
/*   Updated: 2024/11/22 07:30:31 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	idx;
	int		write_result;

	idx = 0;
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	while (str[idx])
	{
		write_result = ft_putchar(str[idx]);
		if (write_result == -1)
			return (-1);
		idx++;
	}
	return (idx);
}

int	ft_putnbr(long nb)
{
	long	num;
	int		len;
	int		aux;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	num = nb % 10 + '0';
	if (nb > 9)
	{
		aux = ft_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_base(size_t n, size_t base)
{
	int		len;
	char	*set;
	int		sub_len;

	len = 0;
	set = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (-1);
	if (n >= base)
	{
		sub_len = ft_putnbr_base(n / base, base);
		if (sub_len == -1)
			return (-1);
		len += sub_len;
	}
	if (ft_putchar(set[n % base]) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_putnbr_base_m(size_t n, size_t base)
{
	int		len;
	char	*set;
	int		sub_len;

	len = 0;
	set = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (-1);
	if (n >= base)
	{
		sub_len = ft_putnbr_base_m(n / base, base);
		if (sub_len == -1)
			return (-1);
		len += sub_len;
	}
	len += ft_putchar(set[n % base]);
	return (len);
}
