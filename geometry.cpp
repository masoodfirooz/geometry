#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;

const double epsilon = 1e-9;

bool isEqual(double x, double y) {
	return ((x - y) <= epsilon) && ((y - x) <= epsilon);
}

class POINT {
private:
	double x, y;
public:
	POINT() {
		x = y = 0;
	}
	POINT(double x, double y) {
		this->x = x;
		this->y = y;
	}
	POINT(const POINT &c) {
		x = c.x;
		y = c.y;
	}
	POINT& operator=(POINT &c) {
		x = c.x;
		y = c.y;
		return *this;
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
	LINE(const LINE &c) {
		slope = c.slope;
		y_intercept = c.y_intercept;
	}
	LINE& operator=(const LINE& c) {
		slope = c.slope;
		y_intercept = c.y_intercept;
		return *this;
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

class LINE_SEGMENT {
private:
	POINT s, d;
public:
	LINE_SEGMENT(POINT s, POINT d) {
		this->s = s;
		this->d = d;
	}
	double getLength() {
		return sqrt(pow(s.getX() - d.getX(), 2) + pow(s.getY() - d.getY(), 2));
	}
	double getXAngle() {
		if (isEqual(s.getY(), d.getY())) {
			return acos((d.getX() - s.getX()) / getLength()) ;
		}
		return asin((d.getY() - s.getY()) / getLength());
	}
	double getYAngle() {
		if (isEqual(s.getX(), d.getX())) {
			return acos((d.getY() - s.getY()) / getLength());
		}
		return asin((d.getX() - s.getX()) / getLength()) ;
	}
};

int main() {
	POINT p1 = *(new POINT(5, 7));
	POINT p2 = POINT(5, 17);
	LINE l = LINE(p1, p2);
	cout << l.isParallel(l) << endl;
	LINE_SEGMENT ls = LINE_SEGMENT(p1, p2);
	cout << ls.getYAngle() << endl;
	return 0;
}
