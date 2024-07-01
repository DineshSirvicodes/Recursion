//First Sol - TC - (N! * N) , Sc =  O(N^2)
class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
        int duprow = row;
        int dupcol = col;
        //  looking in North-West direction, row decrease,col decrease
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // west direction,only col decrease
        row = duprow;
        col = dupcol;
        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        //south-west,row increases, col decrease
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void solve(int col,vector<string>& board,vector<vector<string>>&ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n ; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};

// Second Sol - More Optimized, using hashing concept. 
