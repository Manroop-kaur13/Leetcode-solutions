class Solution {
public:
    int maxidx(vector<vector<int>> &mat,int mid){
        int idx=0;
        int imax=INT_MIN;
        int s=mat.size();
        for(int i=0;i<s;i++){
            if(mat[i][mid]>imax){
                imax=mat[i][mid];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l=0;
        vector<int>ans;
        int size= mat[0].size();
        int h=size-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int max_idx=maxidx(mat,mid);
            int left=mid-1>=0? mat[max_idx][mid-1]:-1;
            int right=mid+1<size?mat[max_idx][mid+1]:-1;;
            if(mat[max_idx][mid]>left && mat[max_idx][mid]>right){ans.push_back(max_idx);
            ans.push_back(mid);
            return ans;}
            else if(mat[max_idx][mid]<left){h=mid-1;}
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};