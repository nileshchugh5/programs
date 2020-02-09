#include<iostream>
#include<string.h>
using namespace std;
class node
{
  public: 
     node *l;
     node *r;
     char data[20],meaning[20];
     

};


class dicti
{
  public:
     void create();
     void display(node*);
     char a;
  
     void insert1(node*,node*);
     node*temp;
     node*root;
     node*curr;
      dicti()
      {
         temp=root=NULL;
      }

};

void dicti::create()
{
do
{
   temp=new node;
   cout<<" Enter the data "<<endl;
   cin>>temp->data;
  
   cout<<" Enter the meaning "<<endl;
   
     cin>>temp->meaning;
      if(root==NULL)
          root=temp;
      else
      {
        insert1(root,temp);
       
      }
      
   cout<<"do i wanna to continue ";
   cin>>a;   
 }while(a=='y');     
}

void dicti::insert1(node *curr,node *temp)
{
 
  
  if(strcmp(curr->data,temp->data)==0)
      cout<<"u cant add "<<endl;
  else
      if(strcmp(curr->data,temp->data)<0)
      {
         if(curr->l==NULL)
          curr->l=temp;
       else
          insert1(curr->l,temp);
     }
     
     else
     {
      if(strcmp(curr->data,temp->data)>0)
      {
         if(curr->r==NULL)
          curr->r=temp;
       else
          insert1(curr->r,temp);
     
     
      }
   }
}

void dicti::display(node*curr)
{

   if(curr!=NULL)
   {
    display(curr->l);
   cout<<curr->data<<" : "<<curr->meaning<<endl;
    display(curr->r);
   }






}

int main()
{
dicti d;
d.create();
d.display(d.root);	
  return 0;



}

