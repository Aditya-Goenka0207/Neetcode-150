class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        int product = 1;

        prefix[0] = 1;

        for(int i=1;i<n;i++){
            prefix[i] = nums[i-1] * product;
            product = prefix[i];
        }

        product = 1;
        suffix[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            suffix[i] = nums[i+1] * product;
            product = suffix[i];
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
