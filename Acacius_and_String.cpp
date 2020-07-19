// Acacius is studying strings theory. Today he came with the following problem.

// You are given a string 𝑠 of length 𝑛 consisting of lowercase English letters and question marks. It is possible to replace question marks with lowercase English letters in such a way that a string "abacaba" occurs as a substring in a resulting string exactly once?

// Each question mark should be replaced with exactly one lowercase English letter. For example, string "a?b?c" can be transformed into strings "aabbc" and "azbzc", but can't be transformed into strings "aabc", "a?bbc" and "babbc".

// Occurrence of a string 𝑡 of length 𝑚 in the string 𝑠 of length 𝑛 as a substring is a index 𝑖 (1≤𝑖≤𝑛−𝑚+1) such that string 𝑠[𝑖..𝑖+𝑚−1] consisting of 𝑚 consecutive symbols of 𝑠 starting from 𝑖-th equals to string 𝑡. For example string "ababa" has two occurrences of a string "aba" as a substring with 𝑖=1 and 𝑖=3, but there are no occurrences of a string "aba" in the string "acba" as a substring.

// Please help Acacius to check if it is possible to replace all question marks with lowercase English letters in such a way that a string "abacaba" occurs as a substring in a resulting string exactly once.

// Input
// First line of input contains an integer 𝑇 (1≤𝑇≤5000), number of test cases. 𝑇 pairs of lines with test case descriptions follow.

// The first line of a test case description contains a single integer 𝑛 (7≤𝑛≤50), length of a string 𝑠.

// The second line of a test case description contains string 𝑠 of length 𝑛 consisting of lowercase English letters and question marks.

// Output
// For each test case output an answer for it.

// In case if there is no way to replace question marks in string 𝑠 with a lowercase English letters in such a way that there is exactly one occurrence of a string "abacaba" in the resulting string as a substring output "No".

// Otherwise output "Yes" and in the next line output a resulting string consisting of 𝑛 lowercase English letters. If there are multiple possible strings, output any.

// You may print every letter in "Yes" and "No" in any case you want (so, for example, the strings yEs, yes, Yes, and YES will all be recognized as positive answer).

// Example
// inputCopy
// 6
// 7
// abacaba
// 7
// ???????
// 11
// aba?abacaba
// 11
// abacaba?aba
// 15
// asdf???f???qwer
// 11
// abacabacaba
// outputCopy
// Yes
// abacaba
// Yes
// abacaba
// Yes
// abadabacaba
// Yes
// abacabadaba
// No
// No
// Note
// In first example there is exactly one occurrence of a string "abacaba" in the string "abacaba" as a substring.

// In second example seven question marks can be replaced with any seven lowercase English letters and with "abacaba" in particular.

// In sixth example there are two occurrences of a string "abacaba" as a substring.




#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans = "";
		bool present = false;
		int count = 0;
		for(int i = 0 ; i < s.size() - 6 ; i++){
			if(s[i] == 'a' and s[i + 1] == 'b' and s[i + 2] == 'a' and s[i + 3] == 'c' and s[i + 4] == 'a' and s[i + 5] == 'b' and s[i + 6] == 'a'){
				present = true;
				count++;
			}
		}
		if(present){
			if(count == 1){
				for(int i = 0 ; i < s.size() ; i++){
					if(s[i] == '?')
						ans = ans + 'z';
					else
						ans = ans + s[i];
				}
				cout << "Yes\n" << ans << "\n";	
			} else {
				cout << "No\n";
			}
		} else {
			bool notpresent = true;
			for(int i = 0 ; i < s.size() - 6 ; i++){
				if((s[i] == 'a' or s[i] == '?') and (s[i + 1] == 'b' or s[i + 1] == '?') and (s[i + 2] == 'a' or s[i + 2] == '?') and (s[i + 3] == 'c' or s[i + 3] == '?') and (s[i + 4] == 'a' or s[i + 4] == '?') 
					and (s[i + 5] == 'b' or s[i + 5] == '?') and (s[i + 6] == 'a' or s[i + 6] == '?')){
					for(int j = 0 ; j < i ; j++){
						if(s[j] == '?')
							ans = ans + 'z';
						else
							ans = ans + s[j];
					}
					ans = ans + "abacaba";
					for(int j = i + 7 ; j < s.size() ; j++){
						if(s[j] == '?')
							ans = ans + 'z';
						else
							ans = ans + s[j];
					}
					count = 0;
					for(int j = 0 ; j < s.size() - 6 ; j++){
						if(ans[j] == 'a' and ans[j + 1] == 'b' and ans[j + 2] == 'a' and ans[j + 3] == 'c' and ans[j + 4] == 'a' and ans[j + 5] == 'b' and ans[j + 6] == 'a'){
							count++;
						}
					}
					if(count == 1){
						cout << "Yes\n" << ans << "\n";
						notpresent = false;
						break;
					} else {
						ans = "";
					}
				}
			}
			if(notpresent)
				cout << "No\n";
		}
	}
}