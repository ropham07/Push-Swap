/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinpham <robinpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:43:25 by robinpham         #+#    #+#             */
/*   Updated: 2026/05/04 04:20:34 by robinpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

/*
void	*to_upper(void *content)
{
	char *str = (char *)content;
	char *new = malloc(ft_strlen(str) + 1);
	for (int i = 0; str[i]; i++)
		new[i] = ft_toupper(str[i]);
	return (new);
}

int	main(void)
{
	t_list *lst = ft_lstnew("hello");
	ft_lstadd_back(&lst, ft_lstnew("world"));

	t_list *result = ft_lstmap(lst, to_upper, free);

	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
}
*/