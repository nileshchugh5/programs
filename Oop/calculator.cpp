/*Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program
should take two operands from user and performs the operation on those two operands
depending upon the operator entered by user. Use a switch statement to select the operation.
Finally, display the result. */
#include <iostream>
#include <cstdlib>
using namespace std;


 class cal
 {
  private:
           float x,y;
           float z;

  public:
           void get();
           void put();
           void add();
           void sub();
           void mul();
           void div();

 };

 void cal::get()                                                 //INOUT OF THE VALUES FROM USER
 {
  cout<<"\n\n ENTER FIRST VALUES==>";
  cin>>x;
  cout<<"\n\n ENTER SECOND VALUES==>";
  cin>>y;
 }

 void cal::add()
 {
  z=x+y;
 }

 void cal::sub()
 {
  z=x-y;
 }

 void cal::mul()
 {
  z=x*y;
 }

 void cal::div()
 {
  z=x/y;
 }

 void cal:: put()
 {
  cout<<"\n\n THE ANSWER IS==>"<<z;
 }

 int main()
 {
   cal c;
   int ch;
   char cont;
   do
   {
   cout<<"\n\n\t\t\t\t\tMENU";                           //MENU OF CHOICE SELECTION FOR CALCULATOR
   cout<<"\n\t1. ADDITION";
   cout<<"\n\t2. SUBTRACTION";
   cout<<"\n\t3. MULTIPLICATION";
   cout<<"\n\t4. DIVISION";
   cout<<"\n\t5. EXIT";
   cout<<"\n\n ENTER YOUR CHOICE ==>";                    //INPUT OF THE DESIRED CHOICE
   cin>>ch;

   switch(ch)
   {

       case 1:
              c.get();
              c.add();        //z=x+y;
              c.put();        //display call
              break;

       case 2:
              c.get();
              c.sub();        //z=x-y;
              c.put();        //display call
              break;

       case 3:
              c.get();
              c.mul();        //z=x*y;
              c.put();        //display call
              break;

       case 4:
              c.get();
              c.div();        //z=x/y;
              c.put();        //display call
              break;

       case 5:
              exit (0);       //direct exit from program

       default:
               cout<<"\n\n\tWRONG CHOICE!!!!!";            //for wrong input

   }

  cout<<"\n\n DO YOU WANT TO CONTINUE ? (Y/n) ==>";
  cin>>cont;

  }while(cont=='Y'||cont=='y');

 return 0;
 }
