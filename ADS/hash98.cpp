#include<iostream>
#define size 10
using namespace std;

class hashtable
{
 long hash[size]
 long phone,key;
 int index;
 public:
 		hashtable
 		{
 		for(int i=0;i<size;i++)
 		hash[i]=-1;
 		}
        void create();
        void display();
        void search();
};

int main()
{
	hashtable ht;
	int op;
	char ch;
	
	do
	{
	cout<<"WHAT DO YOU WANT TO DO-  "<<endl;
    cout<<"1.INSERT A PHONE NUMBER\n 2.DISPLAY THE HASH TABLE\n 3.SEARCH A PHONE NUMBER  "<<endl;
    cout<<"ENTER YOUR CHOICE- ";
    cin>>op;
    
    switch(op)
    {
    	case 1:
    			ht.create();
    			break;
    	case 2:
    			ht.display();
    			break;
    	case 3:
    			ht.search();
    			break;
    	default:
    			cout<<"INVALID OPTION ";
    }
    
    cout<<" DO YOU WANT TO RUN AGAIN (Y/N) ";
    cin>>ch;
}

	while (ch=='Y'||ch=='y');
	return 0;
}

void hashtable:: create()
		{
		 cout<<" ENTER THE PHONE NUMBER YOU WANT TO INSERT-  ";
		 cin>>phone;
		 
		 index=phone%size;
		 hash[index]=phone;
		}

void hashtable:: display()
		{
		 for(int i=0;i<size;i++)
		  cout<<i<<"."<<hash[i]<<endl; 
		} 

void hashtable::search()
		{
		 cout<<"ENTER THE PHONE NUMBER YOU WANT TO SEARCH:  ";
		 cin>>key;
		 
		 index=key%size;
		 
		 if(key==hash[index])
		 	cout<<" PHONE NUMBER FOUND AT INDEX =  "<<index<<endl;
		 else
		 	cout<<" PHONE NUMBER NOT FOUND  "<<endl;
		} 				 

	    									    
