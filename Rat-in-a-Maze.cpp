//TC - 4^(n*m)
// SC - O(n*m) , ie recursion depth of the recursion
class Solution{
    public:
    void solve(int i ,int j ,vector<vector<int>>&a , int n, vector<string> &ans,string move,vector<vector<int>>&vis){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        //downward, row increase ,col fixed
        if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1){
            vis[i][j] = 1;
            solve(i+1,j,a,n,ans,move+'D',vis);
            vis[i][j] = 0;
        }
        //left , row fixes, col decrease
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1){
            vis[i][j] = 1;
            solve(i,j-1,a,n,ans,move+'L',vis);
            vis[i][j] = 0;
        }
        //right , row fixed , col increases
        if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1){
            vis[i][j] = 1;
            solve(i,j+1,a,n,ans,move+'R',vis);
            vis[i][j] = 0;
        }
        //upward , row decrease, col fixed
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1){
            vis[i][j] = 1;
            solve(i-1,j,a,n,ans,move+'U',vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0] == 1) solve(0,0,m,n,ans,"",vis);
        return ans;
    }
};
// little optimization to convert the 4 if conditions into a single condition check,keeping 2 arrays to marked the D,L,R,U directions
// D -> i+1 , j ie +1 , +0
// L => i, j - 1 , ie +0 , -1
// R -> i, j+1 ie , +0 , +1
// U-> i-1, j ie -1, +0
// keeping two arrays di = [+1,0,0,-1]
//                    dj = [0,-1,1,0]
// so di[0] and dj[0] will indicate down direction and so on for the rest of the directions left, right , up
class Solution{
    public:
    void solve(int i,int j, vector<vector<int>>&a,int n, vector<string>& ans,string move,
    vector<vector<int>>& vis,int di[],int dj[]){
        if(i == n-1 && j == n-1 ){
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int ind = 0; ind<4 ; ind++){
            int nexti = i + di[ind]; // i -> row
            int nextj = j + dj[ind];  // j -> col
            
            if(nexti >=0 && nextj >=0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1){
                vis[i][j] = 1;
                solve(nexti,nextj,a,n,ans,move+dir[ind],vis,di,dj);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[] = {1,0,0,-1};
        int dj[] = {0,-1,1,0};
        if(m[0][0] == 1){
            solve(0,0,m,n,ans,"",vis,di,dj);
        }
        return ans;
    }
};
