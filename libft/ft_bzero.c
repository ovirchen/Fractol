/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:33:29 by ovirchen          #+#    #+#             */
/*   Updated: 2017/10/27 17:33:30 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	t;
	char	*s_chr;

	if (n == 0)
		return ;
	else
	{
		t = 0;
		s_chr = (char *)s;
		while (t < n)
			s_chr[t++] = '\0';
	}
}