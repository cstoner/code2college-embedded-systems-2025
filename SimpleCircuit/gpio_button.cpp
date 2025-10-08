#include <wiringPi.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int buttonPin = 29;

int main() {
	wiringPiSetup();
	pinMode(buttonPin, INPUT);
	
	while(true) {
		if (digitalRead(buttonPin) == 1) {
			cout << "The button is pressed" << endl;
		} else { 
			cout << "The button is not pressed" << endl;
		}
		usleep(5000); // pause for 5ms before moving on
	}
	
	return 0;
}
