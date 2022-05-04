#ifndef DigitalPin_HH
#define DigitalPin_HH

#include "gpio.h"

class DigitalPin {
	GPIO_TypeDef *port;
	uint16_t pinNum;

public:
	DigitalPin() = default;
	DigitalPin(GPIO_TypeDef *_port, uint16_t _pinNum);
	void writePin(bool val);
};

#endif
