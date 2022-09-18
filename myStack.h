template <class Type>
class myStack
{
public:
	myStack();
	myStack(const myStack<Type>&);
	const myStack<Type>& operator=(const myStack<Type>&);
	~myStack();

	void push(const Type&);
	void pop();
	Type top() const;
	bool isEmpty() const;

private:
	struct node
	{
		Type item;
		node * next;
	};

	node * topOfmyStack;
};

/*
Description: sets the top of stack to null
Input: nothing
Output: Nothing
*/
template <class Type>
myStack<Type>::myStack()
{
	topOfmyStack = nullptr;
}

/*
Description: Sets the top of stack to null and copies the tree
Input: The stack calss
Output: returns the stack class
*/
template <class Type>
myStack<Type>::myStack(const myStack<Type>& copy)
{

	topOfmyStack = nullptr;
	*this = copy;
}

/*
Description: copies the stack class
Input: The stack class
Output: this
*/
template<class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& rhs)
{
	//this = rhs
	//list = list
	if (this != &rhs)
	{
		while (!isEmpty())
			pop();
		
		if(!rhs.isEmpty())
		{
			topOfmyStack = new node;
			topOfmyStack->item = rhs.topOfmyStack->item;
			topOfmyStack->next = nullptr;
			topOfmyStack = rhs.topOfmyStack;

			node *copyRHSTemp = rhs.topOfmyStack;
			node *copyTemp = topOfmyStack;
			
			while (copyRHSTemp->next != nullptr)
			{
				node * newNode = new node;
				newNode->item = copyRHSTemp->item;
				newNode = copyRHSTemp;
				copyTemp->next = newNode;
				copyTemp->next->next = nullptr;
			}	
		}
	}
	return *this;
}

/*
Description: De-allocates the stack
Input: Nothing
Output: Nothing
*/
template<class Type>
myStack<Type>::~myStack()
{
	node * stackTemp = topOfmyStack;

	while (stackTemp != nullptr)
	{
		node * current = stackTemp;
		stackTemp = stackTemp->next;
		delete current;
	}

	delete topOfmyStack;
	topOfmyStack = nullptr;
}

/*
Description: Pushes the item into the stack from binary tree
Input: The value from the treee
Output: Nothing
*/
template <class Type>
void myStack<Type>::push(const Type& insert)
{
	//Creates the first node in the stack
	if(isEmpty())
	{
		topOfmyStack = new node;
		topOfmyStack->item = insert;
		topOfmyStack->next = nullptr;
		return;
	}
	
	node * stackTemp = topOfmyStack;
	
	//Transveres the stack until it finds the last point in the stack
	while(stackTemp != nullptr)
	{	
		if (stackTemp == nullptr)
		{
			node * newNode = new node;
			newNode->item = insert;
			newNode->next = nullptr;
			stackTemp = newNode;
			break;
		}
		
		stackTemp = stackTemp->next;
	}
	//Creates the node at the end of the stack
	
	return;
}

/*
Description: Deletes the end of the stack
Input: Nothing
Output: Nothing
*/
template <class Type>
void myStack<Type>::pop()
{
	if (!isEmpty())
	{
		node * stackTemp = topOfmyStack;
		
		while (stackTemp != nullptr)
		{
			if (stackTemp->next == nullptr)
				delete stackTemp;
		}	
		stackTemp = nullptr;
	}
	
	return;
}
/*
Description: returns the value that's in the stack
Input: Nothing
Output: the value that's in the stack
*/
template <class Type>
Type myStack<Type>::top() const
{
	return topOfmyStack->item;
}

/*
Description: Check to see if the top of stack is empty ot nah
Input: Nothing
Output: true or false
*/
template <class Type>
bool myStack<Type>::isEmpty() const
{
	if (topOfmyStack == nullptr)
		return true;
	else	
		return false;
}