#include "Date.h"

	Date:: Date(short  d = 1, short m = 1, int y = 2021){
	setDate(d, m, y);
	}

	short Date:: getDay() const {
		return  _day;
	}

	short Date::getMonth() const {
		return  _month;
	}

	int Date:: getYear() const {
		return  _year;
	}

	void Date:: setDate(short d, short m, int y) {
		int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		if ((m < 1) || (m> 12))
		{
			throw "Ilegal month";
		}
		this->_month = m;

		if ((d < 1) || (d> months[m - 1]))
		{
			throw "Day out of range";
		}
		this->_day = d;

		if (y% 4 == 0)
		{
			months[1] = 29;
		}_year = y;
	}
	
	 Date:: ~Date() {
		_day = 0;
		_month = 0;
		_year = 0;
	}

	 void Date:: readDate(std:: ifstream* data) {
		 data->read((char*)&_year, sizeof(_year));
		 data ->read((char*)&_month, sizeof(_month));
		 data->read((char*)&_day, sizeof(_day));
	  } 
	 void Date:: Write(std::ofstream* outputData) {
		 outputData->write((char*)&_year, sizeof(_year));
		 outputData->write((char*)&_month, sizeof(_month));
		 outputData->write((char*)&_day, sizeof(_day));
	 }