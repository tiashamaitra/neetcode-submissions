class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i;
        int l=0;
        unordered_map<char,int>mp;
        int maxi=0;
        for(i=0;i<n;i++)
        {
            
            if(mp.find(s[i])!=mp.end() && mp[s[i]] >= l)
            {
                l=mp[s[i]]+1;
                
            }
            mp[s[i]]=i;
            maxi=max(maxi,i-l+1);
            
        }
        return maxi;
    }
};
