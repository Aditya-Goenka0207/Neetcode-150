class Solution { 
public: 
    bool isValid(vector<vector<char>>& board , int row , int col , char ch){ 
        //row 
        for(int j = 0;j<board.size();j++){ 
            if(j != col && board[row][j] == ch) return false; 
        } 
 
        //col 
        for(int i = 0;i<board.size();i++){ 
            if(i != row && board[i][col] == ch) return false; 
        } 
 
        //3*3 grid 
        int sr = (row/3)*3; 
        int sc = (col/3)*3; 
 
        for(int i = sr;i<=sr+2;i++){ 
            for(int j = sc;j<=sc+2;j++){ 
                if((i != row || j != col) && board[i][j] == ch) return false; 
            } 
        } 
        return true; 
    } 
 
    bool isValidSudoku(vector<vector<char>>& board) { 
        int n = board.size(); 
        int m = board[0].size(); 
 
        for(int i = 0;i<n;i++){ 
            for(int j = 0;j<m;j++){ 
                if(board[i][j] == '.') continue; 
 
                if(!isValid(board , i , j , board[i][j])){ 
                    return false; 
                } 
            } 
        } 
 
        return true; 
    } 
};