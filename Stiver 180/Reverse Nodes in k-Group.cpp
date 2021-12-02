//Problem link - https://leetcode.com/problems/reverse-nodes-in-k-group/
//Video link - https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=35
//Video is not for recursive approach

//Approach 1 - Iterative approach
class Solution {
public:
    int getLength(ListNode *head)
    {
        if(!head) return 0;
        int len =0;
        while(head)
        {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        
        ListNode *headHolder = new ListNode;
        headHolder->next = head;
        if(!head || k==1) return head;
        ListNode *pre,*curr,*next;
        pre = curr = next = headHolder;
        
        while(len>=k)//deal each group separately
        {
            curr = pre->next;
            next = curr->next;
            for(int i=1;i<k;i++)//for group of k, k-1 links have to be rearranged
            {
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = curr->next;
            }
            pre = curr;
            len -= k;
        }
        
        return headHolder->next;
    }
};

//Approach 2 - Recursive approach	Easy to remember
class Solution {
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL, *next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* divideAndConquor(ListNode *head,int &k)
    {
        if(!head || k==1) return head;
        int num = k;
        ListNode *stored_head = head,*temp;
        
        while(head && --num)//traverse towards the end of the node inside the group
        {
            head = head->next;
        }
        if(num != 0) return stored_head;//this condition happens for the last remaining part which is smaller than k
        								//in that case no change of link has to be done and original head has to be returned
        
        temp = head->next;//temp stores the first node of the next group
        head->next = NULL;//break the connection of this group with the next group
        temp = divideAndConquor(temp,k);//since divideAndConquor() is our hypothesis hence it will solve the task for the remaining part
        head = reverse(stored_head);//now reverse the previous group
        stored_head->next = temp;//stored_head which stored the head of original list will be now last node in the first group
        						//and it should point to the solved part for remaining part of the list
        
        return head;//head will be the new head of final list
        /*
        This can be understood with following example with k=2
        Given list - 	1 -> 2 -> 3
        Ans list - 		2 -> 1 -> 3
        */
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return divideAndConquor(head,k);
    }
};
