//Problem link - https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.

void MyQueue:: push(int x)//functions are declared under MyQueue class
{
        QueueNode *newNode = new QueueNode(x);
        if(!(rear)) {rear=front = newNode; return;}//if this is the first node which is to be inserted in empty queue
        
        rear->next = newNode;//else case
        rear=newNode;//last added node will be new rear node
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(!(front)) return -1;//if queue is empty
    QueueNode *tempNode = front;
    int data = tempNode->data;
    front = front->next;
    if(!front) front = rear = NULL;//if deletion has resulted in empty queue
    free(tempNode);
    return data;
}
