
#include <stdlib.h>
#include "ANN.h"

static inline double	getRandomWeight(void)
{
  return (((double)(rand() % 100) / 100.0) - 0.5);
}

void		connectLayer(t_neuron *layer1, unsigned size1,
			     t_neuron *layer2, unsigned size2)
{
  unsigned	i = 0;
  t_connection	*new;

  while (i < size1)
    {
      new = malloc(sizeof(*new));
      new->neuron = &(layer2[i]);
      new->weight = getRandomWeight();
      layer1[i].OConnections = pushBack(layer1[i].OConnections, new);
      /* layer2[i].OConnections = pushBack(layer2[i].IConnections, new); */
      ++i;
    }
}

void		connectNeurons(t_neuron **layers, unsigned *layersSizes, unsigned size)
{
  unsigned	i = 0;

  while (i + 1 < size)
    {
      connectLayer(layers[i], layersSizes[i], layers[i + 1], layersSizes[i + 1]);
      ++i;
    }
}

void		initNeurons(t_neuron *neurons, unsigned size)
{
  unsigned	i = 0;

  while (i < size)
    {
      neurons[i].sum = 0;
      neurons[i].activationPtr = NULL;
      neurons[i].OConnections = NULL;
      neurons[i].IConnections = NULL;
      ++i;
    }
}

t_network      	*createNetwork(unsigned int *layers, unsigned size)
{
  t_network	*net;
  unsigned	i = 0;

  srand(time(NULL));
  net = malloc(sizeof(*net));
  if (!net)
    return NULL;
  net->layers = malloc(sizeof(*(net->layers)));
  if (!net->layers)
    return NULL;
  while (i < size)
    {
      net->layers[i] = malloc(sizeof(*(net->layers[i])) * layers[i]);      
      initNeurons(net->layers[i], layers[i]);
      ++i;
    }
  connectNeurons(net->layers, layers, size);
  return (net);
}

