#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

template <class type>
struct binTreeNode
{
	type item; //stores the data in the node of the tree
	binTreeNode<type> * left;
	binTreeNode<type> * right;
};

template <class type>
void readLISP(binTreeNode<type>*,  ifstream&);

//binTreeNode<int>* createNode(ifstream&);

template <class type>
bool evaluate(binTreeNode<type>*, int, int, myStack<type>&);

template <class type>
void destroyTree(binTreeNode<type>*);

////////////////////////////////////////////////////////////////////
//Assume that the infile stream is a getline string

/*
Description: Creates the binary tree by taking in the LISP stream from 
the file
Input: The struct and file
Output: Nothing
*/
template <class type>
void readLISP(binTreeNode<type> * r,  ifstream& infile)
{

	char binTreeChar;
	infile >> binTreeChar;
	
	if (binTreeChar == '(')					//If it is a '(' ignore and gets the next char
	{	

		infile >> binTreeChar;				//Gets the number in the stream
		
		if(binTreeChar == ')')				//If the char is ) then set it to null
			r = nullptr;
	}

	if(isdigit(binTreeChar))				//If it is a digit then we create a node
	{
		infile.putback(binTreeChar);		//Putting the char back
		int binTreeNumber;				
		infile >> binTreeNumber;			//grab the int from the stream

		r = new binTreeNode<int>;
		r->item = binTreeNumber;			//Sets the value into the node
		r->left = nullptr;
		r->right = nullptr;	
	}
	
	if(binTreeChar == ')')					//If the char is ) then set it to null
	{	
		//r = nullptr;
		infile >> binTreeChar;				//Grabs the next element on the infile stream
	}		

	if (r != nullptr)
	{						
		readLISP(r->left, infile);			//Go to the left node
		readLISP(r->right, infile);			//Go to the right node
	}	
	//Wasnt able to build the tree so I'm deallocating to
	//to aviod a memory leak
	destroyTree(r);	
	return;	
}

/*
Description: Checks to see if the correct sum is equal to the numbers
in the node
Input: The struct, targeted sum, added sum, and stack
Output: true or false 
*/
template <class type>
bool evaluate(binTreeNode<type> * r, int runningSum, int targetSum, 
	myStack<type>& path)
{
	//Checking to see if there isn't a node created
	if (r == nullptr)
		return false;


	runningSum += r->item;
	path.push(r->item);

	if (runningSum == targetSum)
		return true;

	if (runningSum > targetSum)
	{
		runningSum -= r->item;
		path.pop();
		return false;
	}

	return evaluate(r->left, runningSum, targetSum, path) || evaluate(r->right, runningSum, targetSum, path);
}
/*
Description: De-allocates the tree
Input: The struct
Output: Nothing
*/
template <class type>
void destroyTree(binTreeNode<type> * r)
{
	if (r == nullptr)
		return;

	destroyTree(r->left);
	destroyTree(r->right);

	delete r;
}