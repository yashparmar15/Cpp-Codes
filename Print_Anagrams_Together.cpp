vector<vector<string> > Anagrams(vector<string>& v) 
{
    // Your Code Here
    unordered_map<string,vector<string>> M;
    for(int i = 0 ; i < v.size() ; i++){
        string temp = v[i];
        sort(temp.begin(),temp.end());
        M[temp].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for(auto m : M){
        ans.push_back(m.second);
    }
    return ans;
}
