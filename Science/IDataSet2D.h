// Interface for a 2D floating point data set.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_INTERFACE_DATA_SET_2D_H_
#define _OE_INTERFACE_DATA_SET_2D_H_

#include <vector>
#include <string>

#include "IDataSet.h"

namespace OpenEngine {
namespace Science {


/**
 * Interface for a 2D floating point data set.
 * This data set can be plotted using MathGLPlot.
 * @see MathGLPlot
 * @class IDataSet2D IDataSet2D.h ons/MathGL/Science/IDataSet2D.h
 */
class IDataSet2D : public IDataSet {
public:   
    virtual ~IDataSet2D() {};

    virtual std::string GetXName() = 0;
    virtual std::string GetYName() = 0;

    virtual std::vector<float> GetXData() = 0;
    virtual std::vector<float> GetYData() = 0;

    virtual float GetMax() = 0;
    virtual float GetMin() = 0;
};

} // NS Science
} // NS OpenEngine

#endif // _OE_INTERFACE_DATA_SET_2D_H_
