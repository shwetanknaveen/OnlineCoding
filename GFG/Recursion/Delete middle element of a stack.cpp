//Problem link - https://www.geeksforgeeks.org/delete-middle-element-stack/
//Video link - https://www.youtube.com/watch?v=oCcUNRMl7dA&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=8

// C++ code to delete middle of a stack
// without using additional data structure.
#include<bits/stdc++.h>
using namespace std;

// Deletes middle of stack of size
// n. Curr is current item number
void solve(stack<char> &s,int mid)
{
    if(mid==1)//middle element is at the top of stack at this moment
    {
        s.pop();
        return;
    }
    int temp = s.top();//middle element is not yet at the top of stack. Hence store current top of stack
    s.pop();//pop it
    solve(s,mid-1);//solve for remaining stack with mid value as (mid-1)
    s.push(temp);//push back the stored value when recursion call returns to this level
}

void deleteMid(stack<char> &s,int size)
{
    if(size==0) return;
    int mid = size/2 + 1;
    solve(s,mid);
}
//Driver function to test above functions
int main()
{
	stack<char> st;

	//push elements into the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	st.push('5');
	st.push('6');
	st.push('7');

	deleteMid(st, st.size());

	// Printing stack after deletion
	// of middle.
	while (!st.empty())
	{
		char p=st.top();
		st.pop();
		cout << p << " ";
	}
	return 0;
}

