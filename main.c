
#include <stdlib.h>
#include "ANN.h"

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

  tab = createLayerTab();
  net = createNetwork(tab, 3);
  return 0;
}
