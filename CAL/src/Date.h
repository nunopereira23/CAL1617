/*
 * Date.h
 *
 *  Created on: 05/04/2017
 *      Author: Fr0sk
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <string>
#include <iostream>
#include <vector>
#include <ctime>


/**exception thrown when attempting to create an invalid date
 * @struct ExceptionInvalidDate
 * @brief exception for class Data
 */
struct ExceptionInvalidDate {
	std::string data;	/**< component of Date that created the exception*/
	int value;			/**< invalid value the component of Date took*/
	/**
	 * Creates new exception with information provided.
	 * @brief class InvalidDate constructor.
	 *
	 * @param error component of Date that created the exception
	 * @param val 	invalid value the component of Date took
	 */
	ExceptionInvalidDate(std::string error, int val): data(error), value(val) {}
};

class Date {
private:
	unsigned int day;	/**< date's day*/
	unsigned int month;	/**< date's month*/
	unsigned int year;	/**< date's year*/
public:
	/**
		 * Creates new date with information provided.
		 * @brief class Data constructor.
		 *
		 * @param d 		date's day
		 * @param m		 	date's month
		 * @param a			date's year
		 */
		Date(unsigned int d, unsigned int m, unsigned int a){
			if(m < 0 || m > 12)
				throw ExceptionInvalidDate("month",m);
			if(d < 0 || d > 31)
				throw ExceptionInvalidDate("day",d);
			if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
				if(m == 2 && a%4 == 0 && d > 29)
				throw ExceptionInvalidDate("day",d);
			if(m == 2 && a%4 != 0 && d > 28)
				throw ExceptionInvalidDate("day",d);
			day = d;
			month = m;
			year = a;
		}
};

#endif /* SRC_DATE_H_ */
