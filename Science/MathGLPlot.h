// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_MATH_G_L_PLOT_H_
#define _OE_MATH_G_L_PLOT_H_

#include <mgl/mgl_zb.h>
#include <vector>

#include <Resources/Texture2D.h>

namespace OpenEngine {
namespace Science {

    //class MathGLData;
class IDataSet;
class IDataSet1D;
class IDataSet2D;

using namespace Resources;
using namespace std;

/**
 * Short description.
 *
 * @class MathGLPlot MathGLPlot.h ons/MathGL/Science/MathGLPlot.h
 */
class MathGLPlot {
private:
    int width;
    int height;
    //std::list<MathGLData*> datasets;
    //mglGraphZB* graph;
    UCharTexture2DPtr tex;
    vector<float> xv;
    vector<float> yv;
    IDataSet* dataset;

    void Draw1D(mglGraphZB* graph,IDataSet1D *data);
    void Draw2D(mglGraphZB* graph,IDataSet2D *data);

public:   
    MathGLPlot(int w, int h);

    void AddPoint(float t, float y);
    void Redraw();
    //void AddDataSet(MathGLData* dataset);

    ITexture2DPtr GetTexture();

    void SetData(IDataSet* data);
};

} // NS Science
} // NS OpenEngine

#endif // _OE_MATH_G_L_PLOT_H_
