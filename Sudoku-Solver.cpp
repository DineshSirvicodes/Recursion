//TC - O(9^(n^2)) SC - O(1)
class Solution {
public:
    bool isValid(vector<vector<char>>&board,int row,int col, char c){
        for(int i = 0 ; i<9 ; i++){
            // col wise check
            if(board[i][col] == c) return false;
            // row wise check
            if(board[row][i] == c) return false;
            //3*3 grid check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        // row
        for(int i = 0 ; i<board.size(); i++){
            // col
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == '.'){ // empty
                    for(char c = '1'; c<='9'; c++){
                        if(isValid(board,i,j,c)){ // if the current num is valid,go for next recursive function call,and place next missing num
                            board[i][j] = c; // placed the num
                            if(solve(board) == true){ // go to next call, and find all the possible num values after placing
                                return true; // means all the possible cell values, are done , and return true. one solution found so return true
                            }
                            else{
                                board[i][j] = '.';// current num is not valid to be placed. so unmark it empty, go for next iteration
                            }
                        }
                    }
                    return false;
                }           
            }     
        }
        return true; // is all the cells are already non empty so directly return true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
