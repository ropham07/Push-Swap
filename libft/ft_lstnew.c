/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:28:36 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/02 22:02:22 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
int main(void)
{
    char    *str = "hello";
    int     nb = 42;
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;

    // ---- TEST 1 : contenu = une chaîne ----
    printf("=== Test 1 : contenu texte ===\n");
    node1 = ft_lstnew(str);
    printf("On a passé     : \"%s\"\n", str);
    printf("node->content  : \"%s\"\n", (char *)node1->content);
    printf("node->next     : %p (doit être NULL)\n\n", node1->next);

    // ---- TEST 2 : contenu = un entier ----
    printf("=== Test 2 : contenu entier ===\n");
    node2 = ft_lstnew(&nb);
    printf("On a passé     : %d\n", nb);
    printf("node->content  : %d\n", *(int *)node2->content);
    printf("node->next     : %p (doit être NULL)\n\n", node2->next);

    // ---- TEST 3 : contenu = NULL ----
    printf("=== Test 3 : contenu NULL ===\n");
    node3 = ft_lstnew(NULL);
    printf("On a passé     : NULL\n");
    printf("node->content  : %p (doit être NULL)\n", node3->content);
    printf("node->next     : %p (doit être NULL)\n\n", node3->next);

    // ---- TEST 4 : vérifier que les noeuds sont indépendants ----
    printf("=== Test 4 : les noeuds sont indépendants ===\n");
    printf("adresse node1  : %p\n", (void *)node1);
    printf("adresse node2  : %p\n", (void *)node2);
    printf("adresse node3  : %p\n", (void *)node3);
    printf("(toutes les adresses doivent être différentes)\n\n");

    // ---- TEST 5 : modifier le contenu d'un noeud n'affecte pas les autres ----
    printf("=== Test 5 : indépendance des contenus ===\n");
    printf("content node1 avant : \"%s\"\n", (char *)node1->content);
    node1->content = "modifié";
    printf("content node1 après : \"%s\"\n", (char *)node1->content);
    printf("content node2 après : %d (ne doit pas avoir changé)\n",
	 *(int *)node2->content);

    return (0);
}
*/