class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size(), inf = 1001;
        unordered_map<int,int> frq;
        vector<int> ans;
        vector<vector<int>> frqs(n + 1);
        for(int i = 0; i < n; i++) 
            frq[nums[i]]++;
        for(const auto&[num, f] : frq) {
            frqs[f].push_back(num);
        }
        for(int i = n; i >= 0; i--) {
            for(const auto&num : frqs[i]) {
                ans.push_back(num);
                if(ans.size() == k) goto HERE;
            }
        }
        HERE:
        return ans;
    }
};
