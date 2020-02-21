#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
//Include Statements
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

//Default namespace
using namespace std;

//Variable declarations




namespace LVXJOR001
{
	//Method declarations
	void readFile();
	void writeFile();
	void addStudent(string name, string surname, string studentNo, string classRecord);
	void printStudents();
	void printStudent(string studentNo);
	void averageMark(string studentNo);
	int inDB(string studentNo);
}
#endif
