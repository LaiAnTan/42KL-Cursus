#include "../../headers/minishell.h"

void	ft_lst_nodefree(t_list *node)
{
	if (node->env.str != NULL)
		free(node->env.str);
	if(node->cmd.cmd != NULL)
		free_2d_array(&node->cmd.cmd);
	free(node);
}

void	ft_lstfree(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	curr = (*lst);
	while (curr != NULL)
	{
		next = curr->next;
		ft_lst_nodefree(curr);
		curr = next;
	}
	*lst = NULL;
}

void	ft_lstdel_env(t_list **lst, t_list *node)
{
	t_list	*head;
	t_list	*prev;

	if ((*lst) == node)
	{
		(*lst) = (*lst)->next;
		ft_lst_nodefree(node);
		return ;
	}
	head = *lst;
	prev = head;
	while (prev->next != node)
		prev = prev->next;
	prev->next = node->next;
	ft_lst_nodefree(node);
	return ;
}

int		ft_lstsize(t_list *lst)
{
	size_t i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}