/*Title: Use STL to create a set and perform operations on it*/
/*Name: Prabodh Wankhede
Roll No.: 57
SE(B)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;
int main()
{
	vector<int> first, second, vec;
	int x, ch, t;
	while(true)
	{
		cout<<"\n1. Enter elements in first set"<<endl;
		cout<<"2. Search element in first set"<<endl;
		cout<<"3. Delete element from first set"<<endl;
		cout<<"4. Size of first set"<<endl;
		cout<<"5. Display first set"<<endl;
		cout<<"6. Enter element in second set"<<endl;
		cout<<"7. Search element in second set"<<endl;
		cout<<"8. Delete element in second set"<<endl;
		cout<<"9. Size of second set"<<endl;
		cout<<"10. Display second set"<<endl;
		cout<<"11. Union of both sets"<<endl;
		cout<<"12. Intersection of both sets"<<endl;
		cout<<"13. Difference of both sets"<<endl;
		cout<<"14. Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<"Enter no. of elements: ";
				cin>>t;
				while(t--)
				{
					cout<<"Enter element: ";
					cin>>x;
					first.push_back(x);
				}
				sort(first.begin(), first.end()); break;
		case 2: cout<<"Enter element: "; cin>>x;
				if(binary_search(first.begin(), first.end(), x))
					cout<<"Found"<<endl;
				else
					cout<<"Not Found"<<endl;
				break;
		case 3: cout<<"Enter element: "; cin>>x;
				first.erase(remove(first.begin(), first.end(), x), first.end());
				break;
		case 4: cout<<first.size(); break;
		case 5:
				for(int i=0; i<first.size(); i++)
					cout<<first[i]<<" ";
				break;
		case 6: cout<<"Enter no. of elements: ";
				cin>>t;
				while(t--)
				{
					cout<<"Enter element: ";
					cin>>x;
					second.push_back(x);
				}
				break;
		case 7: cout<<"Enter element: "; cin>>x;
				if(binary_search(second.begin(), second.end(), x))
					cout<<"Found"<<endl;
				else
					cout<<"Not Found"<<endl;
				break;
		case 8: cout<<"Enter element: "; cin>>x;
				second.erase(remove(second.begin(), second.end(), x), second.end());
				break;
		case 9: cout<<second.size(); break;
		case 10:
				for(int i=0; i<second.size(); i++)
					cout<<second[i]<<" ";
				break;
		case 11:
			set_union(first.begin(), first.end(), second.begin(), second.end(), back_inserter(vec));
			sort(vec.begin(), vec.end());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
			cout<<"\nUnion: ";
			for(int i=0; i<vec.size(); i++)
				cout<<vec[i]<<" ";
			vec.clear();
			break;
		case 12:
			set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(vec));
			sort(vec.begin(), vec.end());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
			cout<<"\nIntersection: ";
			for(int i=0; i<vec.size(); i++)
				cout<<vec[i]<<" ";
			vec.clear();
			break;
		case 13:
			set_difference(first.begin(), first.end(), second.begin(), second.end(), back_inserter(vec));
			sort(vec.begin(), vec.end());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
			cout<<"\nDifference: ";
			for(int i=0; i<vec.size(); i++)
				cout<<vec[i]<<" ";
			vec.clear();
			break;
		case 14: exit(1); break;
		}
	}
	return 0;
}

/*

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
1
Enter no. of elements: 5
Enter element: 5
Enter element: 10
Enter element: 15
Enter element: 20
Enter element: 25

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
2
Enter element: 25
Found

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
2
Enter element: 30
Not Found

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
3
Enter element: 30

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
3
Enter element: 25

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
4
4
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
5
5 10 15 20
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
6
Enter no. of elements: 5
Enter element: 10
Enter element: 20
Enter element: 30
Enter element: 40
Enter element: 50

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
7
Enter element: 50
Found

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
8
Enter element: 50

1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
9
4
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
10
10 20 30 40
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
11

Union: 5 10 15 20 30 40
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
12

Intersection: 10 20
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
13

Difference: 5 15
1. Enter elements in first set
2. Search element in first set
3. Delete element from first set
4. Size of first set
5. Display first set
6. Enter element in second set
7. Search element in second set
8. Delete element in second set
9. Size of second set
10. Display second set
11. Union of both sets
12. Intersection of both sets
13. Difference of both sets
14. Exit
14
*/
