class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        int n=t.size();
        st.push({t[n-1],n-1});
        
        vector<int>ans(n,0);

        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top().first <= t[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top().second - i;
            }
            st.push({t[i],i});
        }

        return ans;
        
    }
};
