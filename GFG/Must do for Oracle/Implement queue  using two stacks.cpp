//Problem link - https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x) //O(1)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop() //O(N)
{
        // Your Code
        int returnVal;
        if(s1.empty() && s2.empty()) return -1;
        if(!s2.empty()){
            returnVal = s2.top();
            s2.pop();
            return returnVal;
        }
        while(!s1.empty()){
            s2.push(s1.top());//here STL pop() will be called as s1 is stack object
            s1.pop();
        }
        returnVal = s2.top();
        s2.pop();
        return returnVal;
}
