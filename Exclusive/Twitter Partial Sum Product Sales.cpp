/*Question -
A product marketer has severeal suppliers of a product. The stock is represensted by an array of quantites for each supplier. As
items are purchased, the supplier raises the price by 1 unit per item purchased, reducing the marketer's profit on any one item 
is the same as the number of those items the supplier has. For example, the supplier has 4 units, the marketer's profit on the
first unit sold is 4, then 3, then 2 ans the last one the profit is 1. Given the array of quantities at suppliers and
the number of items ordered, determine the highest profit that can be generated.
Example inventory = [3,5]
order = 6
Maximum profit will be 19 (=5 + 4 + 3 + 3 + 2 + 2)
Constraint -
inventory[i]<=10^5
*/

#include <bits/stdc++.h>
using namespace std;
const int size = 1e5 + 10;	//inventory[i]<=10^5.	Adding 10 for safty form array out of bound
long maximumProfit(vector<int>& inventory, long order) {
	vector<int> prefix(size, 0);//default is 0. Prefix[i] = number of suppliers which have inventory = i
	for (int e: inventory) ++prefix[e];
	for (int i = size - 2; i > 0; --i) {
		prefix[i] += prefix[i + 1];//In the loop below, when we will select the largest inventory from right most side prefix[i]
								//it's size will reduce by 1 that is it will be i-1 also its number will reduce by 1.
								//We won't look again at this index again hence we move this remaining inventory data to the
								//imediate index of prefix which will be examined  next
	}
	long ans = 0;
	for (int i = size - 1; i > 0 and order > 0; --i) {
		int del = min(1l * prefix[i], order);//We can buy maximum inventory as per our need only
		ans += 1l * del * i;//1l is used to promote RHS to long. Profit from previous buying will be inventory size i.e., 
							// i * (no. of those inventories bought)
		order -= del;		//requirement will be reduced accordingly
	}
	return ans;
}
int32_t main() {
	vector<int> input = {3, 5};
	long order = 6;
	cout << maximumProfit(input, order) << endl;
}
