#include <iostream>
#include <string>
using namespace std;

namespace CON {
	enum { INC = 2, DEC = 2, VMAX = 100, CMAX = 999};
};

class TV {
	bool on;
	int channel;
	int volume;
public:
	void powerOn();
	void powerOff() {
		on = false;
	}
	void increaseChannel();
	void decreaseChannel();
	void increaseVolume();
	void decreaseVolume();
	void state();
};

void TV::powerOn() {
	on = true;
	channel = 1;
	volume = 1;
}

void TV::increaseChannel() {
	channel += CON::INC;
	if (channel > CON::CMAX)
		channel = CON::CMAX;
}

void TV::decreaseChannel() {
	channel -= CON::DEC;
	if (channel < 0)
		channel = 0;
}

void TV::increaseVolume() {
	volume += CON::INC;
	if (volume > CON::VMAX)
		volume = CON::VMAX;
}

void TV::decreaseVolume() {
	volume -= CON::DEC;
	if (volume < 0)
		volume = 0;
}

void TV::state() {
	cout << "power >> " << boolalpha << on << endl;
	cout << "volume >> " << volume << endl;
	cout << "channel >> " << channel << endl << endl;
}

int main() {
	TV tv;
	tv.powerOn();
	tv.state();
	tv.increaseChannel();
	cout << "채널 " << CON::DEC << " 증가" << endl;
	tv.state();

	return 0;
}

