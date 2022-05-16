//Problem link - https://leetcode.com/problems/lexicographical-numbers/

//Approach 1 -> Using extra space
//Time complexity = O(nlog(n))
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> str;
        for(int i=1;i<=n;i++)
            str.push_back(to_string(i));
        sort(str.begin(),str.end());
        for(string s:str)
            ans.push_back(stoi(s));
        return ans;
    }
};

//Approach 2 -> Without using extra space
//Time complexity = O(nlog(n))
class Solution {
public:
    static bool comparator(int n1,int n2)
    {
        int n = to_string(n1).compare(to_string(n2));
        return n<0?true:false;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(i);
        sort(ans.begin(),ans.end(),comparator);
        return ans;
    }
};

//Approach 3 -> Without extra space
//Time complexity = O(n)
/*
The basic idea is to find the next number to add.
Take 45 for example: if the current number is 45, the next one will be 450 (450 == 45 * 10)(if 450 <= n), or 46 (46 == 45 + 1) (if 46 <= n) 
or 5 (5 == 45 / 10 + 1)(5 is less than 45 so it is for sure less than n).
We should also consider n = 600, and the current number = 499, the next number is 5 because there are all "9"s after "4" in "499" so we 
should divide 499 by 10 until the last digit is not "9".
It is like a tree, and we are easy to get a sibling, a left most child and the parent of any node
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> list;
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            list.push_back(curr);
            if (curr * 10 <= n) //First we we try to have next lexicographical number by appending a 0 on right side
			{
                curr *= 10;
            } 
			else if (curr % 10 != 9 && curr + 1 <= n)//if 0 can't be appended on right side then we try to get next lexicographical number
													//by incrementing number by 1 with same number of digits
			{
                curr++;
            } 
			else 
			{
                while (curr%10 == 9 || curr == n) //We couldn't append 0 and we couldn't add 1 with same number of digits then we reduce 
                								//number of digits
				{
                    curr /= 10;
                }
                curr = curr + 1;//Now we increment it by 1
            }
        }
        return list;
    }
};

