class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , int> m;

        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(m[nums[i]] > 1) return true;
        }
        return false;
    }
};