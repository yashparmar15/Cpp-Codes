class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    unordered_map<int,int> M;
	    for(int i = 0 ; i < n ; i++)
	        M[arr[i]]++;
	    for(auto m : M){
	        for(auto m1 : M){
	            int num = m.first * m.first + m1.first * m1.first;
	            int xnum = sqrt(num);
	            if(xnum * xnum == num and M.find(xnum) != M.end()){
	                if(m.first == m1.first){
	                    if(M[xnum] and m.second >= 2) return true;
	                } else {
	                    if(M[xnum]) return true;
	                }
	            }
	        }
	    }
	    return false;
	}
};
