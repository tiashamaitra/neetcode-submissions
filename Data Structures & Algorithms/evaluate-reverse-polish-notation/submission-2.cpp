class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        int i;
        int ans;
        stack<int>st;
        for(i=0;i<n;i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"                 ||tokens[i]=="*"||tokens[i]=="/")
            {
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                char op=tokens[i][0];
                switch(op)
                {
                    case '+':
                    ans=left+right;
                    break;
                    case '-':
                    ans=left-right;
                    break;
                    case '*':
                    ans=left*right;
                    break;
                    case '/':
                    ans=left/right;
                    break;
                }
                st.push(ans);
            }
            else
            {
                int p=stoi(tokens[i]);
                st.push(p);
            }
        }
        return st.top();
    }
};
