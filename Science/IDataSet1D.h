// Interface for a 1D floating point data set.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_INTERFACE_DATA_SET_1D_H_
#define _OE_INTERFACE_DATA_SET_1D_H_

#include <vector>
#include <string>

#include "IDataSet.h"

namespace OpenEngine {
namespace Science {


/**
 * Interface for a 1D floating point data set.
 * This data set can be plotted using MathGLPlot.
 * @see MathGLPlot
 * @class IDataSet1D IDataSet1D.h ons/MathGL/Science/IDataSet1D.h
 */
class IDataSet1D : public IDataSet {
public:   
    virtual ~IDataSet1D() {};

    virtual std::string GetYName() = 0;

    virtual std::vector<float> GetYData() = 0;
};

} // NS Science
} // NS OpenEngine

#endif // _OE_INTERFACE_DATA_SET_1D_H_
