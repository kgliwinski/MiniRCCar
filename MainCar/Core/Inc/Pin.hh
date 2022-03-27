#ifndef PIN_HH
#define PIN_HH

#include "gpio.h"

class Pin {
	GPIO_TypeDef *port;
	uint16_t pin;

public:
	Pin(GPIO_TypeDef *_port, uint16_t _pin);
	void writePin(bool val);
};

#endif
