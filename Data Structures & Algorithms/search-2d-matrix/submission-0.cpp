class Solution {  
public:  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {  
        int n = matrix.size();  
        int m = matrix[0].size();  
        int sr = 0 , er = n*m-1;  
  
        while(sr <= er){  
            int mid = sr + (er - sr)/2;  
            int mr = mid / m;  
            int mc = mid % m;  
  
            if(matrix[mr][mc] == target) return true;  
            else if(matrix[mr][mc] < target) sr = mid + 1;  
            else er = mid - 1;  
        }  
        return false;  
    }  
};