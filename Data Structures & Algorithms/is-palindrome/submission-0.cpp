class Solution {
public:
    bool isupper(char c)
    {
        int p = c - 'A';

        if(p >= 0 && p <= 25)
        {
            return true;
        }

        return false;
    }

    bool isalnum(char c)
    {
        if((c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9'))
        {
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) 
    {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while(l <= r)
        {
            // Ignore non-alphanumeric characters from left
            if(!isalnum(s[l]))
            {
                l++;
                continue;
            }

            // Ignore non-alphanumeric characters from right
            if(!isalnum(s[r]))
            {
                r--;
                continue;
            }

            char left = s[l];
            char right = s[r];

            // Convert uppercase to lowercase
            if(isupper(left))
            {
                left = left + 32;
            }

            if(isupper(right))
            {
                right = right + 32;
            }

            if(left != right)
            {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};