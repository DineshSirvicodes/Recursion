//TC - O(2^n) *O(N), N is the time to put ds into ans
//Sc - 2^n * K , K is the average length of the ds array
class Solution {
public:
    void recurSolve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        ans.push_back(ds);
        for(int i = ind; i<nums.size(); i++){
            if(i!=ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            recurSolve(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        recurSolve(0,nums,ans,ds);
        return ans;
    }
};
