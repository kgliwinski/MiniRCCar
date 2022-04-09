#include "VoltageMeter.hh"

VoltageMeter::VoltageMeter(ADC_HandleTypeDef *_adc, float _topRes,
		float _bottomRes, float _stmPowerSupply) :
		adc(_adc), topRes(_topRes), bottomRes(_bottomRes), stmPowerSupply(
				_stmPowerSupply) {
	this->divRatio = bottomRes / (topRes + bottomRes);
}

bool VoltageMeter::init() {
	if (HAL_ADC_Start(adc) != HAL_OK)
		return 0;
	return 1;
}

float VoltageMeter::getResRatio() const {
	return this->divRatio;
}

float VoltageMeter::calculateVoltageVolts() const {
	uint16_t measuredVal;
	if (HAL_ADC_PollForConversion(adc, 10) == HAL_OK) {
		measuredVal = HAL_ADC_GetValue(adc);
		HAL_ADC_Start(adc);
	}
	// hard coded 3.68
	float res = float(measuredVal) * this->stmPowerSupply
			/ (4095.0f * (this->divRatio));
	return res;
}
