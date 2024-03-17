//Abstract product class
#include <stdlib.h>
#include <iostream>

class Shape {
	public:
		virtual void draw() = 0;
		virtual ~Shape() {} // Virtual destructor for polymorphism,
};

//Concrete product class - CIRCLE

class Circle : public Shape {
public:
	void draw() override {
		std::cout << "Drawing a Circle"
			<< std::endl;
	}
};

//Concrete product class - SQUARE

class Square : public Shape {
public:
	void draw() override {
		std::cout << "Drawing a Square" 
			<< std::endl;
	}
};

//Abstract creator class
class ShapeFactory {
	public:
		virtual Shape* createShape() = 0;
		virtual ~ShapeFactory() {} //Virtual destructor for polymorphism
};

//Concrete creator class - CIRCLEFACTORY
class CircleFactory : public ShapeFactory {
	public:
		Shape* createShape() override {
			return new Circle();
		}
};

class SquareFactory : public ShapeFactory {
	public:
		Shape* createShape() override {
			return new Square();
		}
};

int main() {
	ShapeFactory* circleFactory = new CircleFactory();
	ShapeFactory* squareFactory = new SquareFactory();

	Shape* circle = circleFactory -> createShape(); 
	Shape* square = squareFactory -> createShape(); 

	circle -> draw(); //Output: Draawing a circle
	square -> draw(); //Output: Draawing a square

	delete circleFactory;
	delete squareFactory;
	delete circle;
	delete square;

	return 0;


}