class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> frq;
        for(const auto&num : nums) {
            if(frq[num]) return true;
            frq[num] = true;
        }
        return false;
    }
};