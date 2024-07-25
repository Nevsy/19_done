#include "ft_list.h"

void	ft_list_reverse(t_list **begin)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = 0;
	current = *begin;
	next = 0;
	while (current != 0)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin = prev;
}