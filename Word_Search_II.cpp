class Solution {
public:
    void recur(string a , vector<vector<char>> v , string b , int x , int y , bool &flag){
        if(a.size() == b.size()){
            flag = 1;
            return;
        }
        if(x >= v.size() or x < 0 or y >= v[0].size() or y < 0)
            return;
        if(v[x][y] == a[b.size()]){
            b = b + v[x][y];
            char temp = v[x][y];
            v[x][y] = '9';
            recur(a,v,b,x+1,y,flag);
            recur(a,v,b,x-1,y,flag);
            recur(a,v,b,x,y+1,flag);
            recur(a,v,b,x,y-1,flag);
            b.pop_back();
            v[x][y] = temp;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0 ; j < board.size() ; j++){
                for(int k = 0 ; k < board[j].size() ; k++){
                    if(board[j][k] == words[i][0]){
                        bool flag = 0;
                        string word = "";
                        int x = j;
                        int y = k;
                        recur(words[i],board,word,x,y,flag);
                        if(flag){
                            ans.push_back(words[i]);
                            words[i] = "999";
                            break;
                        }
                    } 
                }
            }
        }
        return ans;
    }
};