//Problem link - https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1#

//Function to push an integer into the stack.
int arr[100];
int top=-1;
void MyStack :: push(int x)
{
    if(top==99)
    return;
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1) return -1;
    return arr[top--];
}

