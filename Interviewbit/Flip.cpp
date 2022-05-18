//Problem link - https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    int mx_sum = 0; 
    int local_sum = 0;
    int left = 0, right;
    vector<int> ans(2);

    for( int i = 0; A[i] ; i++ ){//Simple Kadane's algorithm
        
        int num = ( A[i] == '0' ? 1 : -1 ) ;//Flipping 0 will increase '1' by 1 hence +1 and vice versa
        if( local_sum + num >= num )//We put = also here as we are looking for lexicographically smallest pair {left,right}
		{
            local_sum += num;
            right = i;
        }
        else{
            local_sum = num;//time to neglect the left window
            left = right = i;
        }

        if( local_sum > mx_sum ){
            mx_sum = local_sum;
            ans[0] = left+1;
            ans[1] = right+1;
        }

    }

    if( mx_sum < 1 )//No possible flipping in any window could increase number of 1s
        return {};
    return ans;

}
