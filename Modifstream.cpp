#include "Modifstream.h"

	 string Modifstream:: readName(string str, int maxLen) {
		  string temp = "";
		  int i = 0, first = 0, last = 0;
		  while(str[i] != '"') { 
			  i++;
			  first = i;
		  }
		  if (str[++i] < 'z' && str[i] >'A') {
			  while (str[i] != '"') { 
				  i++;
				  last = i;
			  }
			  if(str[++i] != '"')  throw "Ilegal string ";
			  else {
				  for (; first < last ; first++) {
					  temp += str[first];
				  }
			  }
		  }
		  else  throw "Ilegal string ";
		 str = temp;
		 return str;
	  }
	 
	 string Modifstream:: readDate(string str, int maxLen) {
		 string temp = "";
		 int i = 0, cnt = 0, first = 0, last = 0;
		 while (str[i] != '/' && i == str.length()) {i++;}

		 if (i == str.length()) throw " Date do not mentioned";

		 else if (str[i] == '/') first = i - 4;

		 while (str[i] != '/' && i == str.length()) { i++; }
		 last = i + 2;

		 if (i == str.length()) throw " Ilegal date format";

		 else if (str[i] == '/') {
			 for (; first <= last; first++) {
				 temp += str[first];
			 }
		 }
		 str = temp;
		 return str;
	 }

	 long Modifstream:: getSalary() {
		 char ch;
		 int i = 0;
		 *this >> ch;

		 char temp[maxSalaryLen];
		 while (ch != ' ') {
			 temp[i] = ch;
			 *this >> ch;
		 }
		 return atoi(temp);
	 }

	 Date Modifstream:: getDate() {
		
		 char ch;
		 short what = 0, d, m; // what means if it is the year or month or days
		 int y;
		 int i = 0;
		 *this >> ch;
		 while (ch == ' ') { this->get(ch); } // skiping all tabes
		 char temp[maxSalaryLen];
		 while (ch != ' ') {
			 i = 0;
			 while (ch != '/') {
				temp[i] = ch;
				*this >> ch;
			 }
			 if (what = 0) {
				 y = atoi(temp);
			 }
			 else if (what = 1) {
				 m = atoi(temp);
			 }
			 else d = atoi(temp);
			 what++;
			 *this >> ch;
		 }
		 return Date(d, m, y);
	 }