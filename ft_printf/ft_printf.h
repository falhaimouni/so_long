/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:27:21 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/08 12:36:35 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *c, ...);
int		ft_putnum(int n, int fd);
int		ft_conversion(const char c, va_list arg);
int		ft_pointerhex(size_t n);
size_t	lenst(long n);

#endif
