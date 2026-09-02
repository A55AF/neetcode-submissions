class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), prfx(n), suffx(n);
        for(int i = 0; i < n; i++) {
            prfx[i] = nums[i];
            if(i) prfx[i] *= prfx[i - 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            suffx[i] = nums[i];
            if(i + 1 < n) suffx[i] *= suffx[i + 1];
        }
        for(int i = 0; i < n; i++ ) {
            int cur = 1;
            if(i) cur *= prfx[i - 1];
            if(i + 1 < n) cur *= suffx[i + 1];
            ans[i] = cur;
        }
        return ans;
    }
};
