#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;

const double epsilon = 1e-9;

bool isEqual(double x, double y) {
	return ((x - y) <= epsilon) && ((x - y) >= epsilon * (-1));
}

class POINT {
private:
	double x, y;
public:
	POINT(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
	void set(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
};

class LINE {
private:
	double slope, y_intercept;
public:
	LINE(double slope, double y_intercept) {
		this->slope = slope;
		this->y_intercept = y_intercept;
	}
	LINE(POINT a, POINT b) {
		if (isEqual(a.getX(), b.getX())) {
			slope = DBL_MAX;
			y_intercept = 0;
		} else {
			slope = (a.getY() - b.getY()) / (a.getX() - b.getX());
			y_intercept = a.getY() - a.getX() * slope;
		}
	}
	void setY_intercept(double y_intercept) {
		this->y_intercept = y_intercept;
	}
	void setSlope(double slope) {
		this->slope = slope;
	}
	double getY_intercept() {
		return y_intercept;
	}
	double getSlope() {
		return slope;
	}
	bool isParallel(LINE l) {
		return (isEqual(slope, l.getSlope()));
	}
	POINT interject(LINE l) {
		if (this->isParallel(l)) {
			POINT *p = new POINT(DBL_MAX, DBL_MAX);
			return *p;
		} else {
			POINT *p = new POINT((y_intercept - l.getY_intercept()) / (l.getSlope() - slope), (l.getSlope() * y_intercept - slope * l.getY_intercept()) / (l.getSlope() - slope));
			return *p;
		}
	}
};

int main() {
	POINT p1 = *(new POINT(2.5, 5));
	POINT p2 = *(new POINT(2.5, 5));
	LINE l = *(new LINE(p1, p2));
	cout << l.isParallel(l) << endl;
	return 0;
}
