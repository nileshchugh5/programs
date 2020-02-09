/*Write a C++ program using command line arguments to search for a word in a file and replace
 *it with specified word. The usage of program is shown below:
 *
 */

//Please save this file with .cpp extension
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(int argc, char *argv[])
{
	int replacecount = 0;

	/*Step 1: Check whether required arguments are present or not
	 * - we are accepting 3 things from commandline - old_word, new_word and
	 *   fileName in which replacement is to be done.
	 * - If argument count (i.e. argc) is < 4 that means some arguments are missing.
	 * - Argument 4 because -
	 *          ./a.out -> argument 0
	 *          old_word -> argument 1
	 *				new_word -> argument 2
	 *				fileName -> argument 3
	 * So, count will be equal to 4. Also, above arguments sequence doesn't matter so can
	 * be adjusted according to our logic.
	 */

	if(argc < 4)
	{
		cout<<"\nSome arguments are missing\n";
		exit(1);
	}

	//Declaring variables for copying arguments
	string old_word;
	string new_word;

	//Copying arguments in our variables
	old_word = argv[1];
	new_word = argv[2];

	//Size of old_word should be equal to replacingString or else terminate
	if(strlen(argv[1])!=strlen(argv[2]))
	{
		cout<<"\nold_word & new_word are not of same length. So replacement not possible.\n";
		exit(1);
	}

	//Declaring Input/Output file object so use fstream class (file_stream class). Here same file will be read and write
	fstream obj1;

	//Opening input file argv[3] in read only and write only mode using open() member function of fstream class
	obj1.open(argv[3],ios::in | ios::out);

	//Doing Error Handling. If file not found then throw error and terminate the program
	if(!obj1)
	{
		cout<<"\nInput File not Found\n";
		exit(1);
	}

	//Declaring "fetchedWord" variable of type string to store the word fetched from input file

           string fetchedWord;

	// Infinite Loop. Read until reading is possible
	while(1)
	{
		//Check if we reached to end of file or not. If end of file it returns non-zero value
		if(obj1.eof()!=0)
		{
			break;
		}
		else
		{
			//Getting position of input pointer
			int pos = obj1.tellg();

			//Copy read data to "fetchedWord" variable

                               obj1>>fetchedWord;

			//Comparing fetchedWord and old_word word
			if(fetchedWord==old_word)
			{
			     if(pos==0)
			     {

				//incrementing output file pointer to pos
				obj1.seekp(pos);
				obj1<<new_word;
				replacecount++;
				}
				else
				{
				obj1.seekp(pos+1);
				obj1<<new_word;
				replacecount++;
				//start replacing from that position
				}
			}
		}
	}

	//Checking how many places replaced
	if(replacecount==0)
	{
		cout<<"\nZero Match Found. No replacement done\n";
	}
	else
	{
		cout<<"\nSuccessfully replaced old_word with new_word at "<<replacecount<<"positions\n";
	}


	//Closing file
	obj1.close();

	return 0;
}



/*How to execute Code?
 *Please take care that your input file is present with some data
 *way to execute -
 *Way 1: $g++ Program5.cpp
			$./a.out Rahul Priya inputFile.txt


*/
