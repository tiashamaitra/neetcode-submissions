class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int i;
        int p=1;
        int zero=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            if(nums[i]!=0)
            {
                p=p*nums[i];
            }
        }
        for(i=0;i<n;i++)
        {
            if(nums[i]==0 && zero==1)
            {
                nums[i]=p;
            }
            else if(nums[i]==0 && zero>1)
            {
                nums[i]=0;
            }
            else if(nums[i]!=0 && zero>=1)
            {
                nums[i]=0;
            }
            else if(nums[i]!=0 && zero==0)
            {
                nums[i]=p/nums[i];
            }
        }
        return nums;
    }
};
