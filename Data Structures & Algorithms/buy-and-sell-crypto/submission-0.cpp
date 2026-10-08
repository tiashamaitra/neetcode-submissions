class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i;
        int maxi=INT_MIN;
        int maxiprofit=0;
        for(i=n-1;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            maxiprofit=max(maxiprofit,maxi-prices[i]);
        }
        if(maxiprofit<=0)
        {
            return 0;
        }
        return maxiprofit;
    }
};
