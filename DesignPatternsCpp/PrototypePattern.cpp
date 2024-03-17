#include <iostream>
class Shape {
	virtual Shape* clone() const = 0; //Clone method for creating copies.
	virtual void draw() const = 0; //Draw method for rendering shape.
	virtual ~Shape() {} //Virtual destructor for proper cleanup.
};

//Circle prototype
class Circle : public Shape {
	private: 
		double radius;

	public: 
		Circle(double r) : radius(r) {}

		Shape* clone() const override {
			return new Circle(*this);
		}

		void draw() const override {
			std::cout << "Drawing a circle with radius" << radius << std::endl;
		}
};

//Rectangle prototype
class Rectangle : public Shape {
	private:
		double width;
		double height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		Shape* clone() const override {
			return new Rectangle(*this);
		}

		void draw() const override {
			std::cout << "Drawing a rectangle with width " << width << " and height " << height << std::endl;
		}
};

int main() {
	Circle circlePrototype(5.0);
	Rectangle rectanglePrototype(4.0, 6.0);

	Shape* shape1 = circlePrototype.clone();
	Shape* shape2 = rectanglePrototype.clone();

	shape1->draw(); // Output: Drawing a circle with radius 5
	shape2->draw(); // Output: Drawing a rectangle with width 4 and height 6

	delete shape1;
	delete shape2;
	return 0;
}
