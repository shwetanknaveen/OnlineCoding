//Problem link - https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void insert(stack<int> &stack,int n)
{
    if(stack.empty() || stack.top()<n)//least element should be at bottom of stack
    {
        stack.push(n);//this is the right place to put the number hence put it and return
        return;
    }
    int top = stack.top();//top of stack which is greater than n, save it in top
    stack.pop();//remove the top
    insert(stack,n);//insert n in stack with remaining elements
    stack.push(top);//push the top again
}
void sortStack(stack<int> &stack)
{
	if(stack.empty() || stack.size()==1)//empty stack or stack with single element is always sorted
        return;
    int top = stack.top();//save the top of stack
    stack.pop();//remove the top
    sortStack(stack);//sort the stack with remaining elements using recursion
    insert(stack,top);//insert the saved top at right place
}

