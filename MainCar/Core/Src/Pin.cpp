#include "Pin.hh"

Pin::Pin(GPIO_TypeDef *_port, uint16_t _pin) :
		port(_port), pin(_pin) {
}
;

void Pin::writePin(bool val) {
	if (val) {
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
	}
}

