
#include <stdlib.h>
#include "ANN.h"
#include "network_descriptor.h"

#define NBLAYERS 3

unsigned	*createLayerTab(void)
{
  unsigned	*tab;

  if (!(tab = malloc(sizeof(*tab) * NBLAYERS)))
    return NULL;
  tab[0] = 2;
  tab[1] = 2;
  tab[2] = 1;
  return tab;
}

int main(int ac, char *av[])
{
  t_network	*net;
  unsigned	*tab;
  t_ANN_des	*ann_des;

  tab = createLayerTab();
  ann_des = createNetworkDescriptor(tab, 3);
  net = createNetwork(tab, 3);
  return 0;
}
