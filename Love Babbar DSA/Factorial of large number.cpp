//Problem link - https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

//Approach -1 -> This takes O(N) space
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> multiplicand;
        multiplicand.push_back(1);
        int carry = 0,mult=1,siz;
        vector<int> ans;
        for(int i=2;i<=N;i++)
        {
            siz=multiplicand.size();
            for(int j=siz-1;j>=0;j--)
            {
                mult = multiplicand[j]*i;
                ans.push_back((mult+carry)%10);
                if((mult+carry)>9) carry = (mult+carry)/10;
                else carry = 0;
            }
            while (carry) {//carry which is remaining in last
            ans.push_back(carry % 10);
            carry /= 10;
            }
            reverse(ans.begin(),ans.end());//we stored the ans in reverse order hence reversing it again
            multiplicand = ans;
            ans.clear();
        }
        return multiplicand;
    }
};

//Approach-2 -> This takes O(1) space

class Solution {
public:
     void multiply(int n, vector<int>& number) {//will multiply the number with n from
     											//left to right
        int carry = 0;
        for (int i = 0; i < number.size(); i++) {
            int num = n * number[i];
            number[i] = ((num + carry) % 10);//current digit is updated
            carry = (num + carry) / 10;
        }
        while (carry) {//this is the left out carry after iterating the last digit
            number.push_back(carry % 10);
            carry /= 10;
        }
    }
    vector<int> factorial(int N){
        vector<int> number;
        number.push_back(1);
        for (int i = 2; i <= N; i++) 
            multiply(i, number);
        reverse(number.begin(), number.end());//since multiply is multiplying from
											//left to right hence we are reversing in end 
        return number;
    }
};

