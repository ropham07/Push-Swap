/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:51:25 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/03 19:41:45 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	(*lst) = NULL;
}

/*
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*node;

	lst = ft_lstnew(ft_strdup("hello"));
	node = ft_lstnew(ft_strdup("world"));
	lst->next = node;

	printf("Avant :\n");
	printf("  node 1 : %s\n", (char *)lst->content);
	printf("  node 2 : %s\n", (char *)lst->next->content);

	ft_lstclear(&lst, del);

	printf("Après :\n");
	if (lst == NULL)
		printf("  liste vide (lst == NULL) ✓\n");

	return (0);
}
*/