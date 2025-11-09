Point2D.o: Point2D.cpp Point2D.h
	g++ -c Point2D.cpp -o Point2D.o

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ testPoint2D.cpp Point2D.o -o bin/testPoint2D

Shape.o: Shape.cpp Shape.h Point2D.h
	g++ -c Shape.cpp -o Shape.o

Circle.o: Circle.cpp Circle.h Shape.h Point2D.h
	g++ -c Circle.cpp -o Circle.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ testCircle.cpp Circle.o Shape.o Point2D.o -o bin/testCircle

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Rectangle.cpp -o Rectangle.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ testRectangle.cpp Rectangle.o Shape.o Point2D.o -o bin/testRectangle

Square.o: Square.cpp Square.h Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp -o Square.o

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o -o bin/testSquare

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
		mkdir -p bin
		g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o