//Problem link - https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1/#

/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//TO REMEMBER WHEN TO CHECK FIRST AND WHEN TO INCREMENT FIRST => We can judge on the initial condition on front=rear=0
//Here nothing is to pop hence we need to check first while dequing

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    rear = (rear+1)%(100005);//while enquing we first increase then check
    if(rear==front)
    {
        if(rear=0)
        {
            rear = 100004;
        }
        else
        {
            rear = rear-1;
        }
        return;
    }
    arr[rear] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear) return -1;//while dequing we first check then increase front
    return (arr[(++front)%100005]);
}



