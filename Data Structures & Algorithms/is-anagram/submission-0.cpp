class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);

        for(char c : s)
            freq1[c-'a']++;

        for(char c : t)
            freq2[c-'a']++;

        int i , j ;

        for(i = 0,j=0;i<26 && j<26;i++,j++){
            if(freq1[i] != freq2[j]) return false;
        }

        return true;
    }
};