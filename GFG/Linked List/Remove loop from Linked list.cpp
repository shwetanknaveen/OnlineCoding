//Problem Link - https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

/*structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    //given in solution method 3( in editorial of this page on GFG)
    void breakConnectionMethodThree(Node *slow /*head*/, Node *fast)
    {
        //we should check first if all nodes are in the loop itself
        //in this case meeting would have been at head node itself
        if(slow==fast)//we passed slow = head
        {
            while(fast->next!=slow) {
                fast=fast->next;//here only one pointer moves at speed of 1
            }
            fast->next = NULL;
            return;
        }
        
        //now for the case when meeting is not at head node
        while(slow->next!=fast->next)//in this case both will meet from where the cycle is connected
        {
            slow = slow->next;//here both move at-
            fast = fast->next;//-speed of 1
        }
        fast->next=NULL;
    }
    //my function
    void breakConnection(Node *node)
    {
        while(node)
        {
            if(node->next->data<0) {
                node->next=NULL;
                return;
            }
            node->data*=-1;
            node=node->next;
        }
    }
    void removeLoop(Node* head)
    {
        if(!head || !(head->next)) return;
        Node *fast = new Node(1);
        Node *slow = new Node(1);
        slow = fast = head;
        slow = slow->next;
        fast = fast->next->next;
        while(slow && fast)
        {
            if(slow==fast)//it means the loop is present
            {
                breakConnectionMethodThree(head,fast);
                break;
            }
            if(slow) slow=slow->next;
            if(fast) fast=fast->next;
            if(fast) fast=fast->next;
        }
    }
};
