/*Title: Representation of graph in the memory using adjacency matrix*/
/*Name: Prabodh Wankhede
Roll No.: 57
SE(B)
*/
#include <iostream>
using namespace std;

int adj_mat[50][50];

void init()
{
	for(int i=0; i<50; i++)
		for(int j=0; j<50; j++)
			adj_mat[i][j] = 0;
}

int main()
{
    init();
	cout<<"Enter no. of cities: ";
	int n;
	cin>>n;
	string cities[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter city #"<<i<<" (Airport Code): ";
		cin>>cities[i];
	}
	cout<<"\nYour cities are: "<<endl;
	for(int i=0; i<n; i++)
		cout<<"city #"<<i<<": "<<cities[i]<<endl;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			cout<<"Enter distance between "<<cities[i]<<" and "<<cities[j]<<": ";
			cin>>adj_mat[i][j];
			adj_mat[j][i] = adj_mat[i][j];
		}
	}
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<"\t"<<cities[i]<<"\t";
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<cities[i];
		for(int j=0; j<n; j++)
			cout<<"\t"<<adj_mat[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}
/*
        PN              MUM             NGP             NDL
PN      0               200             900             1600

MUM     200             0               1000            1200

NGP     900             1000            0               1000

NDL     1600            1200            1000            0
*/
