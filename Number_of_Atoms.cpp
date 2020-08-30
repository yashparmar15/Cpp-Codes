/*Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
Example 2:
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.*/



class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string,int> M;
        stack<pair<string,int>> stk;
        for(int i = 0 ; i < formula.size() ; i++){
            int num = int(formula[i]);
            if(num >= 65 and num <= 91){
                string temp = "";
                temp += formula[i];
                int j = i + 1;
                int s = int(formula[j]);
                while(j < formula.size() and s >= 97 and s <= 122){
                    temp += formula[j];
                    j++;
                    s = int(formula[j]);
                }
                int count = 0;
                while(j < formula.size() and s >= 48 and s <= 57){
                    count = count * 10 + s - 48;
                    j++;
                    s = int(formula[j]);
                }
                if(count == 0)
                    count =  1;
                stk.push(make_pair(temp,count));
                i = j - 1;
            } else {
                if(formula[i] == '(')
                    stk.push(make_pair("(",0));
                else{
                    if(formula[i] == ')'){
                        int num = 0;
                        int j = i + 1;
                        while(j < formula.size() and formula[j] >= '0' and formula[j] <= '9'){
                            num = num * 10 + int(formula[j]) - 48;
                            j++;
                        }
                        i = j - 1;
                        stack<pair<string,int>> t;
                        while(stk.top().first != "("){
                            t.push(make_pair(stk.top().first,stk.top().second * num));
                            stk.pop();
                        }
                        stk.pop();
                        while(!t.empty()){
                            stk.push(make_pair(t.top().first,t.top().second));
                            t.pop();
                        }
                    }
                }
            }
        }
        vector<pair<string,int>> v;
        while(!stk.empty()){
            auto x = stk.top();
            M[x.first] += x.second;
            stk.pop();
        }
        for(auto m : M)
            v.push_back(make_pair(m.first,m.second));
        sort(v.begin(),v.end());
        string ans = "";
        for(int i = 0 ; i < v.size() ; i++){
            ans += v[i].first;
            if(v[i].second != 1)
                ans += to_string(v[i].second);
        }
        return ans;
    }
};
