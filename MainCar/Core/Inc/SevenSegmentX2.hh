#ifndef SEVEN_SEGMENT_X2_HH
#define SEVEN_SEGMENT_X2_HH

#include "SevenSegment.hh"

enum sides : uint32_t{rightSide=0, leftSide=1};

class SevenSegmentX2
{
private:
	SevenSegment singleSeg;
	DigitalPin leftGND;
	DigitalPin rightGND;

public:
	SevenSegmentX2(SevenSegment _singleSeg, DigitalPin _leftGND, DigitalPin _rightGND);
	/// show a two digit number on the display - only floats from 0.0 to 9.9
	bool writeNumber(uint8_t num, bool side);
	/// clear the whole screen
	void clearDisp();
	/// parses a float to a displayable state
	bool parseFloat(float number, uint32_t &left, uint32_t &right);
};

#endif
