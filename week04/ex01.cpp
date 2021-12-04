#include <iostream>	
#include <string>
using namespace std;

class Color {
	int red, green, blue; //�� ����
	string color; //����
public:
	Color() { red = green = blue = 0; color = "black"; } //����Ʈ ������
	Color(int r, int g, int b, string c) : red(r), green(g), blue(b), color(c) {} //�Ű������� �����ϴ� ������ 
	~Color(); //�Ҹ���

	void setColor(int r, int g, int b, string c); 
	void show();
};

void Color::setColor(int r, int g, int b, string c) {
	red = r;
	green = g;
	blue = b;
	color = c;
}

void Color::show() {
	cout << "color = " << color << "\tRGB value >> R) " << red << " G) " << green << " B) " << blue << endl;
}

Color::~Color() {
	cout << color << "��ü �Ҹ�" << endl;
}

void pointer_array() {
	Color screenColor(255, 255, 255, "white");
	Color *p;
	p = &screenColor;
	p->show();

	Color colors[3];
	p = colors;

	p[0].setColor(255, 0, 0, "red");
	p[1].setColor(0, 255, 0, "green");
	p[2].setColor(0, 0, 255, "blue");

	for (int i = 0; i < 3; i++) {
		p->show();
		p++;
	}
}
int main() {
	pointer_array();
	cout << "program stop" << endl;

	return 0;
}

