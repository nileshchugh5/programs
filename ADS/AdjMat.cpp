#include <iostream>
using namespace std;

int adj_mat[50][50];

void init()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            adj_mat[i][j] = 0;
}

void create(int V)
{
    int n;
    for(int i=0; i<V; i++)
    {
        for(int j=i+1; j<V; j++)
        {
            cout<<"Do you want an edge between "<<i+1<<" and "<<j+1<<" (1/0): ";
            cin>>n;
            if(n==1)
                adj_mat[i][j] = adj_mat[j][i] = 1;
        }
    }
}

void display(int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
            cout<<adj_mat[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    init();
    int V;
    cout<<"Enter no. of vertices: ";
    cin>>V;
    create(V);
    display(V);
    return 0;
}
