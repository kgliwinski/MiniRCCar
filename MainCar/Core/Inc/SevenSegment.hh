#ifndef SEVEN_SEGMENT_HH
#define SEVEN_SEGMENT_HH

#include "Pin.hh"

class SevenSegment
{
private:
	Pin ledA;
	Pin ledB;
	Pin ledC;
	Pin ledD;
	Pin ledE;
	Pin ledF;
	Pin ledG;
public:
	SevenSegment() = default;
	SevenSegment(Pin _ledA, Pin _ledB, Pin _ledC, Pin _ledD, Pin _ledE, Pin _ledF, Pin _ledG);

	/// turn off all leds on the display
	void clearDisp();
	/// write a single digit on the display
	bool writeDigit(uint8_t dig);
};

#endif
