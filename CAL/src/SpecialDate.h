/*
 * SpecialDate.h
 *
 *  Created on: 10/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_SPECIALDATE_H_
#define SRC_SPECIALDATE_H_

#include "Date.h"

class SpecialDate {
private:
	Date initialDate;
	Date finalDate;
	double factor;
public:
	SpecialDate(Date initialDate, Date finalDate, double factor);
	Date getInitialDate() const;
	Date getFinalDate() const;
	double getFactor() const;
};

#endif /* SRC_SPECIALDATE_H_ */
