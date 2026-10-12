/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:39:41 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/04 03:21:22 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/*
int main(void)
{
	t_list  *lst;
	t_list  *new;

	lst = NULL;

	// ---- TEST 1 : ajouter a une liste vide ----
	printf("=== Test 1 : ajouter a une liste vide ===\n");
	new = ft_lstnew("A");
	ft_lstadd_back(&lst, new);
	printf("premier element : %s (doit etre A)\n", (char *)lst->content);
	printf("next           : %p (doit etre NULL)\n\n", lst->next);

	// ---- TEST 2 : ajouter a une liste d'un element ----
	printf("=== Test 2 : ajouter a une liste d'un element ===\n");
	new = ft_lstnew("B");
	ft_lstadd_back(&lst, new);
	printf("liste   : A -> B -> NULL\n");
	printf("dernier element : %s (doit etre B)\n", 
	(char *)ft_lstlast(lst)->content);
	printf("next            : %p (doit etre NULL)\n\n", 
	ft_lstlast(lst)->next);

	// ---- TEST 3 : ajouter a une liste de plusieurs elements ----
	printf("=== Test 3 : ajouter a une liste de plusieurs elements ===\n");
	new = ft_lstnew("C");
	ft_lstadd_back(&lst, new);
	printf("liste   : A -> B -> C -> NULL\n");
	printf("dernier element : %s (doit etre C)\n", 
	(char *)ft_lstlast(lst)->content);
	printf("next            : %p (doit etre NULL)\n\n", 
	ft_lstlast(lst)->next);

	// ---- TEST 4 : la liste n'a pas ete modifiee avant le dernier element ----
	printf("=== Test 4 : la liste est intacte avant le dernier element ===\n");
	printf("premier element : %s (doit etre A)\n", (char *)lst->content);
	printf("deuxieme element: %s (doit etre B)\n", 
	(char *)lst->next->content);
}
*/