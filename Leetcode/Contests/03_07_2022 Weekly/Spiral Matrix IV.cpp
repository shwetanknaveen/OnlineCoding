//Problem link - https://leetcode.com/problems/spiral-matrix-iv/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int startRow = 0,endRow = m-1,startCol = 0,endCol = n-1;
        while(head)
        {
            for(int i=startCol;i<=endCol;i++)
            {
                if(!head)
                {
                    return ans;
                }
                ans[startRow][i] = head->val;
                head = head->next;
            }
            startRow++;
            for(int i=startRow;i<=endRow;i++)
            {
                if(!head)
                {
                    return ans;
                }
                ans[i][endCol] = head->val;
                head = head->next;
            }
            endCol--;
            for(int i=endCol;i>=startCol;i--)
            {
                if(!head)
                {
                    return ans;
                }
                ans[endRow][i] = head->val;
                head = head->next;
            }
            endRow--;
            for(int i=endRow;i>=startRow;i--)
            {
                if(!head)
                {
                    return ans;
                }
                ans[i][startCol] = head->val;
                head = head->next;
            }
            startCol++;
        }
        
        
        return ans;
    }
};
