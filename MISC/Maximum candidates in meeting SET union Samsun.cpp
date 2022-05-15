/*
A one-day-long training session will be conducted twice during next 10 days. There are N employees (numbered from 0 to N-1) willing
to attend it. Each employee has provided a list of which of the next 10 days they are able to participate in the training. The employees' 
preferences are represented as an array of strings. E[K] is a string consisting of digits('0'-'9') representing the days the K-th employee
is able to attend the training. 
The dates during which the training will take place are yet to be scheduled.What is the maximum number of employees that can attend during
at least one of the two scheduled days?
E.g., E= ["039","4","14","32","34","7"], the answer is 5. It can be achived for example by running training on days 3 and 4. This way employees
number 0,1,2,3 and 5 will attend the training.
*/

int solution(vector<string> &E) {
    int n = E.size();
    unordered_map<int, vector<int> > m2;
    for(int i=0; i<n; i++) {
        int len = E[i].length();
        for(int j=0; j<len; j++) {
            int c = E[i][j] - '0';
            m2[c].push_back(i);
        }
    }
    int ans = 0;
    for(int i=0; i<10; i++) {//making union of all combination of two days
        for(int j=i+1; j<10; j++) {
            int size1 = m2[i].size();
            int size2 = m2[j].size();
            vector<int> v(size1 + size2);
            int size = set_union(m2[i].begin(), m2[i].end(), m2[j].begin(), m2[j].end(), v.begin()) - v.begin();
            ans = max(ans, size);
        }
    }
    return ans;
}


