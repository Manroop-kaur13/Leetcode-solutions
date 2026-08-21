class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>nums;
        int l=nums2.size();
        stack<int>st;
        for(int i=l-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                nums[nums2[i]]=-1;
            }
            else{
                nums[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int val=nums[nums1[i]];
            ans.push_back(val);
        }
        return ans;
    }
};