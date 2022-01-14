//Video link - https://www.youtube.com/watch?v=WjpswYrS2nY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63

/*
TO FIND Nth ROOT OF M UPTO D DECIMAL DIGITS OF PRECISION
Time complexity -> N	*	log(	M	*	10^D)
				for				for d decimal digits
				multiply		,search space is M*10^D
				loop
				
If we are searching for root of 27 upto 1 decimal digit of precision then our search space will be as following
1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 2.0......27.0
total numbers in the search space is M*10 for 1 decimal digit of precision
*/

#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; //for precision upto 5 decimal places
    
    while((high - low) > eps) {//search until search space has reduced to required precision
    						//usually this condition for binary search is as low<=high
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; 
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}
int main() {
	int n, m;
	cin >> n >> m; 
	getNthRoot(n, m); 
	return 0;
}
