class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size());
        stack<int> st;
        stack<int> ind;
        for (int i = 0; i < ans.size(); i++) {
            while(!st.empty() && temps[i] > st.top()) {
                ans[ind.top()] = i - ind.top();
                ind.pop();
                st.pop();
            }
            st.push(temps[i]);
            ind.push(i);
        }
        return ans;
    }
};
