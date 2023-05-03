/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:59:32 by sfernand          #+#    #+#             */
/*   Updated: 2022/11/14 17:02:53 by sfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<string.h>

size_t	ft_lensrc(const char *r_src)
{
	int	i;

	i = 0;
	while (r_src[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *r_dest, const char *r_src, size_t len)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_lensrc(r_src);
	if (!len)
		return (lensrc);
	while (r_src[i] && i < len - 1)
	{
		r_dest[i] = r_src[i];
		i++;
	}
	r_dest[i] = '\0';
	return (lensrc);
}
