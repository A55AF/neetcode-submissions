class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_set<int> starts;
        for(const auto&i : nums) {
            if(st.find(i - 1) == st.end())
                starts.insert(i);
        }
        int ans = 0;
        for(const auto&i : starts) {
            int cur = i, sz = 0;
            while(st.find(cur) != st.end()) {
                cur++, sz++;
            }
            ans = max(ans, sz);
        }
        return ans;
    }
};