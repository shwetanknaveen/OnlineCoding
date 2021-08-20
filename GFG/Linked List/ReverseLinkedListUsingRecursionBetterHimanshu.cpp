
//PROBLEM LINK - https://leetcode.com/problems/reverse-linked-list/submissions/
class Solution
{
    public:
    //Function to reverse a linked list.
   
     struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL) return head;
        
        Node *newHead = reverseList(head->next);//Hypothesis - our new head will contain head of reversed list(List minus head)
												// and now our head is with us which needs to be pointed by the reversed list
        Node *tempHead = newHead;
        while(tempHead->next)//travel until last node
        {
        	tempHead=tempHead->next;//with temp head which contains head of reversed list
		}
        
        tempHead->next =  head;//connecting head with the reversed list
        head->next = NULL;//now head should point to NULL
        
        return newHead;//newHead has to be returned in the end
    }
    
};
