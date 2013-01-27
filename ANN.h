
#ifndef ANN_H_
# define ANN_H_

# include "list.h"


typedef struct 
{
  int		sum;
  double	(*activationPtr)(double);
  t_list	*OConnections;
  t_list	*IConnections;
}		t_neuron;


typedef struct 
{
  t_neuron	*neuron;
  double	weight;
}		t_connection;

typedef struct 
{
  t_neuron	**layers;
}		t_network;

#endif
