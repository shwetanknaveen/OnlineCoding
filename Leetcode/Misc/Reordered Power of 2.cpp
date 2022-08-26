//Problem link - https://leetcode.com/problems/reordered-power-of-2/

//Apporach 1 -> Checking all permutations

class Solution {
public:
    void solve(string &num,int ind,int &maxPwrVal,bool &ans)
    {
        if(ind>=num.size()) return;
        if(ans) return;//already found that num can be rearranged and made into a power of 2 number
        if(maxPwrVal%stoi(num)==0)
        {
            ans = true;
            return;
        }
        for(int i=ind;i<num.size();i++)
        {
            if(ind==0 && num[i]=='0') continue;//0 can't come at left most place
            swap(num[ind],num[i]);
            solve(num,ind+1,maxPwrVal,ans);
            swap(num[ind],num[i]);
        }
    }
    bool reorderedPowerOf2(int n) 
    {
        int maxPwr = log(INT_MAX)/log(2);
        int maxPwrVal = pow(2,maxPwr);
        bool ans = false;
        string num = to_string(n);
        solve(num,0,maxPwrVal,ans);
        return ans;
    }
};

//Approach 2 -> Check each power of 2 and see that it has digits as in n itself then it can certainly be rearranged in that 
//required order

class Solution {
public:
    bool haveSameDigits(vector<int> digitsCount,int num)
    {
        while(num)
        {
            digitsCount[num%10]--;
            num /= 10;
        }
        for(int i:digitsCount)
        {
            if(i != 0) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> digitsCount(10,0);
        while(n)//Save all the digits in n
        {
            digitsCount[n%10]++;
            n /= 10;
        }
        for(int i=0;;i++)
        {
            long num = pow(2,i);
            if(num>INT_MAX) break;
            if(haveSameDigits(digitsCount,num)) return true;
        }
        return false;
    }
};
