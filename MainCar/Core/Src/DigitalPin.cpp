#include <DigitalPin.hh>

DigitalPin::DigitalPin(GPIO_TypeDef *_port, uint16_t _pinNum) :
		port(_port), pinNum(_pinNum) {
}
;

void DigitalPin::writePin(bool val) {
	if (val) {
	HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(port, pinNum, GPIO_PIN_RESET);
	}
}

