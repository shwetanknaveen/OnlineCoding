
//PROBLEM LINK - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
class Solution
{
    public:
    //Function to reverse a linked list.
   
     struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL) return head;
        
        Node *newHead = reverseList(head->next);
        head->next->next =  head;
        
        head->next =  NULL;
        
        return newHead;//each time newHead will contain the last node
                       //which will be the newHead in reversed linked list
    }
    
};
