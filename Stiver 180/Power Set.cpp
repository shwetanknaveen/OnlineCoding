//Problem link - https://practice.geeksforgeeks.org/problems/power-set4302/1#
//Video link - https://www.youtube.com/watch?v=b7AYbpM5YrE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=68

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n=s.length();
		    vector<string> ans;
		    for(int num=0;num<(1<<n);num++)//num is 0 to (2^n - 1)
		    {
		        string thisString;
		        for(int i=0;i<n;i++)
		        {
		            if(num&(1<<i))//is ith bit set in num -> ith bit means ith bit with 0 based indexing/counting from right
		            {
		                thisString += s[i];//since i is increasing from 0 to n-1 hence it will select characters from left
		                					//to right
		            }
		        }
		        if(!thisString.empty())
		        ans.push_back(thisString);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
