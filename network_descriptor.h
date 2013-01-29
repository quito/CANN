
#ifndef NETWORK_DESCRIPTOR_H_
# define NETWORK_DESCRIPTOR_H_

enum e_NetworkShape
  {
    SIMPLE_MLP = 1,
    ALL_SELF_CONNECTED = 2,
    ALL_TO_ALL = 4,
    NO_BIAIS = 8,
    END_OF_SHAPES
  };

typedef struct	s_ANN_des
{
  unsigned	*sizesLayers;
  unsigned	**connectionsTab;
  unsigned	sizeConnectionsTab;
  
}		t_ANN_des;

typedef struct		s_networkShape
{
  enum e_NetworkShape	s;
  void			(*func)(t_ANN_des*)
}			t_networkShape;

t_ANN_des		*createNetworkDescriptor(unsigned *sizesLayers, unsigned size);

#endif
