# find MathGL

FIND_PATH(MATHGL_INCLUDE_DIR NAMES mgl/mgl.h
  PATHS
  ${OE_LIB_DIR}/mathgl/include
  /opt/local/include
  /usr/local/include
  /usr/include
  /usr/local/include
)

FIND_LIBRARY(MATHGL_LIB
  NAMES
  mgl
  PATHS
  ${OE_LIB_DIR}/mathgl/lib
  /opt/local/lib
  /usr/local/lib
  /usr/lib
)


IF (MATHGL_INCLUDE_DIR AND MATHGL_LIB)
  SET(MATHGL_FOUND TRUE)
ENDIF(MATHGL_INCLUDE_DIR AND MATHGL_LIB)
