#ifndef SINGLE_DC_MOTOR_HH
#define SINGLE_DC_MOTOR_HH
/*!
 * Made for the toshiba tb6612fng DC driver
 * Works corresponding to the available datasheet at https://www.sparkfun.com/datasheets/Robotics/TB6612FNG.pdf
 */

#include <DigitalPin.hh>
#include <tim.h>
#include <gpio.h>

/// Standby not included
enum MotorState {
	STOP = 0, IDLE, CLOCKWISE, COUNTERCLOCKWISE, SHORT_BRAKE
};

enum direction {forward = 0, backward};

class SingleDCMotor {
private:
	DigitalPin inOne;
	DigitalPin inTwo;
	TIM_HandleTypeDef *PWMHandleTypeDef;
	TIM_TypeDef PWMTimTypeDef;
	uint32_t PWMChannel;
	volatile uint32_t *PWMHandleTypeDefChannel;
	MotorState state;

public:
	SingleDCMotor(DigitalPin _inOne, DigitalPin _inTwo,
			TIM_HandleTypeDef *_PWMHandleTypeDef, TIM_TypeDef _PWMTimTypeDef,
			uint32_t _PWMChannel, volatile uint32_t *_PWMHandleTypeDefChannel);
	~SingleDCMotor();
	/*! init of class:sets both inOne and inTwo pins low and starts pwm
	 returns 0 if pwm doesnt start */
	bool init();
	/// set the direction of spinning wheel: dir=0 -> clockwise, dir=1->counterclockwise
	void setDirection(const bool dir);
	/// set the PWM pulse width (0-65535) but in the percents range (0-100%)
	bool setPWMWidth(const uint8_t perc);
	/// stop or let work of the motor
	void setstdBy(const bool goNoGo);

	static DigitalPin stdBy;
};

#endif
