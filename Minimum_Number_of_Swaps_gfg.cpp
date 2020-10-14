using namespace std;
#define F(i,a,b) for(long long int i = a;i < b;i++)
#define ll long long 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        vector<int> arr(N,0);
        for(int i = 0 ; i < arr.size() ; i++)
            cin >> arr[i];
        int count = arr[0];
        int maximum = arr[0];
        int ans = 1;
        if(arr[0] == 0) cout <<-1<<endl;
        else{
        for(int i = 1 ; i < N ; i++){
            if(i <= maximum){
                count = max(count,i + arr[i]);
            } else {
                
                maximum = count;
                count = i + arr[i];
                ans++;
                if(maximum >= N - 1) break;
            }
        }
        if(maximum >= N - 1)
        cout << ans << endl;
        else
        cout <<-1 << endl;
        }
    }
}
