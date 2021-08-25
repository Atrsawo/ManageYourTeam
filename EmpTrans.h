#pragma once

#include "Date.h"
#include <fstream>
#include <iostream>
#include "Modifstream.h"


int const maxNameLen = 40;

class AddNewWorker;
class ChangeWorkerDetail;
class DeleteWorker;

class EmpTrans {


protected:
	long _id;
	char _name[maxNameLen];
	long _salary;
	Date* _hireDate;
	static Modifstream *file;
	
public:
	EmpTrans();
	~EmpTrans();
	static void openUpadteFile();
	static void closeUpadteFile();
	static EmpTrans* readNextList();
	void setUpdate();
	void readCommand() ;
	

	class CantOpenFile {
		
		friend class EmpTrans;
		CantOpenFile() {
			throw "Cant not open updating file";
		}
	
	};

	class NoMore {
		friend class EmpTrans;
		NoMore() {
			throw "No more data in the list";
		}

	};

	class InvalidType {
		friend class EmpTrans;
		InvalidType() {
			throw "Invalid type of updating command";
		}
	};
};

class AddNewWorker : public EmpTrans {
public:
	void setUpdate();
};

class ChangeWorkerDetail : public EmpTrans {
public:
	void setUpdate();
};

class DeleteWorker : public Employee {
public:
	void setUpdate();
};



