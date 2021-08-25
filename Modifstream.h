#pragma once
#include <fstream>
#include <string>
#include "Date.h"

using namespace std;

int const maxSalaryLen = 12;

class Modifstream: public ifstream {
	
public:
	Modifstream(string name) :ifstream(name) {};
	string readName(string str, int maxLen);
	string readDate(string str, int maxLen);
	long getSalary();
	Date getDate()

};