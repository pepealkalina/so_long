/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:37:24 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/05 18:26:49 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_functionlist(t_list *content, void *(*f)(void *))
{
	t_list	*prueba;

	prueba = (t_list *)malloc(sizeof(t_list));
	if (!prueba)
		return (NULL);
	prueba->content = f(content);
	prueba->next = NULL;
	return (prueba);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	newlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = ft_functionlist(lst->content, f);
		if (!temp)
			ft_lstclear(&newlst, del);
		ft_lstadd_back(&newlst, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (newlst);
}

/*Itera la lista ’lst’ y aplica la función ’f’ al
contenido de cada nodo. Crea una lista resultante
de la aplicación correcta y sucesiva de la función
’f’ sobre cada nodo. La función ’del’ se utiliza
para eliminar el contenido de un nodo, si hace
falta.*/