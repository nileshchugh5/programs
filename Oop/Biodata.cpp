/*Create employee bio-data using following classes
i) Personal record
ii))Professional record
iii) Academic record
Assume appropriate data members and member function to accept required data & print bio-data.
Create bio-data using multiple inheritance using C++.*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class personal
   {
     protected:
     string name,address,dob,email,contact;
     public:
       void prsnl_info();

   };
   class professional
     {
       protected :
         string company_name,company_address,office_no,experience;
       public:
         void professional_info();
     };
    class academics
      {
        protected :
          string qualification,university_name;
          int passing_year;
          float sgpa;
        public:
            void academics_info();

      };
     class info: public personal,public professional,public academics
       {
          public:
            void display();
       };
     void personal::prsnl_info()
       {
         cout<<"--------------------------------------Personal_Info----------------------------------------------------------------\n";
         cout<<"Enter your name ::";
         getline(cin,name);
         cout<<"Enter your Address ::";
         getline(cin,address);
         cout<<"Enter your DOB ::";
         getline(cin,dob);
         cout<<"Enter your email ::";
         getline(cin,email);
         cout<<"Enter your Contact no ::";
         getline(cin,contact);

       }

     void professional::professional_info()
       {
            cout<<"--------------------------------------Professional_Data----------------------------------------------------------------\n";
         cout<<"Enter your Company Name ::";
         getline(cin,company_name);
         cout<<"Enter your Company address ::";
         getline(cin,company_address);
         cout<<"Enter your Office no ::";
         getline(cin,office_no);
         cout<<"Enter your Experience ::";
         getline(cin,experience);

       }

      void academics::academics_info()
       {
            cout<<"--------------------------------------Academics_Data----------------------------------------------------------------\n";

         cout<<"Enter your qualification ::";
         getline(cin,qualification);
         cout<<"Enter your University name ::";
         getline(cin,university_name);
         cout<<"Enter your Year of Passing ::";
         cin>>passing_year;
         cout<<"Enter your Percentage(sgpa) ::";
         cin>>sgpa;
         cout<<endl;

       }

      void info::display()
       {
          cout<<"---------------------------------------**Biodata**-------------------------------------------------------\n";
          cout<<"--------------------------------------Personal_Info----------------------------------------------------------------\n";
          cout<<setw(50)<<"Name of student :: "<<name<<endl;
          cout<<setw(50)<<"Address :: "<<address<<endl;
          cout<<setw(50)<<"Email :: "<<email<<endl;
          cout<<setw(50)<<"Dob :: "<<dob<<endl;
          cout<<setw(50)<<"Contact no ::"<<contact<<endl;
          cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
          cout<<"--------------------------------------Professional_Data----------------------------------------------------------------\n";
          cout<<setw(50)<<"Company Name :: "<<company_name<<endl;
          cout<<setw(50)<<"Office address :: "<<company_address<<endl;
          cout<<setw(50)<<"Office no ::"<<office_no<<endl;
          cout<<setw(50)<<"Experience :: "<<experience<<endl;
          cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
          cout<<"--------------------------------------Academics_Data----------------------------------------------------------------\n";
          cout<<setw(50)<<"Qualification :: "<<qualification<<endl;
          cout<<setw(50)<<"University name ::"<<university_name<<endl;
          cout<<setw(50)<<"Passing Year ::"<<passing_year<<endl;
          cout<<setw(50)<<"Sgapa ::"<<sgpa<<endl;
          }

      int main()
       {

       info i;
       i.prsnl_info();
       i.professional_info();
       i.academics_info();
       i.display();
       return 0;


       }
