 #pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>


class Date {

protected:
	short _day, _month;
	int _year;

public:
	Date(short, short, int);
	Date();
	~Date();
	short getDay () const;
	short getMonth() const;
	int getYear() const;
	void setDate(short, short, int);
	void readDate(std:: ifstream* data );
	void Write(std:: ofstream* outputData);
};