/*Title: Create a telephone directory and perform operations on it/*Name: Prabodh Wankhede
Roll No.: 57
SE(B)
*/
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 5
typedef long long int ll;
int currSize = 0;
class DataItem
{
public:
	string name;
	ll data;
};
DataItem HT[SIZE];
int hashCode(ll key)
{
	return key % SIZE;
}
void Display()
{
	for(int i=0; i<SIZE; i++)
		cout<<HT[i].name<<"->"<<HT[i].data<<endl;
}
void Insert(string name, ll phone)
{
    int hashKey = hashCode(phone);
    while(HT[hashKey].data != 0)
    {
        hashKey += 1;
        hashKey %= SIZE;
        if(currSize == SIZE)
        {
        cout<<"\nHash Table Overflow"<<endl;
        return;
        }
    }
    HT[hashKey].name = name;
    HT[hashKey].data = phone;
    currSize += 1;
}
void Delete(ll phone)
{
	int hashKey = hashCode(phone);
	for(int i=0; i<SIZE; i++)
	{
		if(HT[i].data == phone)
		{
			HT[hashKey].name = "";
    		HT[hashKey].data = 0;
    		currSize -= 1;
    		return;
		}
	}
	cout<<"\nContact not present"<<endl;
}
void Search(ll phone)
{
	int hashKey = hashCode(phone);
	for(int i=0; i<SIZE; i++)
	{
		if(HT[i].data == phone)
		{
			cout<<HT[hashKey].name<<": "<<HT[hashKey].data<<endl;
    		return;
		}
	}
	cout<<"\nContact not found"<<endl;
}
int main()
{
	string name;
	int ch;
	ll phone;
	while(true)
	{
		cout<<"\n1. Insert Contact"<<endl;
		cout<<"2. Display all Contacts"<<endl;
		cout<<"3. Search Contact"<<endl;
		cout<<"4. Delete Contact"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter name: ";
			cin>>name;
			cout<<"Enter contact no.: ";
			cin>>phone;
			Insert(name, phone); break;
			case 2: Display(); break;
			case 3: cout<<"Enter contact no.: ";
			cin>>phone;
			Search(phone); break;
			case 4: cout<<"Enter contact no.: ";
			cin>>phone;
			Delete(phone); break;
			case 5: exit(1); break;
		}
	}
    return 0;
}
/*

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Prabodh
Enter contact no.: 7276396824

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Richard
Enter contact no.: 9649916856

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Jared
Enter contact no.: 9876543210

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 2
Jared->9876543210
Richard->9649916856
->0
->0
Prabodh->7276396824

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Gilfoyle
Enter contact no.: 1234567890

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Dinesh
Enter contact no.: 4853294565

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 1
Enter name: Erlich
Enter contact no.: 6656443890

Hash Table Overflow

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 2
Jared->9876543210
Richard->9649916856
Gilfoyle->1234567890
Dinesh->4853294565
Prabodh->7276396824

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 3
Enter contact no.: 9649916856
Richard: 9649916856

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 4
Enter contact no.: 7276396824

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 2
Jared->9876543210
Richard->9649916856
Gilfoyle->1234567890
Dinesh->4853294565
->0

1. Insert Contact
2. Display all Contacts
3. Search Contact
4. Delete Contact
5. Exit
Enter choice: 5
*/
