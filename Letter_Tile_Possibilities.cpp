class Solution {
public:
    void recur(string temp,vector<int> H,string tiles,set<string> &s){
        
        if(temp.size() > 0 and temp.size() <= tiles.size())
            s.insert(temp);
        if(temp.size() > tiles.size())
            return;
        for(int i = 0 ; i < tiles.size() ; i++){
            if(H[int(tiles[i]) - 65] > 0){
                temp.push_back(tiles[i]);
                H[int(tiles[i]) - 65]--;
                recur(temp,H,tiles,s);
                temp.pop_back();   
                H[int(tiles[i]) - 65]++;
           }
        }
    }
    int numTilePossibilities(string tiles) {
        int ans = 0;
        string temp = "";
        set<string> s;
        vector<int> H(26,0);
        for(int i = 0 ; i < tiles.size() ; i++){
            H[int(tiles[i]) - 65]++;
        }
        recur(temp,H,tiles,s);
        return s.size();
    }
};
