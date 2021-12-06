[프로그램 소스]
#include <iostream>
using namespace std;

class Graphic {
	Graphic* next;
protected:
	virtual void draw();
public:
	Graphic() {
		next = NULL;
	}
	virtual ~ Graphic(){  }
	void paint();
	Graphic* add(Graphic* p);
	Graphic* getNext() {
		return next;
	}
};

void Graphic::draw() {
	cout << "draw()" << endl;
}

void Graphic::paint() {
	draw();
}

Graphic* Graphic::add(Graphic* p) {
	this->next = p;
	return p;
}

class Circle :public Graphic {
protected:
	virtual void draw();
};

void Circle::draw() {
	cout << "Circle::draw()" << endl;
}

class Line :public Graphic {
protected:
	virtual void draw();
};

void Line::draw() {
	cout << "Line::draw()" << endl;
}

class Rect : public Graphic {
protected:
	virtual void draw();
};

void Rect::draw() {
	cout << "Rectangle::draw()" << endl;
}

int main(){
	int num;
	Graphic* pStart = NULL;
	Graphic* pLast;
	pStart = new Circle(); //처음에 원 도형을 생성한다
	pLast = pStart;
	pLast = pLast->add(new Rect()); //사각형 객체 생성
	Graphic* p = pStart;

	while (1) {
		cout << "생성할 도형을 선택하세요. " << endl;
		cout << "1:Rect, 2:Circle, 3:Line, 4:finish >> ";
		cin >> num;
		if (num == 1) {
			pLast = pLast->add(new Rect()); //사각형 객체 생성
		}
		else if (num == 2) {
			pLast = pLast->add(new Circle()); //원 객체 생성
		}
		else if (num == 3) {
			pLast = pLast->add(new Line()); //선 객체 생성
		}
		else if (num == 4) {
			cout << " -- 연결된 모든 도형 출력 -- " << endl;
			while (p != NULL) {
				p->paint(); //출력
				p = p->getNext(); //다음 도형으로 이동
			}

			p = pStart;
			while (p != NULL) {
				Graphic* q = p->getNext(); //다음 도형 주소
				delete p; //현재 도형 객체 소멸
				p = q; //다음 도형의 주소를 p에 저장
			}
			cout << " -- 연결된 모든 도형 삭제 -- " << endl;
			break;
		}
		else {
			cout << "잘못 입력하셨습니다. 다시 입력하세요. " << endl;
			continue;
		}
	}
}


