#ifndef LEDS_H
#define LEDS_H

#include "DebugUtils.h"
#include "Arduino.h"
#include "Color.h"

class Leds {
private:
	const unsigned char _redPin = 9;
	const unsigned char _greenPin = 6;
	const unsigned char _bluePin = 10;
	const unsigned char _whitePin = 11;

	Color _color;

public:

	struct Colors {
		Color Black = Color("Black", 0, 0, 0, 0);
		Color White = Color("White", 255, 100, 100, 255);
		Color PureWhite = Color("Pure White", 0, 0, 0, 255);
		Color Red = Color("Red", 255, 0, 0, 0);
		Color Orange = Color("Orange", 255, 80, 0, 0);
		Color Yellow = Color("Yellow", 255, 155, 0, 0);
		Color Green = Color("Green", 0, 128, 0, 0);
		Color Blue = Color("Blue", 0, 0, 255, 0);
		Color Purple = Color("Purple", 75, 0, 130, 0);
		Color Violet = Color("Violet", 200, 130, 238, 0);
	}Colors;

	Leds();
	Leds(unsigned char r, unsigned char g, unsigned char b, unsigned char w);

	void Setup();
	void Show();
	void Stop();
	void Clear();

	Color GetColor();

	void SetColor(Color color);
};

#endif //LEDS_H
