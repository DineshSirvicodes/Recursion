//TC - 2^n + 2^n*log(2^n)
// Intuition: The main idea is that on every index you have two options either to select the element to add it to your subset(pick) 
// or not select the element at that index and move to the next index(non-pick).

// Approach: Traverse through the array and for each index solve for two arrays, one where you pick the element,i.e add the 
// element to the sum or don’t pick and move to the next element, recursively, until the base condition. Here when you reach the end of the array is the base condition.
class Solution {
  public:
    
    void func(int ind,int sum,vector<int>&arr,int N,vector<int>& sumSubset){
        //base case
        if(ind == N){
            sumSubset.push_back(sum);
            return;
        }
        //pick up the element;
        func(ind + 1, sum + arr[ind], arr, N ,sumSubset);
        //do not pick
        func(ind+1 , sum , arr,  N , sumSubset);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> sumSubset;
        func(0,0,arr,n,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};
