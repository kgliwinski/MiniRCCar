#ifndef SEVEN_SEGMENT_X2_HH
#define SEVEN_SEGMENT_X2_HH

#include "SevenSegment.hh"

class SevenSegmentX2
{
private:
	SevenSegment singleSeg;
	Pin leftGND;
	Pin rightGND;
public:
	SevenSegmentX2(SevenSegment _singleSeg, Pin _leftGND, Pin _rightGND);
	/// show a two digit number on the display
	bool writeNumbers(uint8_t leftDig, uint8_t rightDig);
	/// clear the whole screen
	void clearDisp();
};

#endif
