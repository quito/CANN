
#include <stdlib.h>
#include "list.h"

t_list		*allocateNode(void *data)
{
  t_list	*new;

  new = malloc(sizeof(*new));
  if (!new)
    return (NULL);
  new->data = data;
  new->next = NULL;
  return new;
}

t_list		*pushBack(t_list *list, void *data)
{
  t_list	*begin;
  t_list	*prev;
  t_list	*new;

  begin = list;
  prev = NULL;
  while (list)
    {
      prev = list;
      list = list->next;
    }
  new = allocateNode(data);
  if (prev == NULL)
    begin = new;
  else
    prev->next = new;
  return begin;
}
