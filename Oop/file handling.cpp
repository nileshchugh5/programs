/* Write a C++ program that creates an output file, writes information to it, closes the file and
		  	   open it again as an input file and read the information from the file. */



#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <string.h>
using namespace std;

int main()
{
	string data;
	char name[10];
	cout<<"\n\n\t\t Enter the name of thye file to be created:- ";
	cin>>name;
	ofstream fout;
	fout.open(name,ios::app);
	if(!fout)
	{
		cout<<"\n\n\t\t\t Error in creating the file... \n\t\t Exiting the program";
		exit(0);
	}
	cout<<"\n\n\t\t\t File successfully created...!!!";
	cout<<"\n\n\t\t Enter the data & to end press @:- ";
	while(getline(cin,data))
	{
		if(data=="@")
		{
			cout<<"INSIDE IF";
			break;
		}
		fout<<data<<endl;
	}
	cout<<"\n\n\t\t Data successfully entered..!!!";
	cout<<"\n\n\t\t Closing the file";
	fout.close();

	ifstream fin;
	fin.open(name);
	if(!fin)
	{
		cout<<"\n\n\t\t\t Error in opening the file... \n\t\t Exiting the program";
		exit(0);
	}
	cout<<"\n\n\t\t\t File successfully opened...!!!";
	cout<<"\n\n\t\t Contents of the file are:- \n";
	while(fin)
	{
		getline(fin,data);
		cout<<data<<endl;
	}
	cout<<"\n\n\t\t Data successfully read..!!!";
	cout<<"\n\n\t\t Closing the file";
	fin.close();
	return 0;
}
