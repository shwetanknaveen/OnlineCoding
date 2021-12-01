//Problem link - https://leetcode.com/problems/intersection-of-two-linked-lists/
//Video link - https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//look at the best solution in the discussion
public:
    int getLength(ListNode *node){
        int count=0;
        while(node)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLength = getLength(headA);
        int bLength = getLength(headB);
        int lenDiff;
        if(aLength>bLength){
            lenDiff = aLength-bLength;
            while(lenDiff)
            {
                headA=headA->next;
                lenDiff--;
            }
            
        }
        if(aLength<bLength){
            lenDiff = bLength-aLength;
            while(lenDiff)
            {
                headB=headB->next;
                lenDiff--;
            }
            
        }
        while(headA&&headB)
        {
            if(headA==headB)
                return headA;
            headA = headA->next;
            headB= headB->next;
        }
        return NULL;
    }
    
    //SOLUTION WITHOUT USING LENGTH OF LISTS
    /*
    class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA|| !headB) return NULL;
    
        ListNode *a = headA;
        ListNode *b = headB;
    
        //if a & b have different len, then the loop will terminate after second iteration
        while( a != b){
    	//for the end of first iteration, we just reset the pointer in such a way to exchange the heads of two lists
        a = a == NULL? headB : a->next;
        b = b == NULL? headA : b->next;    
        }
    
        return a;
    }
};   //see this comment - https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!/165648

	Notice that if list A and list B have the same length, this solution will terminate in no more than 1 traversal; if both 
	lists have different lengths, this solution will terminate in no more than 2 traversals -- in the second traversal, 
	swapping a and b synchronizes a and b before the end of the second traversal.
    */
};
