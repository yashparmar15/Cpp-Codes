// Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system. These rectangles may intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

// Unfortunately, Chef lost one vertex, and up until now, none of his fixes have worked (although putting an image of a point on a milk carton might not have been the greatest idea after all…). Therefore, he gave you the task of finding it! You are given the remaining 4N−1 points and you should find the missing one.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// Then, 4N−1 lines follow. Each of these lines contains two space-separated integers x and y denoting a vertex (x,y) of some rectangle.
// Output
// For each test case, print a single line containing two space-separated integers X and Y ― the coordinates of the missing point. It can be proved that the missing point can be determined uniquely.

// Constraints
// T≤100
// 1≤N≤2⋅105
// |x|,|y|≤109
// the sum of N over all test cases does not exceed 2⋅105
// Subtasks
// Subtask #1 (20 points):

// T=5
// N≤20
// Subtask #2 (30 points): |x|,|y|≤105
// Subtask #3 (50 points): original constraints

// Example Input
// 1
// 1
// 1 1
// 1 2
// 2 1


#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
	    int n;
	    cin >> n;
	    int x , y;
	    int x_cor = 0,y_cor = 0;
	    for(int i = 0 ; i < 4 * n - 1 ; i++){
	        cin >> x >> y;
	        x_cor ^= x;
	        y_cor ^= y;
	    }
	    cout << x_cor << " " << y_cor << "\n";
	}
	return 0;
}
