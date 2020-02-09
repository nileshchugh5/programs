/*Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes: book, which adds a page count (type int), and tape, which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with zero values.*/
#include<iostream>
using namespace std;

class publication
{
  protected:
      string title;
      float price;
};

class book:public publication
{
  public:
         int pagecount;


     void getdata()
     {
       try
         { cout<<"--------------------BOOK--------------------\n";
           cout<<"Enter title"<<endl;
           cin>>title;
           cout<<"Enter price"<<endl;
           cin>>price;
           cout<<"Enter Page count"<<endl;
           cin>>pagecount;
           if(pagecount==0)
             throw pagecount;
          }
       catch(int)
          {
           pagecount=0;
           title='0';
           price=0.0;
          }
        }
     void display()
     {
          cout<<"Title==>"<<title<<endl;
          cout<<"Price==>"<<price<<endl;
          cout<<"Pagecount==>"<<pagecount<<endl;
     }
  };

 class tape:public publication
{
    public:
        float playingtime;


     void getdata()
     {
       try
         { cout<<"----------------------------TAPE------------------------\n";
           cout<<"Enter title"<<endl;
           cin>>title;
           cout<<"Enter price"<<endl;
           cin>>price;
           cout<<"Enter Playing Time"<<endl;
           cin>>playingtime;
           if(playingtime<=0)
             throw playingtime;
          }
       catch(float)
          {
           playingtime=0;
           title='0';
           price=0.0;
          }
        }
     void display()
     {
          cout<<"Title==>"<<title<<endl;
          cout<<"Price==>"<<price<<endl;
          cout<<"Playing time==>"<<playingtime<<endl;
     }
  };


  int main()
  {
   char ch;
   do
   {
   book b1;
   tape t1;
   b1.getdata();
   b1.display();
   t1.getdata();
   t1.display();
   cout<<"\nIf you want to continue!!!\nPress y or Y\n";
   cin>>ch;
   }while(ch=='y'||ch=='Y');
   return 0;
  }
