#ifndef SINGLE_DC_MOTOR_HH
#define SINGLE_DC_MOTOR_HH

#include <DigitalPin.hh>
#include <tim.h>

class SingleDCMotor {
private:
	DigitalPin inOne;
	DigitalPin inTwo;
	TIM_HandleTypeDef PWM;

public:
	SingleDCMotor(_inOne, _inTwo, _PWM);
	~SingleDCMotor();
	void moveMotor(bool dir,);
};

#endif
