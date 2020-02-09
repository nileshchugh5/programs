/*Implement a class Complex which represents the Complex Number data type. Implement the
following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.*/
#include<iostream>
using namespace std;
class complex
{
public:
	float real;
	float img;
	complex()
	{
		real=0;
		img=0;
	}
void getdata();


complex operator +(complex);
complex operator *(complex);
friend istream& operator>>(istream &,complex &);
friend ostream& operator<<(istream &,complex &);

};
complex complex::operator +(complex c)
{
	complex temp;
	temp.real=real+c.real;
	temp.img=img+c.img;
	cout<<"\n---------------------------------------------\n";
	 cout<<"complex no. addition is::"<<endl<<temp.real<<"+"<<temp.img<<"i"<<endl;
	 cout<<"\n---------------------------------------------\n";
	return temp;
}
complex complex::operator *(complex c)
{
	complex mul;
	mul.real=real*c.real-img*c.img;
	mul.img=real*c.img+img*c.real;
	cout<<"\n---------------------------------------------\n";
	 cout<<"complex no. multiplication is::"<<endl<<mul.real<<"+"<<mul.img<<"i"<<endl;
	 cout<<"\n---------------------------------------------\n";
	return mul;
}
void complex::getdata()
{
 cout<<"\n---------------------------------------------\n";
 cout<<"enter real and imaginary part"<<endl;
 cout<<"enter real part"<<endl;
 cin>>real;
 cout<<"enter imaginary part"<<endl;
 cin>>img;
 cout<<"\n---------------------------------------------\n";
 }
istream & operator>>(istream & in,complex &t)
{
cout<<"\n---------------------------------------------\n";
cout<<"enter real  part"<<endl;
in>>t.real;
cout<<endl;
cout<<"enter imaginary part"<<endl;
in>>t.img;
cout<<endl;
cout<<"\n---------------------------------------------\n";
}
ostream & operator<<(ostream & out,complex &t)
{
cout<<"\n---------------------------------------------\n";
cout<<"entered real and img no parts::"<<endl;
cout<<"real part:"<<endl;
out<<t.real;
cout<<endl;
cout<<"imaginary part"<<endl;
out<<t.img;
cout<<endl;
cout<<"\n---------------------------------------------\n";
}


int main()
{
complex c1,c2,c3;
cin>>c1;
cin>>c2;
cout<<c1;
cout<<c2;
c3=c1+c2;
c3=c1*c2;
return 0;
}
