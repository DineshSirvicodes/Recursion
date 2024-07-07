// TC -  O( N^M) (n raised to m)
// Sc -  O(N)
// Solution 1: Backtracking
// Approach:
// Basically starting from vertex 0 color one by one the different vertices. 

// Base condition:
// If I have colored all the N nodes return true.

// Recursion:
// Trying every color from 1 to m with the help of a for a loop.
// Is safe function returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.
// In case this is an algorithm and follows a certain intuition, please mention it. 
  // Color it with color i then call the recursive function for the next node if it returns true we will return true.
  // And If it is false then take off the color.

// Now if we have tried out every color from 1 to m and it was not possible to color it with any of the m colors then return false.
class Solution{
public:

    bool isSafe(int node,int color[],bool graph[101][101],int N,int col){
        for(int k = 0; k<N ; k++){
           if(k!=node && graph[k][node] == 1 && color[k] == col){
               return false;
           } 
        }
        return true;
    }

    bool solve(int node,int color[],int m,int N, bool graph[101][101]){
        if(node == N){
            return true; //  colors have been assigned to all the nodes
        }
         // i = colors to be put
        for(int i = 1 ; i<=m ; i++){
            if(isSafe(node,color,graph,N,i)){
                color[node] = i; // color that node
                if(solve(node+1,color, m,N,graph)){
                    return true;
                }
                color[node] = 0; // if false, backtrack to remove the color at that node
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
       int color[n] = {0};
       if(solve(0,color,m,n,graph)) return true;
       return false;
        
    }
};
// functionality of each method=>
// bool isSafe()=>
//It iterates through all nodes to check if there is any adjacent node (graph[k][node] == 1) that is already colored with the same color (color[k] == col).
//If such a node is found, it returns false, indicating it's not safe to color the current node with col.
//If no such node is found, it returns true, indicating it's safe to color the current node with col.

// solve =>
// If all nodes are colored (node == N), it returns true.
// It tries to assign each color (from 1 to m) to the current node.
// It checks if assigning color i to the current node is safe using isSafe.
// If safe, it assigns the color and recursively tries to color the next node.
// If coloring the next node leads to a solution (solve(node + 1, color, m, N, graph)), it returns true.
// If not, it backtracks by resetting the color of the current node (color[node] = 0).
// If no color can be assigned to the current node without conflicts, it returns false.

// graphColoring()->
// Initializes the color array to all zeros (no node is colored initially).
// Calls the solve function starting from the first node (node 0).
// Returns true if the graph can be colored with at most m colors.
// Returns false otherwise.
