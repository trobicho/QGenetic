SOURCES+=main.cpp
SOURCES+=MainWin.cpp
SOURCES+=QGenetic.cpp
SOURCES+=GeneticWorker.cpp
SOURCES+=QSnake.cpp
SOURCES+=../genetic/fitnessFunc/Snake_new.cpp
SOURCES+=../genetic/fitnessFunc/Snake_genRand.cpp
SOURCES+=WinGL.cpp

HEADERS+=MainWin.h
HEADERS+=QGenetic.h
HEADERS+=GeneticWorker.h
HEADERS+=QSnake.h
HEADERS+=../genetic/fitnessFunc/Snake_new.h
HEADERS+=../genetic/fitnessFunc/Snake_genRand.h
HEADERS+=WinGL.h
HEADERS+=QFitness.h

LIBS+= -lglut -lGLU
LIBS+=-L ~/lib -lgenetic -lneuralNet
QMAKE_CXXFLAGS+=-Wall -Wextra
QT+=opengl
CONFIG+=qt
CONFIG+=no_lflags_merge
CONFIG+=debug
