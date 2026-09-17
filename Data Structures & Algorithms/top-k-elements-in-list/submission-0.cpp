class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> m;

        for(int n : nums){
            if(m.find(n) == m.end()) m[n] = 1;
            else m[n]++;
        }

        //freq , ele
        vector<pair<int, int>> v;

        for(auto x : m){
            v.push_back({x.second , x.first});
        }

        //sort descending based on freq
        sort(v.rbegin() , v.rend());

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
