#include <iostream>
using namespace std;

class graph
{
     int adj_mat[50][50];
	int n, u;
     public:
	graph()
	{
		
	}
	   int city();
	//  void display();
};

	int graph :: city()
{
	 	cout<<"Enter no. of cities: ";
		cin>>n;
		string cities[n];
	  	for(int i=0; i<n; i++)
		{
			cout<<"Enter city #"<<i+1<<" : ";
			cin>>cities[i];
		}
			cout<<"\nYour cities are: "<<endl;
			for(int i=0; i<n; i++)
			cout<<"city #"<<i+1<<": "<<cities[i]<<endl;

		cout<<"If You Dont Want To Any Weight Enter 0 "<<endl;
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
	    }	


int main()
{
   graph g;
   g.city();
   //g.display();

    return 0;
}
