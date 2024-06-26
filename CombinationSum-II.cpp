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
// Optimal Sol - using subsequences Tc - 2^n * k - where k is the avg. length of the ds array to be put into ans array, SC = k*x where x is the number of combinations
//Initially, We start with the index 0, At index 0 we have n - 1 way to pick the first element of our subsequence.

// Check if the current index value can be added to our ds. If yes add it to the ds and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate sequences.

// Reduce the target by arr[i],call the recursive call for f(idx + 1,target - 1,ds,ans) after the call make sure to pop the element from the ds.(By seeing the example recursive You will understand).

// if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

// Base Condition:

// Whenever the target value is zero add the ds to the ans return.

class Solution {
public:
    void findCombinationSum(int ind,int target,vector<int>& arr,vector<int>&ds,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind ; i<arr.size(); i++){
            // to avoid duplicate element pick up
            if(i>ind && arr[i] == arr[i-1]) continue;//avoid that element
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinationSum(i+1,target-arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0,target,candidates,ds,ans);
        return ans;
    }
};
