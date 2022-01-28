//Problem link - https://leetcode.com/problems/online-stock-span/

//Just like next greter element, we find here the index of previous smaller element

class StockSpanner {
public:
    stack<int> stocksInd;//increasing stack ->Stores indices of stocks
    vector<int> stocks;//stores incoming stocks
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!stocksInd.empty() && stocks[stocksInd.top()]<=price)//keep on searching for the previous stock having larger value than this
            stocksInd.pop();
        stocks.push_back(price);//this stock is pushed in list of stocks
        int retVal, thisStockInd = stocks.size()-1;
        if(stocksInd.empty()) retVal = thisStockInd - (-1);//previous greater element is at index -1 means nowhere
        else retVal = thisStockInd - stocksInd.top();//previous greater element is at index stokcsInd.top();
        stocksInd.push(thisStockInd);//now this stock is greater in value than previous ones on stocksInd hence pushed
        							//See next greater element question for better understanding
        return retVal;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
