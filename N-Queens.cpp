//First Sol - TC - (N! * N) , Sc = O(N^2)
class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
        int duprow = row;
        int dupcol = col;
        //  looking in North-West direction, row decrease,col decreases
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        // west direction,only col decreases
        row = duprow;
        col = dupcol;
        while(col>=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        //south-west,row increases, col decreases
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
//Intuition: This is the optimization of the issafe function. 
// In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for the diagonal.
// Here, we will use hashing to maintain a list to check whether that position can be the right one or not.
// 3 hasharrays
// 1) leftRow => to get the hashing details of the row, west direction, firstly a queen is placed and next time to place a queen in the next col,
//     this leftRow is checked again, if it is hashed already, ie marked then dont put the queen there
// 2) lowerDiagonal => has 0 to 2*n-1 space, as the sum of row + col will go till 2*n-1, so go to row+col and check if any place is marked and place
// queen accordingly
// 3) upperDiagonal => has 0 to 2*n-1 space, as the sum of n-1 + col-row will go to 2*n-1, why this formula? to get the upperdiagonal hashing
class Solution {
public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, 
    vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) 
    {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string >> ans;
        vector < string > board(n);
        string s(n, '.');
            for (int i = 0; i < n; i++) {
                board[i] = s;
            }
        vector < int > leftrow(n, 0), // west
        upperDiagonal(2 * n - 1, 0),  // north-west
        lowerDiagonal(2 * n - 1, 0); // south - west
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};
