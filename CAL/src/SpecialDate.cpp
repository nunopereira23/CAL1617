/*
 * SpecialDate.cpp
 *
 *  Created on: 10/04/2017
 *      Author: Fr0sk
 */

#include "SpecialDate.h"

SpecialDate::SpecialDate(Date initialDate, Date finalDate, double factor)
	: initialDate(initialDate), finalDate(finalDate), factor(factor) { }

Date SpecialDate::getInitialDate() const {
	return this->initialDate;
}

Date SpecialDate::getFinalDate() const {
	return this->finalDate;
}

double SpecialDate::getFactor() const {
	return this->factor;
}
