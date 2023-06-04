#include "../../headers/minishell.h"

t_list *ft_lstnew_env(char *var)
{
	t_list *list = (t_list *) malloc (sizeof(t_list));
	list ->env.str = var;
	list ->env.printed = 0;
	list ->cmd.cmd= NULL;
	list ->next = NULL;
	list->in_fd = -1;
	list->out_fd = -1;
	return (list);
}

t_list *ft_lstnew_cmd(char **cmd)
{
	t_list *list = (t_list *) malloc (sizeof(t_list));
	list ->env.str = NULL;
	list ->env.printed = 0;
	list ->cmd.cmd = cmd;
	list ->next = NULL;
	list->in_fd = STDIN_FILENO;
	list->out_fd = STDOUT_FILENO;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current -> next != NULL)
		current = current -> next;
	return (current);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		ft_lstlast(*lst) -> next = new;
	}
}

void	ft_lstprint_env(t_list *lst)
{
	t_list *node;
	
	node = lst;
	while (node != NULL)
	{
		printf("%s\n", node->env.str);
		node = node->next;
	}
}

