//Problem link - https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.

//HERE PUSH IS MADE IN O(1) AND POP IS MADE IN O(N). 
//IT CAN BE OTHER WAY AROUND
//USE PEN AND PAPER WITH SAMPLE INPUT 1,2,3,4 TO UNDERSTAND ITS WORKING
void QueueStack :: push(int x) //O(1)
{
        // Your Code
        q1.push(x);//here stl push function will be called as q1 is queue object
        
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()// O(N)
{
        // Your Code
        if(q1.empty()) return -1;
        queue<int> temp;
        int q1Len = q1.size();
        while(q1Len>1){
            q2.push(q1.front());
            q1.pop();
            q1Len--;
        }
        int returnVal = q1.front();
        q1.pop();
        //Now swap q1 and q2
        temp = q1;
        q1 = q2;
        q2 = temp;
        return returnVal;
}

/*
void push(int x) //O(N)
    {
        // Push x first in empty q2
        q2.push(x);
  
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
  
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
  
    int pop()  //O(1)
    {
  
        // if no elements are there in q1
        if (q1.empty())
            return -1;
        int returnValue = q1.front();
        q1.pop();
        return returnValue;
    }
  
*/
