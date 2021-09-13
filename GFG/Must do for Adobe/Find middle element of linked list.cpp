//Problem link - https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1#
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getCount(Node *head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}
int getMiddle(Node *head)
{
   // Your code here
   int middle = (getCount(head)/2);
   while(middle--)
   head=head->next;
   return head->data;
}
