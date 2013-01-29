
#include <stdlib.h>
#include "network_descriptor.h"

static unsigned		getNbNeurons(unsigned *sizesLayers, unsigned size)
{
  unsigned		i = 0;
  unsigned		count = 0;

  while (i < size)
    {
      count += sizesLayers[i];
      ++i;
    }
  return count;
}

static unsigned		**allocateConnectionTab(unsigned nb)
{
  int			i = 0;
  unsigned		**new;

  new = malloc(sizeof(*new) * nb);
  memset(new, 0, sizeof(*new) * nb);
  if (!new)
    return NULL;
  while (i < nb)
    {
      new[i] = malloc(sizeof(**new) * nb);
      if (!(new[i]))
	return NULL;
      memset(new[i], 0, sizeof(**new) * nb);
      i++;
    }
  return new;
}

/* =============== SHAPE ASSIGNATION ================== */

static void		shapeSimpleMlp(t_ANN_des *nd)
{
}

static void		shapeAllSelfConnected(t_ANN_des *nd)
{
}

static void		shapeAllToAll(t_ANN_des *nd)
{
}

static void		shapeNoBiais(t_ANN_des *nd)
{
}

t_networkShape		shapeTab[] =
  {
    {SIMPLE_MLP, shapeSimpleMlp},
    {ALL_SELF_CONNECTED, shapeAllSelfConnected},
    {ALL_TO_ALL, shapeAllToAll},
    {NO_BIAIS, shapeNoBiais}
  };

/* shape is a bitfield (SIMPLE_MLP | NO_BIAIS) */
void			setNetworkShape(t_ANN_des *nd, unsigned shape)
{
  unsigned		i = 0;
  unsigned		end;
  
  end = sizeof(shapeTab) / sizeof(*shapeTab);
  while (i < end)
    {
      if (shape & shapeTab[i].s && shapeTab[i].func)
	shapeTab[i].func(nd);
      ++i;
    }
}

/* ========================================================== */

t_ANN_des		*createNetworkDescriptor(unsigned *sizesLayers, unsigned size)
{
  t_ANN_des		*des;
  unsigned		nb_neurons;

  des = malloc(sizeof(*des));
  if (!des)
    return NULL;
  des->sizesLayers = malloc(size * sizeof(*des->sizesLayers));
  if (!des->sizesLayers)
    return NULL;
  memcpy(des->sizesLayers, sizesLayers, size * sizeof(*sizesLayers));
  nb_neurons = getNbNeurons(sizesLayers, size);
  des->sizeConnectionsTab = nb_neurons;
  des->connectionsTab = allocateConnectionTab(nb_neurons);
  if (!(des->connectionsTab))
    return NULL;
  return (des);
}
