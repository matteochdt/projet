CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall

all: testVecteur

testVecteur: testVecteur.o Vecteur.o