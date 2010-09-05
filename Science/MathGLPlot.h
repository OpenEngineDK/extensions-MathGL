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

#include <Resources/Texture2D.h>

namespace OpenEngine {
namespace Science {

    using namespace Resources;

/**
 * Short description.
 *
 * @class MathGLPlot MathGLPlot.h ons/MathGL/Science/MathGLPlot.h
 */
class MathGLPlot {
private:
    UCharTexture2DPtr tex;
public:
    MathGLPlot(int w, int h);

    ITexture2DPtr GetTexture();
};

} // NS Science
} // NS OpenEngine

#endif // _OE_MATH_G_L_PLOT_H_
