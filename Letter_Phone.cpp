/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.*/


void recur(vector<string> &ans , string temp , vector<string> v , string A,int index){
    if(temp.size() == A.size()){
        ans.push_back(temp);
        return;
    }
    for(int i = index ; i < A.size() ; i++){
        for(int j = 0 ; j < v[int(A[i]) - 48].size() ; j++){
            temp.push_back(v[int(A[i]) - 48][j]);
            recur(ans,temp,v,A,i+1);
            temp.pop_back();
        }
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> v = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string temp = "";
    recur(ans,temp,v,A,0);
    return ans;
}
