class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.rbegin(), left.rend());
        sort(right.begin(), right.end());
  
        if (right.empty())
            return left.front();
        if (left.empty())
            return n - right.front();

        return max(n - right.front(), left.front());
    }
};
