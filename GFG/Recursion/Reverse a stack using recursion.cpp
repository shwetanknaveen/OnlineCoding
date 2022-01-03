//Problem link - https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

// C++ code to reverse a
// stack using recursion
#include<bits/stdc++.h>
using namespace std;

stack<char> st;

// initializing a string to store
// result of reversed stack
string ns;

void insert_at_bottom(char x)
{

	if(st.size() == 0)
	st.push(x);//if reached at bottom then simply insert and return. Here return is implicit

	else	//if bottom is not reached yet
	{		
		char a = st.top();//store the top
		st.pop();//remove the top
		insert_at_bottom(x);//insert at bottom in the remaining stack
		st.push(a);//push back the stored top while returning to same level of recursion call
	}
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
	if(st.size()==0) return;//if there is nothing on stack then simply return as there is nothing to reverse
	
	char x = st.top();//store the top
	st.pop();//remove the top
	reverse();//hypothesis-> it will remove the stack after top has been removed
	
	insert_at_bottom(x);	//insert the stored top in reversed stack
		
		
}

// Driver Code
int main()
{
	
	// push elements into
	// the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	
	cout<<"Original Stack"<<endl;
	
	// print the elements
	// of original stack
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl;
	
	// function to reverse
	// the stack
	reverse();
	cout<<"Reversed Stack"
		<<endl;
	
	// storing values of reversed
	// stack into a string for display
	while(!st.empty())
	{
		char p=st.top();
		st.pop();
		ns+=p;
	}
	
	//display of reversed stack
	cout<<ns[3]<<" "<<ns[2]<<" "
		<<ns[1]<<" "<<ns[0]<<endl;
	return 0;
}


