/*Write a function template selection Sort.
Write a program that inputs, sorts and
outputs an integer array and a float array.*/
#include<iostream>
using namespace std;
template<class T>
void selsort(T a[],int size)
{
   T temp;
   int i,j,min;
   for(i=0;i<size-1;i++)
   {
      min=i;
     for(j=i+1;j<size;j++)
     {
     if(a[j]<a[min])
       min=j;
     }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
     }

}




int main()
{
	char z;
    int c[100], i,n,ch;
    float d[100];

    do
    {
    cout<<"\nEnter choice:\n1.Sort integer no.s\n2.Sort float no.c\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"Enter The number of Element:\n";
    cin>>n;
    cout<<"\nEnter Elements:\n";
    for(i=0;i<n;i++)
    {

        cout<<"\nEnter:";
        cin>>c[i];
    }
    selsort(c,n);
    cout<<"\nAfter Sorting\n";
    for(i=0;i<n;i++)
    {
       cout<<c[i]<<"\t";
    }
    break;
    case 2:
    cout<<"Enter The number of Element:\n";
    cin>>n;
    cout<<"\nEnter Elements:\n";
    for(i=0;i<n;i++)
    {

        cout<<"\nEnter:";
        cin>>d[i];
    }
    selsort(d,n);
    cout<<"\nAfter Sorting\n";
    for(i=0;i<n;i++)
    {
       cout<<d[i]<<"\t";
    }

    break;
    default:
    cout<<"\nEnter avalid choice!!!!\n";
    break;
    }
    cout<<"\nDo you want to continue!!\nIf yes press y\n";
    cin>>z;
    }while(z=='y'||z=='Y');


    return 0;
}
