#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class AdjList
{
public:
    node *head;
};

class Graph
{
 public:
    int V;
    AdjList *array;
    Graph(int V)
    {
        this->V = V;
        array = new AdjList[V];
        for(int i=0; i<V; i++)
            array[i].head = NULL;
    }
    node* new_node(int val)
    {
        node *tempNode = new node;
        tempNode->data = val;
        tempNode->next = NULL;
        return tempNode;
    }
    void add_edge(int src, int dest)
    {
        node *temp = new_node(src);
        temp->next = array[dest].head;
        array[dest].head = temp;
        temp = new_node(dest);
        temp->next = array[src].head;
        array[src].head = temp;
    }
    void print_graph()
    {
        for(int v=0; v<V; v++)
        {
            node* temp1;
            temp1 = new node;
            temp1 = array[v].head;
            cout<<v<<": ";
            while (temp1 != NULL)
            {
                cout<<temp1->data<<" ";
                temp1 = temp1->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter no. of vertices: ";
    cin>>n;
    Graph G(n);
    char op;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            cout<<"Do you want an edge between "<<i<<" and "<<j<<": ";
            cin>>op;
            if(op=='y' || op=='y')
                G.add_edge(i,j);
        }
    }
    G.print_graph();
    return 0;
}