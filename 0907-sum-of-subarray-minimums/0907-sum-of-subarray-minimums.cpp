class Solution {
public:
    vector<int>nse(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){ans[i]=n;}
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        
        return ans;
    }

    vector<int>pse(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){ans[i]=-1;}
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
    
        return ans;

    }
    int sumSubarrayMins(vector<int>& arr) {
        long long sum=0;
        long long mod=1e9+7;
        vector<int>left=pse(arr);
        vector<int>right=nse(arr);
        for(int i=0;i<arr.size();i++){
            long long l=i-left[i];
            long long  r=right[i]-i;
            sum=sum+(l*r*1LL*arr[i]);
        }
        return sum%mod;
    }
};