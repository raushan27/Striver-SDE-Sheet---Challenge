//Best Time to Buy and Sell Stock
// SDE Sheet Q6

int maximumProfit(vector<int> &prices){
    int lowestPrice = INT_MAX;
    int profit = 0;                 
    int finalProfit = 0;

    for(int i = 0; i<prices.size(); i++){
        if(prices[i] < lowestPrice)
            lowestPrice = prices[i];
        profit = prices[i] - lowestPrice;          //profit if sold that day

        if(profit > finalProfit)
            finalProfit = profit;
    }
    return finalProfit;
}