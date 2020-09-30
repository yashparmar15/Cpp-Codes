#include<bits/stdc++.h>
using namespace std;
void recur(string temp,vector<string> &res,int open,int close,int &N){
    if(open == close and open == N){
        res.push_back(temp);
        return;
    }
    if(open + 1 <= N) recur(temp + "(",res,open + 1,close,N);
    if(close + 1 <= open) recur(temp + ")",res,open,close + 1,N);
}
vector<string> generate(int &N){
    vector<string> res;
    string temp = "(";
    int open = 1,close = 0;
    recur(temp,res,open,close,N);
    return res;
}
int countScore(string &s,int low,int high){
    if(low == high - 1) return 1;
    int count = 0;
    for(int i = low ; i < high ; i++){
        if(s[i] == '(') count++;
        if(s[i] == ')') count--;
        if(count == 0){
            return countScore(s,low,i) + countScore(s,i + 1,high);
        }
    }
    return 2 * countScore(s,low + 1,high - 1);
}
int main(){
    int N;
    cin >> N;
    vector<string> res = generate(N);
    int ans = 0;
    for(int i = 0 ; i < res.size() ; i++){
        ans += countScore(res[i],0,res[i].size() - 1);
    }
    cout << ans << endl;
}
