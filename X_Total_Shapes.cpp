/*Given N * M string array arr of O's and X's. The task is to find the number of 'X' total shapes.
'X' shape consists of one or more adjacent X's (diagonals not included).

Input:
The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, in a new line print the total X shapes.

Your Task:
Complete Shape function that takes string array arr, n, m as arguments and returns the count of total X shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Expected Time Complexity : O(N*M)
Expected Auxilliary Space : O(1)

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO
So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.*/


void dfs(vector<vector<char>> &arr,int i,int j){
    if(i < 0 or j < 0 or i >= arr.size() or j >= arr[0].size() or arr[i][j] == 'O') return;
    arr[i][j] = 'O';
    dfs(arr,i,j+1);
    dfs(arr,i-1,j);
    dfs(arr,i+1,j);
    dfs(arr,i,j-1);
}

int Shape(vector<string> &v,int n,int m) {
    //code here
    int ans = 0;
    vector<vector<char>> arr(v.size(),vector<char> (v[0].size(),'0'));
    for(int i = 0 ; i < v.size() ; i++){
        for(int j = 0 ; j < v[0].size() ; j++){
            arr[i][j] = v[i][j];
        }
    }
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr[i].size() ; j++){
            if(arr[i][j] == 'X'){
                ans++;
                dfs(arr,i,j);
            }
        }
    }
    return ans;
}
