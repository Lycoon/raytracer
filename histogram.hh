//************************************************
//*                                              *
//*   TP 1&2    (c) 2017 J. FABRIZIO             *
//*                                              *
//*                               LRDE EPITA     *
//*                                              *
//************************************************

#ifndef HISTOGRAM_HH
#define HISTOGRAM_HH

#include "image.hh"

namespace tifo
{

    typedef struct
    {
        unsigned int histogram[IMAGE_NB_LEVELS];
    } histogram_1d;

} // namespace tifo

#endif
