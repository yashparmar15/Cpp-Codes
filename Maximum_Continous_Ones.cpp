#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> v(N);
    for(int i = 0 ; i < N ; i++) cin >> v[i];
    int start = -1,end = -1;
    int prev = 0 , count = 0;
    int Max = 0;
    int s = -1;
    for(int i = 0 ; i < N ; i++){
        if(v[i] == 1){
            count++;
            if(count == 1) s = i;
        }
        else{
           if(K > 0){
               K--;
               count++;
               if(count == 1) s = i;
           }
           else {
               while(v[prev] != 0){
                   count--;
                   prev++;
               }
               s = prev + 1;
               prev++;
           }
        }
        if(Max < count){
            Max = count;
            start = s;
            end = i;
        }
    }
    cout << start << " " << end << endl;
}
