# OpenGL Chess
A full-fledged single player Chess game.

The [GLUT library](http://www.opengl.org/resources/libraries/glut/) is a prerequisite for this game. Once GLUT has been installed, use the instructions given below to compile and execute OpenGL Chess.
  - On an OS X system: `g++ main.cpp -framework GLUT -framework OpenGL -o chess.out; ./chess.out`
  - On a Linux system: `g++ main.cpp -lglut -lGLU -lGL -lm -o chess.out; ./chess.out`
