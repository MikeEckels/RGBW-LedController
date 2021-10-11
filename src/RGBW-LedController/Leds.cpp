#include "Leds.h"

Leds::Leds() {}

Leds::Leds(unsigned char r, unsigned char g, unsigned char b, unsigned char w) : _redPin(r), _greenPin(g), _bluePin(b), _whitePin(w) {}

void Leds::Setup() {
	pinMode(this->_redPin, OUTPUT);
	pinMode(this->_greenPin, OUTPUT);
	pinMode(this->_bluePin, OUTPUT);
	pinMode(this->_whitePin, OUTPUT);
	DEBUG_PRINT_NOTICE("Configuring pins");
}

void Leds::Show() {
	analogWrite(this->_redPin, this->_color.Red);
	analogWrite(this->_greenPin, this->_color.Green);
	analogWrite(this->_bluePin, this->_color.Blue);
	analogWrite(this->_whitePin, this->_color.White);
	DEBUG_PRINT_INFO("Output set ON");
}

void Leds::Stop() {
	analogWrite(this->_redPin, 0);
	analogWrite(this->_greenPin, 0);
	analogWrite(this->_bluePin, 0);
	analogWrite(this->_whitePin, 0);
	DEBUG_PRINT_INFO("Output set OFF");
}

void Leds::Clear() {
	Leds::Stop();
	Leds::SetColor(this->Colors.Black);
	DEBUG_PRINT_ERR("Color data cleared");
}

Color Leds::GetColor() {
	return this->_color;
	DEBUG_PRINT_INFO("Current color is: " + _color.GetName());
}

void Leds::SetColor(Color color) {
	this->_color = color;
	DEBUG_PRINT_INFO("Color changed to: " + _color.GetName());
}
