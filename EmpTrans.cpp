#include "EmpTrans.h"
#include "Employee.h"
#include <fstream>
#include <iostream>

using namespace std;

EmpTrans:: EmpTrans() {

}

EmpTrans:: ~EmpTrans() {

}

void EmpTrans:: openUpadteFile() {

	if (file == NULL)
	{
		file = new Modifstream ("emptrans.data");
		if (file->bad())
		{
			delete file;
			throw CantOpenFile();
		}
	}
	file->seekg(0);
}

void EmpTrans:: closeUpadteFile() {
		file->close();
		delete file;
}

EmpTrans* EmpTrans:: readNextList()
{
	EmpTrans* empTrans;
	char transactionType;
	char ch;

	(*file) >> transactionType;
	if (file->eof())
		throw NoMore();

	if (transactionType == 'A')
	{
		empTrans = new  AddNewWorker;
		empTrans->readCommand();
		empTrans-> _id = -1; // -1 represent a new employeer
	}
	else if (transactionType == 'C')
	{
		empTrans = new ChangeWorkerDetail;
		(*file) >> empTrans->_id;
		empTrans->readCommand();
	}
	else if (transactionType == 'D')
	{
		empTrans = new DeleteWorker;
		(*file) >> empTrans->_id;
	}
	else
		throw InvalidType();

	do { file -> get(ch); } while ((!file -> eof()) && (ch != '\n'));
	return empTrans;
}
 


void EmpTrans:: readCommand()  {

	char ch;
	file->readName(_name, maxNameLen);

	*file >> ch;
	if (ch == 'S')
		salaryType = globalSalary;
	else if (ch == 'H')
		salaryType = perHourSalary;
	else
		throw "Invalid content ";

	_salary = file->getSalary();
	*_hireDate = file->getDate();
}

 void DeleteWorker:: setUpdate() {
	 Employee employee;
	 try
	 {
		 employee.readInputFile(_id);
	 }
	 catch (Employee::NoSuch)
	 {
		 cerr << endl << "Transaction found for invalid employee : " << _id;
			 throw;
	 }
	 employee.setStatus(on);
	 employee.setUpdate();
 
}