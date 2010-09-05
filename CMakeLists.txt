
# Create the extension library
ADD_LIBRARY(Extensions_MathGL
  Science/MathGLPlot.h
  Science/MathGLPlot.cpp  
)

TARGET_LINK_LIBRARIES(Extensions_MathGL
  ${MATHGL_LIB}
  "gsl"
  "png"
)