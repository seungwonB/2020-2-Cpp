#include <iostream>
#include <string>
using namespace std;

class Point;
void showPoint(const Point& p, const string name); //const 사용 - 값을 사용만하고 값은 바뀌지 않게, 상수 

class PointCom {
	int cnt;
public:
	PointCom() :cnt(0) {}
	Point pointAdd(const Point& p1, const Point& p2); //point가 가지고 있는 무언갈 사용해야됨
	Point pointMul(const Point& p1, const Point& p2);
	~PointCom() {
		cout << "cnt = " << cnt << endl;
	}
};
class Point {
	int x, y;
public:
	Point(const int& xp, const int& yp) :x(xp), y(yp) {}
	friend Point PointCom::pointAdd(const Point& p1, const Point& p2);
	friend Point PointCom::pointMul(const Point& p1, const Point& p2);
	friend void showPoint(const Point& p, const string name);
};

Point PointCom::pointAdd(const Point& p1, const Point& p2) {
	++cnt;
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point PointCom::pointMul(const Point& p1, const Point& p2) {
	++cnt;
	return Point(p1.x * p2.x, p1.y * p2.y);
}

void showPoint(const Point& p, const string pname) {
	cout << "Point : " << pname << endl;
	cout << "x : " << p.x << ", y : " << p.y << endl << endl;
}

int main() {
	Point p1(3, 4);
	Point p2(5, 6);
	PointCom pc;
	showPoint(p1, "p1");
	showPoint(p2, "p2");
	showPoint(pc.pointAdd(p1, p2), "pAdd");
	showPoint(pc.pointMul(p1, p2), "pMul");
}

