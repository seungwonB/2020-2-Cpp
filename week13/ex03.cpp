[���α׷� �ҽ�]
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
	pStart = new Circle(); //ó���� �� ������ �����Ѵ�
	pLast = pStart;
	pLast = pLast->add(new Rect()); //�簢�� ��ü ����
	Graphic* p = pStart;

	while (1) {
		cout << "������ ������ �����ϼ���. " << endl;
		cout << "1:Rect, 2:Circle, 3:Line, 4:finish >> ";
		cin >> num;
		if (num == 1) {
			pLast = pLast->add(new Rect()); //�簢�� ��ü ����
		}
		else if (num == 2) {
			pLast = pLast->add(new Circle()); //�� ��ü ����
		}
		else if (num == 3) {
			pLast = pLast->add(new Line()); //�� ��ü ����
		}
		else if (num == 4) {
			cout << " -- ����� ��� ���� ��� -- " << endl;
			while (p != NULL) {
				p->paint(); //���
				p = p->getNext(); //���� �������� �̵�
			}

			p = pStart;
			while (p != NULL) {
				Graphic* q = p->getNext(); //���� ���� �ּ�
				delete p; //���� ���� ��ü �Ҹ�
				p = q; //���� ������ �ּҸ� p�� ����
			}
			cout << " -- ����� ��� ���� ���� -- " << endl;
			break;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���. " << endl;
			continue;
		}
	}
}


