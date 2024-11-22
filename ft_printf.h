/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:25:44 by retahri           #+#    #+#             */
/*   Updated: 2024/11/21 09:35:11 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putnbr_base_m(size_t n, size_t base);
int	ft_putnbr_base(size_t n, size_t base);
int	ft_putnbr(long nb);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_printf(const char *str, ...);

#endif