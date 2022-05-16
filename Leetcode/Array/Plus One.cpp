//Problem link - https://leetcode.com/problems/plus-one/
//Little complicated variant on interviewbit - https://www.interviewbit.com/problems/add-one-to-number/
class Solution {
public:
    vector<int> plusOne(vector<int>& A) 
	{
	    vector<int> ans;
	    int carry = 1;
	    for(int i = A.size()-1;i>=0;i--)
	    {
	        int val = A[i] + carry;
	        carry = val/10;
	        ans.push_back(val%10);
	        if(carry==0)//if carry at any stage is 0 then we simply push all remaining digits on left side of A
	        {
	            i--;//first move to left of present digit
	            while(i>=0)
	            {
	                ans.push_back(A[i]);
	                i--;
	            }
	            break;//after pushing all remaining digits, break out
	        }
	    }
	    if(carry) ans.push_back(carry);//if all digits have been looked out and there is still carry for e.g., 9999 will have carry 1 in the end
	    							//then we push that carry in the last
	
	    reverse(ans.begin(),ans.end());//We stored ans in reverse order hence we reverse it before returning it back
	    return ans;
    }
};
