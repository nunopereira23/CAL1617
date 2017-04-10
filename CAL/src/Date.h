/*
 * Date.h

 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>


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

	/**
	 * Converts the date to the number of days passed since epoch.
	 * @brief Converts the date to number of days.
	 */
	unsigned int convertToDays() const {
		unsigned int m = (this->month + 9) % 12;
		unsigned int y = this->year - m/10;
		return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (this->day - 1);
	}

	/**
	 * Converts the the number of days passed since epoch to date.
	 * @brief Converts number of days to date.
	 *
	 * @param days	the number of days since epoch
	 */
	void convertToDate(unsigned int days) {
		unsigned int y = (10000*days + 14780)/3652425;
		unsigned int ddd = days - (365*y + y/4 - y/100 + y/400);
		if (ddd < 0) {
			y = y - 1;
			ddd = days - (365*y + y/4 - y/100 + y/400);
		}

		unsigned int mi = (100*ddd + 52)/3060;
		unsigned int mm = (mi + 2)%12 + 1;
		y = y + (mi + 2)/12;
		unsigned int dd = ddd - (mi*306 + 5)/10 + 1;

		this->day = dd;
		this->month = mm;
		this->year = y;
	}

public:
	/**
	 * Creates new date with information provided.
	 * @brief class Date constructor.
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

	/**
	 * Creates new date with information provided.
	 * @brief class Date constructor.
	 *
	 * @param date 		date in dd-mm-yyyy format
	 */
	Date(std::string date){
		std::string d = date.substr(0, date.find('-'));
		date = date.substr(date.find('-') + 1);
		std::string m = date.substr(0, date.find('-'));
		date = date.substr(date.find('-') + 1);

		day = (unsigned int) atoi(d.c_str());
		month = (unsigned int) atoi(m.c_str());;
		year = (unsigned int) atoi(date.c_str());;
	}

	/**
	 * Adds the given number of days to the date.
	 * @brief Adds days to date.
	 *
	 * @param days to add to the date
	 */
	void addDays(unsigned int days){
		unsigned int numberOfDays = convertToDays();
		numberOfDays += days;
		convertToDate(numberOfDays);
	}

	bool isInvalid() {
		if (day == 99 || month == 99 || year == 9999) {
			return false;
		}
		return true;
	}

	/**
	 * Creates new date with current day, month and year
	 * @brief class Date constructor with no arguments.
	 */
	Date(){
		time_t t = time(0); // time now
		struct tm * now = localtime(& t);
		day = now->tm_mday;
		month = now->tm_mon;
		year = now->tm_year + 1900;
	}

	/**
	 * sends date to out stream out
	 * @brief operator << for class Date
	 *
	 * @param out 		out stream chosen
	 * @param date		date to be sent
	 */
	friend std::ostream& operator<< (std::ostream& out, const Date &date) {
		out << date.day << "-" << date.month << "-" << date.year;
		return out;
	}

	/**
	 * sends date to in stream in
	 * @brief operator >> for class Date
	 *
	 * @param in		in stream chosen
	 * @param date		date to be sent
	 */
	friend std::istream &operator>>(std::istream  &in, Date &date ){
		char lixo;
		in >> date.day >> lixo >> date.month >> lixo >> date.year;

		return in;
	}

	bool operator< (const Date& right) const{
		std::vector<int> l,r;
		l.push_back(this->year);
		l.push_back(this->month);
		l.push_back(this->day);
		r.push_back(right.year);
		r.push_back(right.month);
		r.push_back(right.day);

		for(size_t i = 0;i < l.size();i++){
			if(l[i] < r[i])
				return true;
			else if(l[i] > r[i])
				return false;
		}

		return false;
	}

	bool operator==(const Date& right) const{
		if(this->day == right.day && this->month== right.month && this->year == right.year)
			return true;

		return false;
	}
};

#endif /* SRC_DATE_H_ */
