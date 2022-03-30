#ifndef SEVEN_SEGMENT_HH
#define SEVEN_SEGMENT_HH

#include <DigitalPin.hh>

class SevenSegment
{
private:
	DigitalPin ledA;
	DigitalPin ledB;
	DigitalPin ledC;
	DigitalPin ledD;
	DigitalPin ledE;
	DigitalPin ledF;
	DigitalPin ledG;
public:
	SevenSegment() = default;
	SevenSegment(DigitalPin _ledA, DigitalPin _ledB, DigitalPin _ledC, DigitalPin _ledD, DigitalPin _ledE, DigitalPin _ledF, DigitalPin _ledG);

	/// turn off all leds on the display
	void clearDisp();
	/// write a single digit on the display
	bool writeDigit(uint8_t dig);
};

#endif
