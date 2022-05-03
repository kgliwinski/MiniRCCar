#ifndef SINGLE_DC_MOTOR_HH
#define SINGLE_DC_MOTOR_HH
/*!
 * Made for the toshiba tb6612fng DC driver
 * Works corresponding to the available datasheet at https://www.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf
 */

#include <DigitalPin.hh>
#include <tim.h>

/// Standby not included

class SingleDCMotor {
private:
	DigitalPin inOne;
	DigitalPin inTwo;
	TIM_HandleTypeDef *PWMHandleTypeDef;
	TIM_TypeDef PWMTimTypeDef;
	uint32_t PWMChannel;
	volatile uint32_t *PWMHandleTypeDefChannel;


public:
	SingleDCMotor(DigitalPin _inOne, DigitalPin _inTwo,
			TIM_HandleTypeDef *_PWMHandleTypeDef, TIM_TypeDef _PWMTimTypeDef,
			uint32_t _PWMChannel, volatile uint32_t *_PWMHandleTypeDefChannel);
	~SingleDCMotor();
	/*! init of class:sets both inOne and inTwo pins low and starts pwm
	 returns 0 if pwm doesnt start */
	bool init();
	/// set the direction of spinning wheel: dir=0 -> clockwise, dir=1 -> counterclockwise
	void setDirection(const bool dir);
	/// set the PWM pulse width (0-65535) but in the percents range (0-100%)
	bool setPWMWidth(const uint8_t perc);

};

#endif
