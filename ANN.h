
#ifndef ANN_H_
# define ANN_H_

# include "list.h"

# define ANN_K	1.0

enum e_neuronType
  {
    BIAIS = 1,
    OUTPUT = 2,
    INPUT = 4,
    HIDDEN = 8
  };

typedef struct 
{
  int		sum;
  double	(*activationPtr)(double);
  t_list	*OConnections;
  t_list	*IConnections;
  unsigned	type;
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
