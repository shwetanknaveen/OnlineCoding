//Problem link - https://www.interviewbit.com/problems/subarray-with-given-xor/
//Video link - https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=26
//Time and space complexity -> O(n)
/*
	LOGIC->
	if curr_XOR ^ Y = B ==>  Y = curr_XOR ^ B
	so if we are counting that how many xors lead to B, we can have those counts which have xor value as curr_XOR ^ B
*/
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> prefXOR_count;//stores count of xor values
    int count = 0;
    int curr_XOR = 0;	// X^0 = X  --> identity
    for(int X : A)
    {
        curr_XOR ^= X;
        if(curr_XOR == B)
        count++;//simply increment count as it is our target value

        if(prefXOR_count.find(curr_XOR^B) != prefXOR_count.end())//this shouldn't be as else part
        {
            count =count + prefXOR_count[curr_XOR^B]; //see in logic part, prefXOR_count[curr_XOR^B] is count of Y
        }
        
        prefXOR_count[curr_XOR]++;
        

    }
    return count++;

}

