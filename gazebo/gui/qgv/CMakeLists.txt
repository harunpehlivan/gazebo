include (${gazebo_cmake_dir}/GazeboUtils.cmake)

set(sources ${sources}
  qgv/private/QGVCore.cpp
  qgv/private/QGVGraphPrivate.cpp
  qgv/private/QGVEdgePrivate.cpp
  qgv/private/QGVGvcPrivate.cpp
  qgv/private/QGVNodePrivate.cpp
  qgv/QGVEdge.cpp
  qgv/QGVNode.cpp
  qgv/QGVScene.cpp
  qgv/QGVSubGraph.cpp
  PARENT_SCOPE
)

SET(internal_qt_headers ${internal_qt_headers}
  qgv/QGVScene.h
  PARENT_SCOPE
)
