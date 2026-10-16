class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int r=(m*n)-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int mrow=mid/n;
            int mcol=mid%n;
            if(target==matrix[mrow][mcol])
            {
                return true;
            }
            else if(target<matrix[mrow][mcol])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return false;
    }
};
