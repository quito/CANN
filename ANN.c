
#include <stdlib.h>
#include <math.h>
#include "ANN.h"

/* ==== ACTIVATION FUNCTION ===== */

double		sigmoid(double x)
{
  return (1.0 / (1.0 + (exp(-x * ANN_K_SIGMOID))));
}

/* ==== SUM FUNCTIONS =====*/

double		getSum(struct s_neuron *n)
{
  if (n->type == BIAIS)
    return ANN_BIAIS_VALUE;
  return n->sum;
}

/* ============================== */

static inline double	getRandomWeight(void)
{
  /* return (((double)(rand() % 100) / 100.0) - 0.5); */
  return ANN_RANDOM(rand(), 100, 0.5);
}

void		connectLayer(t_neuron *layer1, unsigned size1,
			     t_neuron *layer2, unsigned size2)
{
  unsigned	i = 0;
  unsigned	j;
  t_connection	*new;

  while (i < size1 + 1) /* +1 for the biais */
    {
      j = 0;
      if (layer1[i].type & DATA)
	{
	    new = malloc(sizeof(*new));
	    new->neuron = &(layer2[i]);
	    new->weight = getRandomWeight();
	    layer1[i].OConnections = pushBack(layer1[i].OConnections, new);	  
	}
      else
	while (j < size2)
	  {
	    new = malloc(sizeof(*new));
	    new->neuron = &(layer2[j]);
	    new->weight = getRandomWeight();
	    layer1[i].OConnections = pushBack(layer1[i].OConnections, new);
	    ++j;
	  }
      ++i;
    }
}

void		connectNeurons(t_neuron **layers, unsigned *layersSizes, unsigned size)
{
  unsigned	i = 0;
  unsigned	idx = 0;

  while (i + 1 < size)
    {
      connectLayer(layers[i], layersSizes[idx], layers[i + 1], layersSizes[idx + 1]);
      if (i)
	++idx;
      ++i;
    }
}

void		initNeurons(t_neuron *neurons, unsigned size, enum e_neuronType type)
{
  unsigned	i = 0;

  while (i < size + 1)
    {
      neurons[i].sum = 0;
      neurons[i].activationPtr = sigmoid;
      neurons[i].OConnections = NULL;
      neurons[i].IConnections = NULL;
      neurons[i].type = type;
      if (i == size)
	{
	  neurons[i].type |= BIAIS;
	  neurons[i].sum = ANN_BIAIS_VALUE;
	}
      ++i;
    }
}

t_network      	*createNetwork(unsigned int *layers, unsigned size)
{
  t_network	*net;
  unsigned	i = 0;
  unsigned	idx = 0;

  srand(time(NULL));
  net = malloc(sizeof(*net));
  if (!net)
    return NULL;
  net->layers = malloc(sizeof(*(net->layers)) * (size + 1)); /* allocate + 1 for Input connection */
  net->nbLayers = size;
  if (!net->layers)
    return NULL;
  while (i < size + 1) /* +1 for the Input DATA layer */
    {
      net->layers[i] = malloc(sizeof(*(net->layers[i])) * (layers[idx] + 1));
      if (i == 0)
	initNeurons(net->layers[i], layers[idx], DATA);
      else if (i == 1)
	initNeurons(net->layers[i], layers[idx], INPUT);
      else if (i == size - 1)
	initNeurons(net->layers[i], layers[idx], OUTPUT);
      else
	initNeurons(net->layers[i], layers[idx], HIDDEN);
      if (i > 0)
	++idx;
      ++i;
    }  
  connectNeurons(net->layers, layers, size + 1); /* +1 for the Input DATA layer */
  return (net);
}

