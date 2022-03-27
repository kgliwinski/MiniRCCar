#include "SevenSegment.hh"

SevenSegment::SevenSegment(Pin _ledA, Pin _ledB, Pin _ledC, Pin _ledD,
		Pin _ledE, Pin _ledF, Pin _ledG) :
		ledA(_ledA), ledB(_ledB), ledC(_ledC), ledD(_ledD), ledE(_ledE), ledF(
				_ledF), ledG(_ledG) {
}

void SevenSegment::clearDisp() {
	ledA.writePin(0);
	ledB.writePin(0);
	ledC.writePin(0);
	ledD.writePin(0);
	ledE.writePin(0);
	ledF.writePin(0);
	ledG.writePin(0);
}

bool SevenSegment::writeDigit(uint8_t val) {
	if (val > 9) {
		return 0;
	}

	if (val == 0) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledE.writePin(1);
		ledF.writePin(1);
	} else if (val == 1) {
		ledB.writePin(1);
		ledC.writePin(1);
	} else if (val == 2) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledD.writePin(1);
		ledE.writePin(1);
		ledG.writePin(1);
	} else if (val == 3) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledG.writePin(1);
	} else if (val == 4) {
		ledB.writePin(1);
		ledC.writePin(1);
		ledF.writePin(1);
		ledG.writePin(1);
	} else if (val == 5) {
		ledA.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledF.writePin(1);
		ledG.writePin(1);
	} else if (val == 6) {
		ledA.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledE.writePin(1);
		ledF.writePin(1);
		ledG.writePin(1);
	} else if (val == 7) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledC.writePin(1);
	} else if (val == 8) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledE.writePin(1);
		ledF.writePin(1);
		ledG.writePin(1);
	} else if (val == 9) {
		ledA.writePin(1);
		ledB.writePin(1);
		ledC.writePin(1);
		ledD.writePin(1);
		ledF.writePin(1);
		ledG.writePin(1);
	}
	return 1;
}
