
#include "EmpTrans.h"
#include "Employee.h"
#include <exception>



class Main {

	 int  main() {
			 EmpTrans *empTrans;

			 try {
				 Employee:: openFile();
				 EmpTrans::openUpadteFile();
			 }
			 catch (Employee:: CantOpenFile) {
				 return - 1;
			 }
			 catch (EmpTrans :: CantOpenFile) {
				 return - 1;
			 }
			 for (; ; )
			 {
				 try
				 {
					 empTrans = EmpTrans:: readNextList();
					 empTrans->setUpdate();
					 delete empTrans;
				 }
				 catch (EmpTrans:: NoMore)
				 {
					 break;
				 }
				 catch (Employee:: NoSuch)
				 {
					 break;
				 }
			 }
			 Employee:: closeFile();
			 EmpTrans:: closeUpadteFile();
		 return 0;

		 
	}
};