/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.*/



class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long int A1 = fabs(C-A)*fabs(B-D);
        long int A2 = fabs(E-G)*fabs(F-H);
      
        long long int common_area = 0,width=0,height=0;
  
        if(min(C,G)>max(A,E))
            width = min(C,G)-max(A,E);
        if(min(D,H)>max(B,F))
            height = min(D,H)-max(B,F);
       
        common_area = width*height; 
        return A1+A2-common_area;
    }
};
