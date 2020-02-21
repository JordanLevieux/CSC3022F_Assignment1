#include "StudentRecord.h"

//Struct to hold student data
struct Record
{
	string name;
	string surname;
	string studentNo;
	string classRecord;
};

//Vector to hold student records
vector <Record> studentRecords;

//Read contents of studentDB.dat into a vector of Records
void LVXJOR001::readFile()
{
	string name;
	string surname;
	string studentNo;
	string classRecord;
	int counter = 0;
	//Open file with student information
	ifstream studentDB("studentDB.dat");
	if (!studentDB){cerr<<"File failed to open"<<endl;}
	while (getline(studentDB, name, ','))
	{
		studentRecords.emplace_back(Record{});
		getline(studentDB, surname, ',');
		getline(studentDB, studentNo, ',');
		getline(studentDB, classRecord);
		
		studentRecords[counter] = {name, surname, studentNo, classRecord};
		counter++;
	}
	
	studentDB.close();
}

//Writes the vector of Records back to studentDB.dat
void LVXJOR001::writeFile()
{
	ofstream studentDB("studentDB.dat");
	for (int i=0; i<studentRecords.size(); i++)
	{
		studentDB<<studentRecords[i].name<<","<<studentRecords[i].surname<<","<<studentRecords[i].studentNo<<","<<studentRecords[i].classRecord<<endl;
	}
	studentDB.close();
}

//Adds a student to the Record vector
void LVXJOR001::addStudent(string name, string surname, string studentNo, string classRecord)
{
	int pos = LVXJOR001::inDB(studentNo);
	Record temp = {name, surname, studentNo, classRecord};
	if (pos == -1)
		studentRecords.emplace_back(temp);
	else
		studentRecords[pos] = temp;
}

//Prints students' records to standard output
void LVXJOR001::printStudents()
{
	system("clear");
	char temp;
	for (int i=0; i<studentRecords.size(); i++)
	{
		cout<<studentRecords[i].name<<","<<studentRecords[i].surname<<","<<studentRecords[i].studentNo<<","<<studentRecords[i].classRecord<<endl;
	}
	//Hold data on screen
	cout<<"\nPress 1 to continue"<<endl;
	cin>>temp;
}

//Prints the record for the desired student
void LVXJOR001::printStudent(string studentNo)
{
	system("clear");
	char temp=1;
	for (int i=0; i<studentRecords.size(); i++)
	{
		if (!studentRecords[i].studentNo.compare(studentNo))
		{
			cout<<studentRecords[i].name<<","<<studentRecords[i].surname<<","<<studentRecords[i].studentNo<<","<<studentRecords[i].classRecord<<endl;
			temp = 0;
			break;
		}
	}
	//Hold data on screen
	if (temp){cout<<"Could not find student"<<endl;}
	cout<<"\nPress 1 to continue"<<endl;
	cin>>temp;
}

//Print the average mark of the desired student student
void LVXJOR001::averageMark(string studentNo)
{
	int location;
	string sMark;
	double mark = 0.0;
	int counter = 0;
	char temp = 1;
	for (int i=0; i<studentRecords.size(); i++)
	{
		if (!studentRecords[i].studentNo.compare(studentNo))
		{
			location = i;
			temp = 0;
			break;
		}
	}
	system("clear");
	if (temp)
	{
		cout<<"Student not found"<<endl;
	}
	else
	{
		istringstream str(studentRecords[location].classRecord);
		while (str >> sMark)
		{
			mark += stod(sMark);
			counter++;
		}
		mark = mark/counter;
		cout<<"Average mark for "<<studentNo<<" is: "<<mark<<endl;
	}
	cout<<"\nPress1 to continue"<<endl;
		cin>>sMark;
}

//Check if student is in DB
int LVXJOR001::inDB(string studentNo)
{
	for (int i=0; i<studentRecords.size(); i++)
	{
		if (!studentRecords[i].studentNo.compare(studentNo))
		{
			return i;
		}
	}
	return -1;
}
