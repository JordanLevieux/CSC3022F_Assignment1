#include "StudentDatabase.h"
#include "StudentRecord.h"
using namespace std;

int main()
{
	string name, surname, studentNo, classRecord;
	char input;
	LVXJOR001::readFile();
	
	while(1)
	{
		system("clear");
		cout<<"0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Student grade\n\nq: Quit\n"<<endl;
		cin>>input;
		system("clear");
		switch(input)
		{
			case 'q' : return 0;
				break;
			case '0' :
				cout<<"Enter student's name:\n";
				cin>>name;
				cout<<"Enter student's surname:\n";
				cin>>surname;
				cout<<"Enter student number:\n";
				cin>>studentNo;
				cin.ignore();
				cout<<"Enter marks:\n";
				getline(cin, classRecord);				
				
				LVXJOR001::addStudent(name,surname,studentNo,classRecord);
				break;
			
			case '1' :
				LVXJOR001::printStudents();
				break;
			case '2' :
				LVXJOR001::writeFile();
				cout<<"File saved.\n\nPress 1 to continue\n";
				cin>>input;
				break;
			case '3' :
				cout<<"Enter student number:\n";
				cin>>studentNo;
				LVXJOR001::printStudent(studentNo);
				break;
			case '4' :
				cout<<"Enter student number:\n";
				cin>>studentNo;
				LVXJOR001::averageMark(studentNo);
		}
	}
	
	
	return 0;
}


