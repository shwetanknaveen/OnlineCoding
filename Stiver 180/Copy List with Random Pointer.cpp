//Problem link - https://leetcode.com/problems/copy-list-with-random-pointer/
//Video link - https://www.youtube.com/watch?v=VNf6VynfpdM

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        Node *newHeadHolder = new Node(0);
        while(temp)//first traversal for inserting new list's nodes inbetween nodes of original list
        {
            Node *newNode = new Node(0);
            newNode->next = temp->next;
            newNode->val = temp->val;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;//reassigning temp with original head
        
        while(temp)//second traversal for setting random pointers.Now we have doubled the length of linked list
        			//and we will be stepping with step size of 2 hence if temp exist, temp->next must exist so no need for
        			//null check of temp->next separately
        {
            if(temp->random != NULL)
            {
            temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        temp = head;//reassigning temp with original head
        newHeadHolder->next = (temp != NULL) ? temp->next : NULL;//if original list wasn't empty then atleast one new node in
        														//the copy linked list must have been created which should be
        														//made head;
        
        Node *traveller = newHeadHolder;
        while(temp)//third traversal to gain the original list again
        {
            traveller->next = temp->next;
            temp->next = temp->next->next;
            traveller = traveller->next;
            temp = temp->next;
        }
        
        return newHeadHolder->next;
    }
};
