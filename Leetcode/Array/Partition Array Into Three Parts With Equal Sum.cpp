//Problem link - https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
//See also "Interviewbit/Partitions" -> https://www.interviewbit.com/problems/partitions/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& B) {
        int n = B.size();
        int totalSum = 0;
        for(int i:B)
         totalSum+=i;

        if(totalSum%3 != 0) return false;//if Total sum itself is not divisible by 3 then obviously it can't be partitoned in three equal parts
        vector<int> prefSum(n,0);
        prefSum[0] = B[0];
        for(int i=1;i<n;i++)
            prefSum[i] = prefSum[i-1] + B[i];
		//We only look that first two parts have their sum as 1/3 of total sum and thirs part will automatically have sum = 1/3 totalSum
        for(int i=0;i<n-2;i++)//We go upto n-3 only as we have to leave at least 2 elements ahead so that possiblity of other two parts exist
        {
            if(prefSum[i]==totalSum/3)//if first part has sum equal 1/3 of total then we start looking for 2nd part
            {
                for(int j=i+1;j<n-1;j++)//We go upto n-2 only as we leave at least 1 element so that possibility of third part exist
                {
                    if(prefSum[j]==2*(totalSum/3)) return true;//if second part has prefix sum = 2/3 of total sum, as it includes sum of first 
                												//part also then it is a possible combination
                }
            }
        }
        return false;//No possible combination was found

    }
};
