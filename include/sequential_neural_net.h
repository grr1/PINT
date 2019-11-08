

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
      std::vector<PTensor*> * weights;

    public:
      SequentialNet();
      ~SequentialNet();
      void addLayer(int inSize, int outSize);
      PTensor run(PTensor * input);
  };

}


#endif
