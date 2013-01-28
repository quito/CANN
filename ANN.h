
#ifndef ANN_H_
# define ANN_H_

# include "list.h"

# define ANN_K_SIGMOID		1.0
# define ANN_BIAIS_VALUE	1.0

# define ANN_RANDOM(rand, y, z) (((double)(rand % y) / y) - z)

enum e_neuronType
  {
    BIAIS = 1,
    OUTPUT = 2,
    INPUT = 4,
    HIDDEN = 8,
    DATA = 16
  };

typedef struct s_neuron
{
  double	sum;
  double	(*activationPtr)(double);
  double	(*getSum)(struct s_neuron *);
  t_list	*OConnections;
  t_list	*IConnections;
  unsigned	type;
}		t_neuron;


typedef struct 
{
  t_neuron	*neuron;
  double	weight;
}		t_connection;

/*
 o-------o--o
          \/ \
          /\  \
 o-------o--o--o---->
          \/  /
          /\ /
 o-------o--o
 |_______|__|__|
   DATA   IH  O
*/
typedef struct 
{
  t_neuron	**layers;
  unsigned	nbLayers;
}		t_network;

#endif
