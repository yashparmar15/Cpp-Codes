/*Chef has a string S. He also has another string P, called pattern. He wants to find the pattern in S, but that might be impossible. Therefore, he is willing to reorder the characters of S in such a way that P occurs in the resulting string (an anagram of S) as a substring.

Since this problem was too hard for Chef, he decided to ask you, his genius friend, for help. Can you find the lexicographically smallest anagram of S that contains P as substring?

Note: A string B is a substring of a string A if B can be obtained from A by deleting several (possibly none or all) characters from the beginning and several (possibly none or all) characters from the end.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single string S.
The second line contains a single string P.
Output
For each test case, print a single line containing one string ― the smallest anagram of S that contains P.

Constraints
1≤T≤10
1≤|P|≤|S|≤105
S and P contain only lowercase English letters
there is at least one anagram of S that contains P
Subtasks
Subtask #1 (20 points): |S|≤1,000
Subtask #2 (80 points): |S|≤105
Example Input
3
akramkeeanany
aka
supahotboy
bohoty
daehabshatorawy
badawy
Example Output
aaakaeekmnnry
abohotypsu
aabadawyehhorst*/



#include <bits/stdc++.h>
using namespace std;

bool comp(string a , string b){
    if(a.size() == b.size())
        return a < b;
    if(a.size() > b.size()){
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] != b[0])
                return a[i] < b[0];
        }
        return 1;
    } else {
        for(int i = 0 ; i < b.size() ; i++){
            if(a[0] != b[i])
                return a[0] < b[i];
        } 
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
	    string s;
	    cin >> s;
	    string p;
	    cin >> p;
	    vector<int> M(26,0);
	    for(int i = 0 ; i < s.size() ; i++){
	        M[int(s[i]) - 97]++;
	    }
	    for(int i = 0 ; i < p.size() ; i++){
	        M[int(p[i]) - 97]--;
	    }
	    vector<string> t;
	    for(int i = 0 ; i < 26 ; i++){
	        for(int j = 0 ; j < M[i] ; j++){
	            string s(1, char(i + 'a'));
	            t.push_back(s);
	        }
	    }
	    t.push_back(p);
	    sort(t.begin(),t.end(),comp);
	    string ans = "";
	    for(int i = 0 ; i < t.size() ; i++){
	        ans = ans + t[i];
	    }
	    cout << ans << "\n";
	}
	return 0;
}
