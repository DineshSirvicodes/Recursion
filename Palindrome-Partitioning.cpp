// TC - O(2^n * k^(n/2)) where 2^n is to generate every substring and O(k) for inserting the palindromes into another data structure. k is the avg lenth of the palindrome list. O(n/2) for checking if a substring generated is a palindrome or not
// Sc - O(k*x) , k is the average length of the palindrome list, and x is the number of palindromes generated. O(n) is the recursion depth.
class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
            
        }
        return true;
    }
    void func(int ind,string s, vector<vector<string>> &res , vector<string>&path){
        if(ind == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = ind ; i<s.size(); i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,res,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0,s,res,path);
        return res;
    }
};
