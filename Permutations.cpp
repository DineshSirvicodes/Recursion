// First Sol - 
// https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/
// TC - N! * O(N). Here O(N) is the hashmap used for marking and unmarking the array, mark->the element is picked, unmark->unpick the element
// SC - O(N) + O(N). First O(N) for ds array to store each combination, second O(N) for hashmap
// Auxilary space = O(N) for recursion depth.
class Solution {
public:
    void recurPermutate(vector<int>&ds,vector<int>&nums,int freq[],vector<vector<int>>&ans){
        //base case
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){ // freq[i] == 0
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermutate(ds,nums,freq,ans);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0; i<nums.size(); i++){
            freq[i] = 0;
        }
        recurPermutate(ds,nums,freq,ans);
        return ans;
    }
};
//Output:
ds (Adding): 1 
freq: 1 0 0 
ds (Adding): 1 2 
freq: 1 1 0 
ds (Adding): 1 2 3 
freq: 1 1 1 
ds (Permutation found): 1 2 3 
ans: [1 2 3 ] 
ds (Removing): 1 2 
freq: 1 1 0 
ds (Removing): 1 
freq: 1 0 0 
ds (Adding): 1 3 
freq: 1 0 1 
ds (Adding): 1 3 2 
freq: 1 1 1 
ds (Permutation found): 1 3 2 
ans: [1 2 3 ] [1 3 2 ] 
ds (Removing): 1 3 
freq: 1 0 1 
ds (Removing): 1 
freq: 1 0 0 
ds (Removing): 
freq: 0 0 0 
ds (Adding): 2 
freq: 0 1 0 
ds (Adding): 2 1 
freq: 1 1 0 
ds (Adding): 2 1 3 
freq: 1 1 1 
ds (Permutation found): 2 1 3 
ans: [1 2 3 ] [1 3 2 ] [2 1 3 ] 
ds (Removing): 2 1 
freq: 1 1 0 
ds (Removing): 2 
freq: 0 1 0 
ds (Adding): 2 3 
freq: 0 1 1 
ds (Adding): 2 3 1 
freq: 1 1 1 
ds (Permutation found): 2 3 1 
ans: [1 2 3 ] [1 3 2 ] [2 1 3 ] [2 3 1 ] 
ds (Removing): 2 3 
freq: 0 1 1 
ds (Removing): 2 
freq: 0 1 0 
ds (Removing): 
freq: 0 0 0 
ds (Adding): 3 
freq: 0 0 1 
ds (Adding): 3 1 
freq: 1 0 1 
ds (Adding): 3 1 2 
freq: 1 1 1 
ds (Permutation found): 3 1 2 
ans: [1 2 3 ] [1 3 2 ] [2 1 3 ] [2 3 1 ] [3 1 2 ] 
ds (Removing): 3 1 
freq: 1 0 1 
ds (Removing): 3 
freq: 0 0 1 
ds (Adding): 3 2 
freq: 0 1 1 
ds (Adding): 3 2 1 
freq: 1 1 1 
ds (Permutation found): 3 2 1 
ans: [1 2 3 ] [1 3 2 ] [2 1 3 ] [2 3 1 ] [3 1 2 ] [3 2 1 ] 
ds (Removing): 3 2 
freq: 0 1 1 
ds (Removing): 3 
freq: 0 0 1 
ds (Removing): 
freq: 0 0 0 
All permutations:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 

// Second Sol - With Backtracking. More Optimal, without extra space ie without using map / hasharray 
// logic swap each index, TC - O(N!) * O(N),where O(N) for loop. SC - O(1). Also Auxiliary space is O(N) for recursion depth
// Go from index to n - 1 and swap once the swap has been done call recursion for the next state. 
// After coming back from the recursion make sure you re-swap it because, for the next element, the swap will not take place.

class Solution {
public:
    void recurPermute(int index,vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            recurPermute(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        return ans;
    }
};
