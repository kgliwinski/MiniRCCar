#include "SingleDCMotor.hh"

SingleDCMotor::SingleDCMotor(DigitalPin _inOne, DigitalPin _inTwo,
		TIM_HandleTypeDef *_PWMHandleTypeDef, TIM_TypeDef _PWMTimTypeDef,
		uint32_t _PWMChannel, volatile uint32_t *_PWMHandleTypeDefChannel) :
		inOne(_inOne), inTwo(_inTwo), PWMHandleTypeDef(_PWMHandleTypeDef), PWMTimTypeDef(
				_PWMTimTypeDef), PWMChannel(_PWMChannel), PWMHandleTypeDefChannel(
				_PWMHandleTypeDefChannel) {
	state = STOP;
}

SingleDCMotor::~SingleDCMotor() {
}

bool SingleDCMotor::init() {
	this->inOne.writePin(0);
	this->inTwo.writePin(0);
	if (HAL_TIM_PWM_Start(PWMHandleTypeDef, PWMChannel) != HAL_OK)
		return 0;
	return 1;
}

void SingleDCMotor::setDirection(bool dir) {
	if (dir == 1) {
		inOne.writePin(1);
		inTwo.writePin(0);
	} else {
		inOne.writePin(0);
		inTwo.writePin(1);
	}
}

bool SingleDCMotor::setPWMWidth(uint8_t perc) {
	if (perc > 100)
		return 0;
	uint32_t width = perc * 655.35;
	*(PWMHandleTypeDefChannel) = width;
	return 1;
}
