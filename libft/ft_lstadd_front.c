/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:30:43 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:02:30 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int main(void)
{
    t_list  *lst;
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;

    lst = NULL;

    // ---- TEST 1 : ajouter un noeud devant une liste vide ----
    printf("=== Test 1 : ajout sur liste vide ===\n");
    node1 = ft_lstnew("premier");
    ft_lstadd_front(&lst, node1);
    printf("liste : [%s] -> NULL\n\n", (char *)lst->content);

    // ---- TEST 2 : ajouter un noeud devant une liste d'un element ----
    printf("=== Test 2 : ajout devant un element ===\n");
    node2 = ft_lstnew("deuxieme");
    ft_lstadd_front(&lst, node2);
    printf("liste : [%s] -> [%s] -> NULL\n\n",
        (char *)lst->content,
        (char *)lst->next->content);

    // ---- TEST 3 : ajouter encore un noeud devant ----
    printf("=== Test 3 : ajout devant deux elements ===\n");
    node3 = ft_lstnew("troisieme");
    ft_lstadd_front(&lst, node3);
    printf("liste : [%s] -> [%s] -> [%s] -> NULL\n\n",
        (char *)lst->content,
        (char *)lst->next->content,
        (char *)lst->next->next->content);

    // ---- TEST 4 : verifier que le dernier next est bien NULL ----
    printf("=== Test 4 : le dernier next est NULL ===\n");
    printf("next du dernier : %p (doit etre NULL)\n\n",
        lst->next->next->next);

    // ---- TEST 5 : protection NULL ----
    printf("=== Test 5 : protection NULL ===\n");
    ft_lstadd_front(NULL, node1);
    ft_lstadd_front(&lst, NULL);
    printf("pas de segfault : OK\n");

    return (0);
}
*/	