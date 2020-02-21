#include "StudentDatabase.h"

using namespace std;

int main()
{
	while(1)
	{
		char input;
		system("clear");
		cout<<"0: Add student\n1: Read database\n2: Save database\n3: Display student data\n4: Student grade\n\nq: Quit\n"<<endl;
		cin>>input;
		switch(input)
		{
			case 'q' : return 0;
				break;
			case '0' : 
				break;
			
			default: cout<<"Looping"<<endl;
		}
	}
	
	
	return 0;
}


