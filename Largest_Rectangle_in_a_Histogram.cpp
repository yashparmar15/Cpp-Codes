class Solution {
public:
    stack<int> s;
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0){
            return 0;
        }
        int i = 0;
        int max_area = 0;
        while(i<n){
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i++);
            } else{
                int tp = s.top();
                s.pop();
                
                int area_with_tp = heights[tp] * (s.empty() ? i : i - s.top() -1);
                
			
				max_area = max(max_area,area_with_tp);
            }
        }
        
        while(s.empty() == false){
                int tp = s.top();
                s.pop();
                
                int area_with_tp = heights[tp] * (s.empty() ? i : i - s.top() -1);
                
				max_area = max(max_area,area_with_tp);
        }
        return max_area;
    }
};
