#include "SevenSegmentX2.hh"

SevenSegmentX2::SevenSegmentX2(SevenSegment _singleSeg, DigitalPin _leftGND,
		DigitalPin _rightGND) :
		singleSeg(_singleSeg), leftGND(_leftGND), rightGND(_rightGND) {
}

void SevenSegmentX2::clearDisp() {
	this->singleSeg.clearDisp();
	leftGND.writePin(0);
	rightGND.writePin(0);
}

bool SevenSegmentX2::writeNumber(uint8_t num, bool side) {
	if (num > 9)
		return 0;
	DigitalPin curGND;
	DigitalPin othGND;
	if (side == 1) {
		curGND = leftGND;
		othGND = rightGND;
	} else {
		curGND = rightGND;
		othGND = leftGND;
	}
	singleSeg.clearDisp();
	singleSeg.setDP(!side);
	curGND.writePin(0);
	othGND.writePin(1);
	if (!singleSeg.writeDigit(num)) {
		singleSeg.writeDigit(0);
		return 0;
	}
	return 1;
}

bool SevenSegmentX2::parseFloat(float number, uint32_t &left, uint32_t &right) {
	if(number >= 10.0)
		return 0;
	left = uint32_t(number * 10) / 10;
	right = uint32_t(number * 10) % 10;
	return 1;
}
