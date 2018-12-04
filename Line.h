#pragma once

namespace PMK {
	ref class Point {
	public:
		float x;
		float y;

		Point() {};
		Point(float x, float y) {
			this->x = x;
			this->y = y;
		};
		float getX() {
			return x;
		}

		float getY() {
			return y;
		}

		void setX(float x) {
			this->x = x;
		}
		void setY(float y) {
			this->y = y;
		}

		~Point() {}
	};

	ref class Line {
	public:
		Point^ a;
		Point^ b;
	
		Line() {
			this->a = gcnew Point();
			this->b = gcnew Point();
		};
		Line(float x1, float y1, float x2, float y2) {
			this->a = gcnew Point(x1, y1);
			this->b = gcnew Point(x2, y2);
		}
		Line(Point^ a, Point^ b) {
			this->a = a;
			this->b = b;
		}

		Point^ getA() {
			return a;
		}
		Point^ getB() {
			return b;
		}

		float getX1() {
			return a->getX();
		}
		float getY1() {
			return a->getY();
		}
		float getX2() {
			return b->getX();
		}
		float getY2() {
			return b->getY();
		}

		void setA(Point^ a) {
			this->a = a;
		}
		void setB(Point^ b) {
			this->b = b;
		}

		void setX1(float x) {
			a->setX(x);
		}
		void setY1(float y) {
			a->setY(y);
		}
		void setX2(float x) {
			b->setX(x);
		}
		void setY2(float y) {
			b->setY(y);
		}

	};
};