/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:39:49 by qhonore           #+#    #+#             */
/*   Updated: 2016/11/29 10:45:24 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\f' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}
