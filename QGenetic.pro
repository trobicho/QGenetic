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

LIBS+=-framework GLUT
LIBS+=-L../genetic -lgenetic -L../neuralNet -lneuralNet
QT+=opengl
CONFIG+=qt
CONFIG+=no_lflags_merge
CONFIG+=debug
QMAKE_LFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11
CXXFLAGS+=-std=c++11
