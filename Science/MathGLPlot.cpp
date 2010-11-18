#include "MathGLPlot.h"

#include <Science/IDataSet.h>
#include <Logging/Logger.h>
#include <vector>

namespace OpenEngine {
namespace Science {


    
MathGLPlot::MathGLPlot(int w, int h) : width(w), height(h) {
    //graph = new mglGraphZB(w,h);
    UCharTexture2D *te = new UCharTexture2D(w,h,3);
    tex = UCharTexture2DPtr(te);
    
    //xv.push_back(0);
    //yv.push_back(42);

}

// void MathGLPlot::AddDataSet(MathGLPlot *dataset) {
//     datasets.push_back(dataset);
// }

void MathGLPlot::AddPoint(float t, float y) {
    xv.push_back(t);
    yv.push_back(y);
}


void MathGLPlot::Redraw() {
    mglGraphZB* graph = new mglGraphZB(width,height);
    mglData x;
    mglData y;

    if (xv.size() < 1)
        return;
    
    // for (int i=0;i<100;i++) {
    //     float y = sin(float(i/10.0));
    //     data.push_back(y);
    //     //data2.push_back(i);
    // }
    
    y.Set(yv);
    x.Set(xv);

    //y.Modify("sin(x*pi)");
    //logger.info << "arg" << logger.end;

    graph->XRange(x);
    //graph->Min.x = 0;
    //graph->Max.x = 100;
    //graph->RecalcBorder();
    graph->YRange(y);
    graph->Axis("xy");
    graph->Box();
    graph->Plot(x,y);
    
    memcpy(tex->GetData(), graph->GetBits(), width*height*3);

    tex->ReverseVertecally();
    Texture2DChangedEventArg arg(tex);
    tex->ChangedEvent().Notify(arg);
    delete graph;
}

ITexture2DPtr MathGLPlot::GetTexture() {
    return tex;
}

}
}
