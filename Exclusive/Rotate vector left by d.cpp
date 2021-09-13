//Question link - https://www.hackerrank.com/contests/iiit-bangalore-1/challenges/array-left-rotation/submissions/code/1336535246

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    vector<int> ans;
    for(int i=0;i<(n-d);i++)
    {
       ans.push_back(arr[d+i]);
    }
    for(int j=0;j<d;j++)
        ans.push_back(arr[j]);
    return ans;
}
/*
IMPORTANT NOTE - When we don't give size of vector in its declaration then we can push_back() in it but we can't do
vect[i]=something as it will give segmentation fault
*/
