/*

*/


class Solution {
public:
    

    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
        {
            return 0;
        }
        
        int currentMin = prices[0];
        int currentMax = 0;
        
        
        for(int i = 1; i < prices.size(); i++)
        {
            
            
            if(prices[i] < currentMin)
            {
                currentMin = prices[i];
            }
            else if(prices[i] - currentMin > currentMax)
            {
                currentMax = prices[i] - currentMin;
            }
        }
        
        return currentMax;
    
    }
    
    
};