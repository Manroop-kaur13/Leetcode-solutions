class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
           bool  destroyed=false;
            while(!st.empty() && asteroids[i]<0 && st.top()>0){
                if(st.top()<abs(asteroids[i])){
                    st.pop();
                }
                else if(st.top()==abs(asteroids[i])){
                    destroyed=true;
                    st.pop();
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
                }
                if(!destroyed){
                   st.push(asteroids[i]);}
              }
              
    vector<int>ans;
    while(!st.empty()){
        int x=st.top();
        ans.push_back(x);
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};