class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        int i;
        unordered_set<int>st;
        for(i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int maxi=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int f=nums[i];
                int c=1;
                while(st.find(f+1)!=st.end())
                {
                    c++;
                    f=f+1;
                }
                maxi=max(maxi,c);
            }
        }
        return maxi;
        
    }
};
