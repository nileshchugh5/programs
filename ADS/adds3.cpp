#include<iostream>
using namespace std;
class node
{
  public:
     node*r;
   node*l;
  int data;

};

class ads3
{
  public:
   node*p;
  node*temp;
node *curr;
  node* root;
    char g,h;
ads3()
{

   root=NULL;
}
  void insert(node*,node*);
void operator=(ads3 b);
void create();
void display(node*);
void insert1(node*,node*);
node* copy(node*);
 void delete1(node*)

};


void ads3::create()
{

  do 
 {
    temp= new node;
    cout<<"Enter the data ";
     cin>>temp->data;
    temp->l=temp->r=NULL;
      if(root==NULL)
        root=temp;
     else
       insert1(root,temp);
     
   cout<<"do u wanna to continue ";
    cin>>g;
   }while(g=='y'); 
}

void ads3::insert1(node*curr,node*temp)
{

      cout<<"where do u wanna to add left or right "<<endl;
      cin>>h;
       if(h=='l')
     {
          if(curr->l==NULL)
            curr->l=temp;
         else
          insert1(curr->l,temp);
  
     }


     else  if(h=='r')
     {
          if(curr->r==NULL)
            curr->r=temp;
         else
          insert1(curr->r,temp);
  
     }


}


   void ads3::display(node *curr)
{
    if(curr!=NULL)
    {

     cout<<curr->data;
     display(curr->l);
     display(curr->r);
    }   


}




void ads3::operator=(ads3 b)
{
   cout<<"tree is ";
  
  this->root=copy(b.root);

}

node* ads3::copy(node*curr)
{

 node* p;
  p=NULL;
 if(curr!=NULL)
 {
  p=new node;
  p->data=curr->data;
  p->l=copy(curr->l);
  p->r=copy(curr->r);
 }
return p;

}

  
void ads3::delete1(node*curr)
{
    if(curr!=NULL)
   {
     delete1(curr->l);
     if(curr->l==NULL && curr->r==NULL)
         delete curr;
     delete1(curr->r);
   }
}
int main()
{

   ads3 y,y1;
   y.create();
   y.display(y.root);
   y1=y;
    y.delete1(y.root);
y1.display(y1.root);
return 0;




}
























