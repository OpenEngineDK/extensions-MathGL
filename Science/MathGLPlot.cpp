#include "MathGLPlot.h"

namespace OpenEngine {
namespace Science {
    
MathGLPlot::MathGLPlot(int w, int h) {
    mglGraphZB graph(w,h);
    mglData y(100);
    y.Modify("sin(x*pi)");
    graph.Axis("xy");
    graph.Box();
    graph.Plot(y);
    UCharTexture2D *te = new UCharTexture2D(w,h,3);
    memcpy(te->GetData(), graph.GetBits(), w*h*3);
    tex = UCharTexture2DPtr(te);
    tex->ReverseVertecally();
}

ITexture2DPtr MathGLPlot::GetTexture() {
    return tex;
}

}
}
