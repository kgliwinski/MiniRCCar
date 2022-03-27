#include "SevenSegmentX2.hh"

SevenSegmentX2::SevenSegmentX2(SevenSegment _singleSeg, Pin _leftGND,
		Pin _rightGND) :
		singleSeg(_singleSeg), leftGND(_leftGND), rightGND(_rightGND)
		{}

void SevenSegmentX2::clearDisp()
{
	this->singleSeg.clearDisp();
	leftGND.writePin(0);
	rightGND.writePin(0);
}

bool SevenSegmentX2::writeNumbers()
{
	return 1;
}
