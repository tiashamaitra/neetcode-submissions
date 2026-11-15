class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int i;
        for(i=0;i<stones.size();i++)
        {

            while(stones.size()>1)
            {
                sort(stones.begin(),stones.end(),greater<int>());
                
                {
                    if(stones[0]==stones[1])
                    {
                        stones.erase(stones.begin());
                        stones.erase(stones.begin());
                    }
                    
                    
                    
                    else if(stones[0]>stones[1])
                    {
                        stones[0]=stones[0]-stones[1];
                        stones.erase(stones.begin()+1);
                    }
                }
            }
        }
        if(stones.empty())
        {
            return 0;
        }
        return stones[0];


    }
};
