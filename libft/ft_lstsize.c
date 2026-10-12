/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:43:19 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:02:17 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
int main(void)
{
    t_list  *lst;

    lst = NULL;

    // ---- TEST 1 : liste vide ----
    printf("=== Test 1 : liste vide ===\n");
    printf("taille : %d (doit etre 0)\n\n", ft_lstsize(lst));

    // ---- TEST 2 : liste d'un element ----
    printf("=== Test 2 : un element ===\n");
    ft_lstadd_front(&lst, ft_lstnew("A"));
    printf("taille : %d (doit etre 1)\n\n", ft_lstsize(lst));

    // ---- TEST 3 : liste de trois elements ----
    printf("=== Test 3 : trois elements ===\n");
    ft_lstadd_front(&lst, ft_lstnew("B"));
    ft_lstadd_front(&lst, ft_lstnew("C"));
    printf("taille : %d (doit etre 3)\n\n", ft_lstsize(lst));

    // ---- TEST 4 : la liste n'a pas ete modifiee ----
    printf("=== Test 4 : la liste est intacte apres comptage ===\n");
    printf("premier element : %s (doit etre C)\n", (char *)lst->content);
    printf("taille encore   : %d (doit etre 3)\n", ft_lstsize(lst));

    return (0);
}
*/