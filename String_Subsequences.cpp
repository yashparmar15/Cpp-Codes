class Solution{
public:
    int countWays(string a, string b){
        
        
        //          g   k   s
        //      1   0   0   0            
        //  g   1   1   0   0   
        //  e   1   1   0   0   
        //  e   1   1   0   0
        //  k   1   1   1   0
        //  s   1   1   1   1
        //  f   1   1   1   1
        //  o   1   1   1   1
        //  r   1   1   1   1   
        //  g   1   2   1   1
        //  e   1   2   1   1
        //  e   1   2   1   1
        //  k   1   2   3   1
        //  s   1   2   3   4
        int m = a.length(); 
        int n = b.length(); 
        int lookup[m + 1][n + 1] = { { 0 } }; 
        for (int i = 0; i <= n; ++i) 
            lookup[0][i] = 0; 
        for (int i = 0; i <= m; ++i) 
            lookup[i][0] = 1; 
        for (int i = 1; i <= m; i++) 
        { 
            for (int j = 1; j <= n; j++) 
            { 
                if (a[i - 1] == b[j - 1]) 
                    lookup[i][j] = lookup[i - 1][j - 1] +  
                                   lookup[i - 1][j]; 
                      
                else
                    lookup[i][j] = lookup[i - 1][j]; 
            } 
        } 
      
        return lookup[m][n]; 
    }
};
