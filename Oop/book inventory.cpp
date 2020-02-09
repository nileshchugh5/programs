/*A book shop maintains the inventory of books that are being sold at the shop. The list includes
details such as author, title, price, publisher and stock position. Whenever a customer wants a
book, the sales person inputs the title and author and the system searches the list and
displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the
system  displays  the  book  details  and  requests  for  the  number  of  copies  required.  If  the
requested copies book details and requests for the number of copies required. If the requested
copies are available, the total cost of the requested copies is displayed; otherwise the message
―Required copies not in stock‖ is displayed. Design a system using a class called books with
suitable  member  functions  and  Constructors.  Use  new  operator  in  constructors  to  allocate
memory space required. Implement C++ program for the system.*/

#include<iostream>
#include<cstring>
using namespace std;
class book
{
   char *publisher;
   int len;
  public:
    int *stock;
    float *price;
    char *author,*title;
    book()
    {
    }
  book(char *p,char *a,char *t,int st,float pr)
  {
     len=strlen(p);
     publisher=new char [len+1];
     strcpy(publisher,p);
     len=strlen(a);
     author=new char [len+1];
     strcpy(author,a);
     len=strlen(t);
     title=new char[len+1];
     strcpy(title,t);
     stock=new int;
     *stock=st;
     price=new float;
     *price=pr;
  }
  void display();
};
void book::display()
{
 cout<<"TITLE:"<<title<<endl<<"AUTHOR:"<<author<<endl<<"PUBLSIHER:"<<publisher<<endl<<"PRICE:"<<*price<<endl<<"STOCK:"<<*stock<<endl;
}
int main()
{
 int z,n,i,cop,flag=0;
 float *p;
 int *s;
 char choice;
 int sto;
 float pri;
 char tit[50],aut[50],a[10],b[10],c[10],ans;
  cout<<"\------------------------------------------------\n";
  cout<<"ENTER HOW MANY ENTRIES YOU WANT TO DO ?";
  cin>>n;
  book *B1=new book[n]; //declaration of objects
  for(i=0;i<n;i++)
  {
    cout<<"\n--------------------------------------\n";
    cout<<"ENTER PUBLISHER==>";
    cin>>a;
    cout<<"ENTER AUTHOR==>";
    cin>>b;
    cout<<"ENTER TITLE==>";
    cin>>c;
    cout<<"ENTER STOCK AVAILABLE==>";
    cin>>sto;
    cout<<"ENTER THE PRICE==>";
    cin>>pri;
    cout<<"\n----------------------------------------\n";
     B1[i]=book(a,b,c,sto,pri);
  }
 for(i=0;i<n;i++)
 {
   cout<<"\n--------------------------------------------\n";
   B1[i].display();
   cout<<"\n--------------------------------------------\n";
 }
 do
 {
   cout<<"\n----------------------------------------------------------------------\n";
   cout<<"ENTER THE TITLE OF THE BOOK WHICH CUSTOMER WANTS ==>";
   cin>>tit;
   cout<<"ENTER AUTHOR OF THE BOOK WHICH CUSTOMER WANTS ==>";
   cin>>aut;
   cout<<"TITLE:"<<tit<<endl<<"AUTHOR:"<<aut<<endl;
   cout<<"\n-------------------------------------------------------------------------\n";
   for(i=0;i<n;i++)
   {
    if(strcmp(tit,B1[i].title)==0&&strcmp(aut,B1[i].author)==0)
    {
      flag=1;
      p=B1[i].price;
      s=B1[i].stock;
      break;
    }
   else
      flag=0;
   }
  if(flag==1)
  {
    cout<<"\n----------------------------------------------------------\n";
    cout<<"BOOK IS AVAILABLE"<<endl;
    cout<<"\n----------------------------------------------------------\n";
    cout<<"ENTER NUMBER OF COPIES REQUIRED"<<endl;
    cin>>cop;
    cout<<"\n----------------------------------------------------------\n";
    z=cop**p;
   if(cop<=*s)
   {
     cout<<"TOTAL AMOUNT IS==>"<<z<<endl;
     cout<<"\n----------------------------------------------------------\n";
   }
   else
   {
     cout<<"COPIES ARE NOT AVAILABLE"<<endl;
     cout<<"\n----------------------------------------------------------\n";
   }
  }
  else
    cout<<"BOOK IS UNAVAILABLE"<<endl;
    cout<<"Do you want to continue..? if yes press y or Y"<<endl;
    cin>>choice;
 }while(choice=='y'||choice=='Y');
 return 0;
}
