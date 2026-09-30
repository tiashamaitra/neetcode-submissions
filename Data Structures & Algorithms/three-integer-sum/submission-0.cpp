class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int i;
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        //[-4,-1,-1,0,1,2]
        for(i=0;i<n;i++)
        {
            if(i>0 && nums[i-1]==nums[i])
            {
                continue;
            }
            int target=-nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum=nums[l]+nums[r];
                
                if(sum==target)
                {
                    v.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
                else if(sum<target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            
            
        }
        return v;
        
    }
};
