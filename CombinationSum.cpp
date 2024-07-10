//TC = O(2^t * k) where t is the target, k is the average length of the data structure
// SC = O(k*x), k is the average length and x is the no. of combinations
class Solution {
public:
    void findCombination(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        // base case
        if(ind == arr.size()){ // reached end of arr- candidates
            if(target == 0){// the current combination is a solution
                ans.push_back(ds);
            }
            return;
        }
        
        //pick up the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back(); // remove last stored element
        }
        // dont pick , arr[ind]>target,move to next element of candidate arr
        findCombination(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
}; 
