/*Crete User defined exception to check the following conditions and throw the exception if the
criterion does not meet.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception.*/
#include<iostream>
using namespace std;
class info
{
	string city;
	int age,flag;
	char vehicle;
	double income;
	public:
		void getdata();
		void display();
};
void info::getdata()
{
	try
	{
    flag=0;
	cout<<"\n\tEnter your city\n";
	cin>>city;
	cout<<"\n\tEnter your age\n";
	cin>>age;
	cout<<"\n\tEnter your income\n";
	cin>>income;
	cout<<"\n\tDo you have 4 wheeler vehicle\n IF yes press y\n";
	cin>>vehicle;
	if(city!="pune"&&city!="mumbai"&&city!="bangalore"&&city!="chennai")
		throw city;
	if(age<18||age>55)
		throw age;
	if(vehicle!='y')
		throw vehicle;
	if(income<50000||income>100000)
		throw income;
	}
	catch(...)
	{
	    flag=1;
	}

}
void info::display()
{
	if(flag==1)
		cout<<"\nException caught!!!";
	else
	{
		cout<<"\n City is"<<city;
		cout<<"\n Age is"<<age;
		cout<<"\n Income is"<<income;
		cout<<"\n Vehicle is 4 wheeler"<<vehicle;
	}
}
int main()
  {
   char ch;
   do
   {
   info b1;
   b1.getdata();
   b1.display();
   cout<<"\nIf you want to continue!!!\nPress y or Y\n";
   cin>>ch;
   }while(ch=='y'||ch=='Y');
   return 0;
  }


