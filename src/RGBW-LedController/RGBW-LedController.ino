#include "Leds.h"

Leds leds;

void setup() {
	DEBUG_BEGIN(9600);

	leds.Setup();
	leds.SetColor(leds.Colors.Black);
	leds.Show();
}

void loop() {
	leds.SetColor(leds.Colors.Red);
	leds.Show();
	
	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Orange);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Yellow);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Green);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Blue);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Purple);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.Violet);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.White);
	leds.Show();

	delay(2000);

	leds.Clear();
	leds.SetColor(leds.Colors.PureWhite);
	leds.Show();

	delay(2000);
}
