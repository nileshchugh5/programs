#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int V;
	char op;
	cout<<"Enter no. of vertices: ";
	cin>>V;
	vector<int> AdjList[V];
	for(int i=0; i<V; i++)
	{
		for(int j=i+1; j<V; j++)
		{
			cout<<"Do you want an edge between "<<i<<" and "<<j<<": ";
			cin>>op;
			if(op=='y' || op=='Y')
			{
				AdjList[i].push_back(j);
				AdjList[j].push_back(i);
			}
		}
	}
	for(int i=0; i<V; i++)
	{
        cout<<i<<" ";
    	for(int j=0; j<AdjList[i].size(); j++)
    		cout<<AdjList[i][j]<<" ";
    	cout<<endl;
	}
	return 0;
}
