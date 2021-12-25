//Problem link - https://leetcode.com/problems/permutation-sequence/
//Video link - https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=56


//Approach -1 Using library function next_permutation()
//Time complexity -> O(n*k) Space complexity -> O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
       int arr[n];
        for(int i=1;i<=n;i++)
            arr[i-1] = i;//store the numbers from 1 to n
        for(int i=0;i<(k-1);i++)
            next_permutation(arr,arr+n);//to find kth permutation we have to find (k-1)'th next permutation
        string ans="";
        for(int i=0;i<n;i++)
            ans = ans+to_string(arr[i]);//store the answer in string format
        return ans;
    }
};


//Approach -2 Factorial number system
//Time complexity -> O(n^2) Space complexity -> O(n)

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;//as n<=9 hence fact can be contained in int
        vector<int> numbers;
        for(int i=1;i<n;i++)
        {
            fact *= i;//note here that we are calculating factorial as (n-1)!
            numbers.push_back(i);
        }
        numbers.push_back(n);//n was left to push in the array
        string ans="";
        k=k-1; //as we will be using based indexing
        while(true)
        {
            ans = ans + to_string(numbers[k/fact]);//select the digit
            numbers.erase(numbers.begin() + (k/fact));//remove that digit from the list of numbers
            
            if(numbers.size()==0)//if all numbers from list have been selected then just break the loop
                break;
            
            k=k%fact;//one block of numbers fixing a digit has been selected hence now we have to find (k%fact)th sequence
            fact = fact/numbers.size();//one number has been selected and erased from list of numbers
        }
        return ans;
    }
};
