class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> frqs(1e4 + 8);
        for(int i = 0, frq = 0, last = nums[0]; i < nums.size(); i++) {
            if(nums[i] == last) frq++;
            else {
                frqs[frq].push_back(last);
                frq = 1;
            }
            last = nums[i];
            if(i == nums.size() - 1) {
                frqs[frq].push_back(last);
                frq = 1;
            }
        }
        for(int i = frqs.size() - 1; i >= 0; i--) {
            for(const auto&j : frqs[i]) {
                ans.push_back(j);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};
