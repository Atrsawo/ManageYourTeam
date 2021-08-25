#pragma once
#include "Date.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "Array.h"

using namespace std;

int const maxNameLen = 40;

enum salary_type {
	globallSalary = 0,
	perHourrSalary = 1
};

enum employee_status {
	on = 1,
	off = 0
};


class Employee {

protected:
	long _id;
	char _name [maxNameLen];
	unsigned int _salary;
	salary_type salaryType;
	employee_status employeeStatus;
	static ifstream* inputFile;
	static ofstream* outputFile;
	Date _hireDate;
	struct Location {
		int num;
		long location;
	};
	static int locationCount;
	static int highestNumber;
	static long highestLocation;
	long location;
	static Array<Location> locationList;
	void readInputFile();
public:
	Employee();
	~Employee();
	static void openFile();
	static void closeFile();
	void readList(long);
	void updateList(employee_status);
	void readInputFile(long);
	void setStatus(employee_status);
	void setUpdate();

	class CantOpenFile {
		CantOpenFile() {
			throw "Cant not open updating file";
		}
	};

	class NoSuch  {
		friend class Employee;
		friend class DeleteWorker;
		NoSuch() {
			throw "No such employer in the list";
		}
	}; 

	friend class CantOpenFile;
	friend class NoSuch;

	class CantOpenFile {
		friend class Employee;
		CantOpenFile() {
			throw "No more data in the list";
		}
	};
};
