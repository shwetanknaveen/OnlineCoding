
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
        
        Node *newHead = reverseList(head->next);//Hypothesis - newHead will contain the head of the reversed list
        										//that reversed list will not have head
        head->next->next =  head; //connecting head with the reversed list
        
        head->next =  NULL;//now the end of the reversed list which was preveiously head should point to NULL
        
        return newHead;//in end the newHead should be returned
    }
    
};
