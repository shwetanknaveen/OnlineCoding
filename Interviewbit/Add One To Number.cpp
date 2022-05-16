//Problem link - https://www.interviewbit.com/problems/add-one-to-number/
//Little similar question on leetcode - https://leetcode.com/problems/plus-one/
vector<int> Solution::plusOne(vector<int> &A) {
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
    
	for(int i=ans.size()-1;i>=0;i--) //We pop all those insignificant MSB 0s which were in input and which got pushed in ans
    {
        if(ans[i]==0) ans.pop_back();
        else break;//first non zero number found in MSB of ans, so break and stop popping
    }
    if(ans.empty()) ans.push_back(0);//In whole process, if ans becomes empty then it should be 0
    reverse(ans.begin(),ans.end());//We stored ans in reverse order hence we reverse it before returning it back
    return ans;
}
