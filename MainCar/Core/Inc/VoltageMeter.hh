#ifndef VOLTAGE_METER_HH
#define VOLTAGE_METER_HH

#include "DigitalPin.hh"
#include "adc.h"


class VoltageMeter
{
private:
	ADC_HandleTypeDef *adc;
	const float topRes;
	const float bottomRes;
	const float stmPowerSupply;
	float divRatio;

public:
	VoltageMeter(ADC_HandleTypeDef *_adc, float _topRes, float _bottomRes, float _stmPowerSupply);
	/// init ADC measure
	bool init();
	/// get the voltage divider ratio
	float getResRatio() const;
	float calculateVoltageVolts() const;
};

#endif
