class Solution {
public:
    vector<int>pse(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){ans[i]=-1;}
            else{ans[i]=st.top();}
            st.push(i);
        }
        return ans; 
    }
    vector<int>nse(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){ans[i]=n;}
            else{ans[i]=st.top();}
            st.push(i);
        }
        return ans; 
    }
    vector<int>nge(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()){ans[i]=n;}
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;}
    vector<int>pge(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){ans[i]=-1;}
        else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;}
    long long subArrayRanges(vector<int>& nums) {
        vector<int>nextg=nge(nums);
        vector<int>nexts=nse(nums);
        vector<int>prevg=pge(nums);
        vector<int>prevs=pse(nums);
        long long sum=0;
        
        for(int i=0;i<nums.size();i++){
            long long greater=1LL*(nextg[i]-i)*(i-prevg[i])*nums[i];
            long long smaller=1LL*(nexts[i]-i)*(i-prevs[i])*nums[i];
            sum+=greater-smaller;
        }
        return sum;
    }
};