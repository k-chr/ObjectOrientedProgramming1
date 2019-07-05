#include <iostream>
using namespace std;
#include "map_template.h"		//defines template map_template<Key,Value>

int main(void)
{
	typedef unsigned int ID; 							//Identification number of Employee
	map_template<ID,Employee> Database;					//Database of employees
	try{
		Database.Add(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
		Database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); 	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
		Database.Add(730505129,Employee("Anna Zaradna","secretary",32));
		cout << Database << endl;							//Print databese

		map_template<ID,Employee> NewDatabase = Database;	//Make a copy of database
	
		Employee* pE;
		pE = NewDatabase.Find(510212881);	
		if(pE){			//Find employee using its ID
			pE->Position = "salesman";	
		}						//Modify the position of employee
		pE = NewDatabase.Find(761028073);
		if(pE){					//Find employee using its ID
			pE->Age = 29;	
		}									//Modify the age of employee
		cout << Database << endl;
		Database = NewDatabase;
		cout << Database << endl;	 	//Add third employee: name: Anna Zaradna, position: secretary, age: 32
		typedef string Title;
		map_template<Title, Book> Library;
		Library.Add("What will it be like in AnCap?", Book("Kelthuz", "Shelved", "Important message", 14213788));
		map_template<Title, Book> NewLibrary = Library;
		cout << Library << endl;
		Book *pB = NewLibrary.Find("What will it be like in AnCap?");
		if(pB){
			pB->Status = "Loaned";
			Library = NewLibrary;
			cout << Library << endl;
		}
	}
	catch(const Key_already_exists& err){
		cout << "Key_already_exists" << endl;
	}
	
	
}
