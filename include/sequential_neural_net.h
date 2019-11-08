

#ifndef SANN_H
#define SANN_H

#include <vector>

namespace pint
{
  class SequentialNet
  {
    private:
      OpNode * in;
      OpNode * out;
      int numLayers;

    public:
      SequentialNet();
      ~SequentialNet();
      std::vector<PTensor*> weights; // TODO: this should be private, but it can't right now
      void addLayer(int inSize, int outSize);
      PTensor run(PTensor * input);
  };

}


#endif
