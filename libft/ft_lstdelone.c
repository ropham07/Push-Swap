/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:39:51 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/03 18:48:32 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node;
	char	*str;

	str = malloc(sizeof(char) * 6);
	if (!str)
		return (1);
	str[0] = 'h'; str[1] = 'e'; str[2] = 'l';
	str[3] = 'l'; str[4] = 'o'; str[5] = '\0';

	node = ft_lstnew(str);
	printf("Avant : %s\n", (char *)node->content);

	ft_lstdelone(node, del);
	printf("Après : nœud libéré ✓\n");

	return (0);
}
*/