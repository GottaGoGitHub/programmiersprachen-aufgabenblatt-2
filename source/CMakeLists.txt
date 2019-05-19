# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  )

target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})


  
add_executable(aufgabe23 aufgabe_2_und_3.cpp)

#add_executable(aufgabe41 aufgabe_4_1.cpp)

add_executable(aufgabe6 aufgabe_6.cpp)

add_executable(aufgabe9 aufgabe_9.cpp)