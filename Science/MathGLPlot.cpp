#include "MathGLPlot.h"

#include <Science/IDataSet.h>
#include <Science/IDataSet1D.h>
#include <Science/IDataSet2D.h>
#include <Logging/Logger.h>
#include <vector>

namespace OpenEngine {
namespace Science {


    
MathGLPlot::MathGLPlot(int w, int h) : width(w), height(h), dataset(NULL) {
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


void MathGLPlot::Draw1D(mglGraphZB* graph,IDataSet1D* data) {
    mglData y;

    if (data) {
        yv = data->GetYData();
    }

    if (yv.size() < 1)
        return;
    
    
    y.Set(yv);

    //graph->XRange(x);
    //graph->Label('x', data->GetXName().c_str());
    graph->Label('y', data->GetYName().c_str());

    pair<float,float> xrange = data->GetXRange();

    graph->Min.x = xrange.first;
    graph->Max.x = xrange.second;
    graph->RecalcBorder();

    graph->YRange(y);
    graph->Axis("xy");
    graph->Box();
    graph->Plot(y);
}

void MathGLPlot::Draw2D(mglGraphZB* graph,IDataSet2D* data) {
    mglData x;
    mglData y;

    if (data) {
        xv = data->GetXData();
        yv = data->GetYData();
    }

    if (xv.size() < 1)
        return;
    
    
    y.Set(yv);
    x.Set(xv);

    graph->XRange(x);
    graph->Label('x', data->GetXName().c_str());
    graph->Label('y', data->GetYName().c_str());

    graph->YRange(y);
    graph->Axis("xy");
    graph->Box();
    graph->Plot(x,y);
}

void MathGLPlot::Redraw() {
    mglGraphZB* graph = new mglGraphZB(width,height);
    graph->SetFontSize(8.0);

    if (IDataSet1D *data = dynamic_cast<IDataSet1D*>(dataset)) {
        Draw1D(graph,data);
    }
    else if (IDataSet2D *data = dynamic_cast<IDataSet2D*>(dataset)) {
        Draw2D(graph,data);
    }

    
    memcpy(tex->GetData(), graph->GetBits(), width*height*3);

    tex->ReverseVertecally();
    Texture2DChangedEventArg arg(tex);
    tex->ChangedEvent().Notify(arg);
    delete graph;
}

void MathGLPlot::SetData(IDataSet* data) {
    dataset = data;
}


ITexture2DPtr MathGLPlot::GetTexture() {
    return tex;
}

}
}
