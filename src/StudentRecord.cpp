#include "StudentRecord.h"



void readFile()
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

void writeFile()
{
	ofstream studentDB("studentDB.dat");
	for (int i=0; i<studentRecords.size(); i++)
	{
		studentDB<<studentRecords[i].name<<","<<studentRecords[i].surname<<","<<studentRecords[i].studentNo<<","<<studentRecords[i].classRecord<<endl;
	}
	studentDB.close();
}

void addStudent(string name, string surname, string studentNo, string classRecord)
{
	Record temp = {name, surname, studentNo, classRecord};
	studentRecords.emplace_back(temp);
}

int main()
{
	readFile();
	addStudent("Last","First","SNUM","20 21");
	writeFile();
	return 0;
}
