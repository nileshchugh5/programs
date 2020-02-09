/*Write C++ program using STL for implementation of stack & queue using SLL*/
#include<iostream>
#include<stack>
#include<queue>
#include<iterator>
using namespace std;
class stac
{

		stack<int> lst;

		public:
	    	void push1(int a);
	    	void pop1();
	    	void display();

};
class que
{
	queue<int> qst;
	public:
		queue<int>q;
		void push1(int k);
		void pop1();
		void display();
};

void stac::push1(int a)
{
	lst.push(a);
}

void stac::pop1()
{
	lst.pop();
}
void stac::display()
{
	if(!lst.empty())
    {
        while(!lst.empty())
        {
            cout<<"\t"<<lst.top();
            lst.pop();

        }
    }
    else
        cout<<"\nStack is empty,";


}
void que::push1(int b)
{
	qst.push(b);
}

void que::pop1()
{
	qst.pop();
}

void que::display()
{
    if(!qst.empty())
    {
        while(!qst.empty())
        {
            cout<<"\t"<<qst.front();
            qst.pop();

        }
    }
    else
        cout<<"\nQueue is empty,";



}

int main()
{
	stac s;
	que q;
	int a;
	int ch;
	char y;
	char choice;
	int n;
	do
	{
     X:cout<<"\nEnter choice\n1.STACK\n2.QUEUE\n";
     cin>>n;
	switch(n)
	{
		case 1:
                do
                {
                cout<<"\n\t\tSTACK MENU\n"<<endl;
                cout<<"\n1.INSERT AN ELEMENT "<<"\n"<<"2.DELETE AN ELEMENT "<<"\n3.Display\n4.Men menu\n"<<endl;
                cout<<"\nEnter your choice : \n";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                        cout<<endl<<"\nEnter an element you want to insert\n :";
                        cin>>a;
                        s.push1(a);
                        break;
                    case 2:
                        s.pop1();
                        break;
                    case 3:
                        s.display();
                        break;
                    case 4:
                        goto X;
                        break;
                    default:
                        cout<<"\nWrong choice!!!\n";
                        break;
                }
                cout<<"\n\nDO YOU WANT TO CONTINUE ...? IF YES PRESS Y OR y ==> ";
                cin>>y;

                    }while(y=='y'||y=='Y');
                    break;
        case 2:
                do
                {
                    cout<<"\n\n\t\t\tQUEUE MENU ";
                    cout<<"\n\n1.INSERT AN ELEMENT ";
                    cout<<"\n2.DELETE AN ELEMENT ";
                    cout<<"\n3.Display";
                    cout<<"\n4Men menu\n";
                    cout<<"\n\nEnter your choice ==> ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            cout<<"\nENTER AN ELEMENT TO INSERT INTO QUEUE ==> ";
                            cin>>a;
                            q.push1(a);

                            break;

                        case 2:
                            q.pop1();
                            cout<<"\nELEMENT DELETED";

                            break;

                        case 3:
                            q.display();
                            break;
                        case 4:
                            goto X;
                            break;

                        default:
                        cout<<"\nWrong choice!!!\n";
                        break;
                    }

                    cout<<"\n\nDO YOU WANT TO CONTINUE ...? IF YES PRESS Y OR y ==> ";
                    cin>>y;

                    }while(y=='y'||y=='Y');
                    break;
        default:
            cout<<"\nWrong choice!!!\n";
            break;



	}
	cout<<"DO YOU WANT TO CONTINUE ....? IF YES PRESS Y OR y ==>";
	cin>>choice;
	}while(choice=='y'||choice=='Y');
	return 0;
}
