/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:57:38 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:02:26 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int main(void)
{
    t_list  *lst;
    t_list  *last;

    lst = NULL;

    // ---- TEST 1 : liste vide ----
    printf("=== Test 1 : liste vide ===\n");
    last = ft_lstlast(lst);
    printf("dernier : %p (doit etre NULL)\n\n", last);

    // ---- TEST 2 : liste d'un element ----
    printf("=== Test 2 : un element ===\n");
    ft_lstadd_front(&lst, ft_lstnew("A"));
    last = ft_lstlast(lst);
    printf("dernier : %s (doit etre A)\n", (char *)last->content);
    printf("next    : %p (doit etre NULL)\n\n", last->next);

    // ---- TEST 3 : liste de trois elements ----
    printf("=== Test 3 : trois elements ===\n");
    ft_lstadd_front(&lst, ft_lstnew("B"));
    ft_lstadd_front(&lst, ft_lstnew("C"));
    last = ft_lstlast(lst);
    printf("liste   : C -> B -> A -> NULL\n");
    printf("dernier : %s (doit etre A)\n", (char *)last->content);
    printf("next    : %p (doit etre NULL)\n\n", last->next);

    // ---- TEST 4 : la liste n'a pas ete modifiee ----
    printf("=== Test 4 : la liste est intacte apres recherche ===\n");
    printf("premier element : %s (doit etre C)\n", (char *)lst->content);
    printf("dernier element : %s (doit etre A)\n", 
	(char *)ft_lstlast(lst)->content);

    return (0);
}
*/