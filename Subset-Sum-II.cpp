
// Solution 1: Brute Force
// Approach:
// At every index, we make a decision whether to pick or not pick the element at that index. 
// This will help us in generating all possible combinations but does not take care of the duplicates. 
// Hence we will use a set to store all the combinations that will discard the duplicates.

// Optimal Sol if n = 3 ,no. of subsets created is 2^n  ie 2^3 = 8.
// Tc - 2^n * N , where N is the time to put ds into ans
// Sc - 2^n * k , where k is the average length of subsets
class Solution :
public:
    void findSubsets(int ind,vector<int>& nums, vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i = ind ; i<nums.size(); i++){
            if(i!=ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }
};
