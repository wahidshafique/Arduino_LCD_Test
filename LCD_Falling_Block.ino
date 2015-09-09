//Task Scheduler Library: http://playground.arduino.cc/Code/TaskScheduler
/*
	LCD 16 x 2
	ARDUINO-UNO
	220 ohm Resistor 
	Potentiometer
	Tactile-PTH
	1 kohm Resistor
*/

#include <TaskScheduler.h>
#include <LiquidCrystal.h>

//Task t1(100, -1, &Obstacles);
//Task t2(100, -1, &Player);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int switchState = 0;

void Obstacles() {

	byte ob[8] = {
		B1111,
		B1111,
		B1111,
		B1111,
		B1111,
		B1111,
		B1111,
		B1111
	};
	byte obo[8] = {
		B1000,
		
	};
	delay(250); 
	int randNum;
	for (int i = 17; i > 1; i--) {
		lcd.setCursor(i + 1, randNum);
		lcd.print(" ");
		randNum = random(2);
		lcd.createChar(0, obo); 
		lcd.setCursor(i, randNum);
		lcd.write((uint8_t)0); 
		delay(100);
	}
}

void Player() {
	
	lcd.setCursor(0, switchState);
	lcd.print(" ");
	for (char i = 0; i < 4; i++) {

		byte frame1[8] = {
			B00000, 
			B11000, 
			B10100, 
			B10010, 
			B10010, 
			B10100, 
			B11000, 
			B00000 };
		byte frame2[8] = {
			B00000, 
			B00000, 
			B11000, 
			B10110, 
			B10110, 
			B11000, 
			B00000, 
			B00000 };
		byte frame3[8] = {
			B00000, 
			B00000, 
			B00000, 
			B11110, 
			B11110, 
			B00000, 
			B00000, 
			B00000 };
		byte *arrows[4] = { frame1,frame2,frame3,frame2 }; 
		lcd.createChar(0, arrows[i]); 
		lcd.setCursor(0, switchState);
		lcd.write((uint8_t)0);
		delay(250); 
	}
}
void setup() {
	pinMode(6, INPUT);
	lcd.begin(16, 2);
}

void loop() {
	Obstacles();
	Player();
}
