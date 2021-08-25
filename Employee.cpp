#include "Employee.h"

ofstream* Employee::outputFile = NULL;
ifstream* Employee::inputFile = NULL;

int Employee::locationCount = 0;
int Employee::highestNumber = 0;
long Employee::highestLocation = 0;
Array <Employee::Location>
Employee::locationList;

 Employee:: Employee() {
     memset(_name, 0, maxNameLen);
     _id = -1;
     location = -1;
     salaryType = globallSalary;
     _salary = 0;
     employeeStatus = on;
     _hireDate.setDate(1,1, 1901 );
}

 void  Employee:: openFile(){

     Employee employee;
     inputFile = new ifstream("employee.data",ios::in | ios::binary);
     if (inputFile->bad())
     {
         delete inputFile;
         throw CantOpenFile();
     }
     inputFile->seekg(0);

     for (locationCount = 0; ; locationCount++)
     {
         locationList[locationCount].location = inputFile->tellg();
         try
         {
             employee.readInputFile();
         }
         catch (exception e) // cheking the end of file and stop reading
         {
             break;
         }
         if (employee._id > highestNumber)
             highestNumber = employee._id;
         locationList[locationCount].num = employee._id;
     }

     highestLocation = inputFile->tellg();
     inputFile->close();
     delete inputFile;
 }

 void Employee:: readInputFile(long id) {
     inputFile = new ifstream("employee.datas",ios::in | ios::binary);
     if (inputFile->bad())
     {
         delete inputFile;
         throw CantOpenFile();
     }

     int i;
     for (i = 0; i < locationCount; i++)
     {
         if (locationList[i].num == id)
             break;
     }
     if (i == locationCount)
         throw NoSuch();

     inputFile->seekg(locationList[i].location,ios::beg);
     readInputFile();
     inputFile->close();
     delete inputFile;
 }

 void Employee:: readInputFile() {
     long location = inputFile->tellg();
     int id;
     inputFile->read((char*) &id, sizeof(id));
     if (inputFile->gcount() != sizeof(id))
         throw "end of file";
     inputFile->read((char*)&employeeStatus, sizeof(employeeStatus));
     inputFile->read(_name, maxNameLen);
     inputFile->read((char*)&salaryType,sizeof(salaryType));
     inputFile->read((char*)&_salary, sizeof(_salary));
     _hireDate.readDate(inputFile);
 }

 void Employee:: setStatus(employee_status st) {
     employeeStatus = st; 
 }

 void Employee:: setUpdate() {

 }

 void  Employee::closeFile() {
     inputFile->close();
     delete inputFile;
 }

 Employee:: ~Employee() {
     memset("", 0, 0);
     _id = 0;
     location = -2;
     salaryType = globallSalary;
     _salary = 0;
     employeeStatus = on;
     _hireDate.setDate(0, 0, 0);
 }