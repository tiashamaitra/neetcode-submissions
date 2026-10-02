class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        int i;
        for(i=0;i<n;i++)
        {
            string s1=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s1);
        }
        vector<vector<string>>v;
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        return v;


    }
};
