class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0 , j = n-1;

        int ans = 0;

        while(i < j){
            int water = (j-i) * min(heights[i] , heights[j]);
            ans = max(ans , water);

            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return ans;
    }
};
