class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        int s=0;
        for(i=0;i<n+1;i++)
        {
            s=s^i;
        }
        for(i=0;i<n;i++)
        {
            s=s^nums[i];
        }
        return s;
    }
};
