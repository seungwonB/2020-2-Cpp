#include <iostream>
#include <string>	
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	~Circle() {
		cout << "반지름 " << radius << " 객체 소멸~~" << endl;
	}
	void setRadius(int r) {
		radius = r;
	}
	double getArea();
	int getRadius() const{
		return radius;
	}
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

class CircleManage {
	Circle* p;
	int size;
public:
	CircleManage(); //size크기의 배열을 동적 생성. 사용자로부터 입력 완료
	~CircleManage();  // 동적으로 할당받은 메모리 반납
	void CircleWrite(); //객체 배열과 면적이 100~200사이의 Circle 객체검색하여 출력
};

CircleManage::CircleManage() {
	cout << "생성하고자 하는 원의 개수 >> ";
	cin >> size;
	p = new Circle[size]; //입력받은 만큼 저장하는 포인터 배열

	int radius;
	for (int i = 0; i < size; i++) {
		cout << "원" << i + 1 << ": ";
		cin >> radius;
		p[i].setRadius(radius); //포인터 배열에 저장
	}
}

void CircleManage::CircleWrite() {
	int count = 0;
	Circle *pArray = p;
	for (int i = 0; i < size; i++) {
		cout << "반지름 = " << pArray->getRadius() << "\t넓이 = " << pArray->getArea() << endl;
		if (pArray->getArea() >= 100 && pArray->getArea() <= 200)
			count++;
		pArray++;
	}
	cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl << endl;
}

CircleManage::~CircleManage() {
	delete[] p;
}

int main() {
	CircleManage cm;
	cm.CircleWrite();
	return 0;
}

