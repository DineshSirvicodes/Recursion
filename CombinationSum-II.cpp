// Brute approach- same as Combination Sum solution, but we have 2 conditions
// 1) No duplicate combination entry,
// 2) One element can be used once only
// Approach - Use set ds to store the List of List to avoid duplicate entries, again convert the set ds back to vector<vector<int>> res to return list of list
class Solution {
public:
    void findCombinationSum(int ind,int target,vector<int>& arr,set<vector<int>> &ans, vector<int> ds){
        if(ind == arr.size()){
            if(target == 0){
                ans.insert(ds);
            }
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombinationSum(ind+1,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findCombinationSum(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findCombinationSum(0,target,candidates,ans,ds);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
