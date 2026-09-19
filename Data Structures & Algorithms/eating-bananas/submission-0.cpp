class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1 , end = *max_element(piles.begin(), piles.end());

        while(st <= end){
            int mid = st + (end-st)/2;

            int hours = 0;

            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + mid - 1) / mid;
            }

            if(hours <= h) end = mid - 1;
            else st = mid + 1;
        }

        return st;
    }
};