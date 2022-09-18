/*
Name: David Navarro 5004269642 assigment 5 section 1003 
Description: User inputs a file that creates a binary tree based on LISP
format. Then transvere the tree to find the right path that equals the 
running sum from the file to the tree. Then outputs the number/path
from the tree. Then closes the file.
Input: File
Output: The correct path for the runnining sum
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
#include "binaryTree.h"
using namespace std;


int main()
{
	myStack<int> binTreeStack;		//Stack Variable
	ifstream infile;				//var for files
	string fileName;				//String to get the input
	int sumValue;					//targeted sum in eval function
	int sumCombineValues = 0;		//runningSum in eval function
	bool isSumThere;				//T or F in Eval function
	
	
	cout << "Enter the LISP file: ";
	getline(cin, fileName);

	while (fileName != "L_input.txt")
	{
		cout << "Enter the LISP file: ";
		getline(cin, fileName);
	}
	
	infile.open(fileName);

	//This is the running sum for the evaluate function
	infile >> sumValue;

	while (!infile.eof())
	{
		binTreeNode<int> * root = nullptr;		//Creates the first node in the list		
	
		readLISP(root, infile);
		//checks if there is a targeted sum
		isSumThere = evaluate(root, sumCombineValues, sumValue, binTreeStack);
		//If true, then prints out it if not prints "cannot be found" and skips for next line
		if(!isSumThere)
		{
			cout << "There is a path that exist which equals: " << sumValue << endl;
			while(!binTreeStack.isEmpty())
			{
				//Get's the value on the stack
				cout << binTreeStack.top() << " + ";
				//Pop stack for next value
				binTreeStack.pop();
			}	

			cout << "= " << sumValue << endl;
		}
		else
			cout << "No path is found for to equal: " << sumValue << endl;
		//Destory tree for next creation of the tree
		destroyTree(root);
		infile >> sumValue;	
		cout << endl;
		//casuing a infintie loop
		break;
	}
	
	infile.close();
	return 0;
}

