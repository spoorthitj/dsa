class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int>vec(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prev=st.top();
                st.pop();
vec[prev]=i-prev;
            }
            st.push(i);
        }
        return vec;

    }
};