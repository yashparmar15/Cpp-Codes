/*There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105*/


class Solution {
public:
    struct stud{
        double avg;
        int p1;
        int p2;
    };
    struct compare {
        bool operator()(stud p1, stud p2)
        {
            return p1.avg < p2.avg;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<stud,vector<stud>,compare> pq;
        for(int i = 0 ; i < classes.size() ; i++){
            stud temp;
            temp.avg = (classes[i][0] + 1) / (classes[i][1] * 1.0 + 1.0) - classes[i][0] / (classes[i][1] * 1.0) ;
            temp.p1 = classes[i][0];
            temp.p2 = classes[i][1];
            pq.push(temp);
        }
        for(int i = 0 ; i < extraStudents ; i++){
            stud temp = pq.top();
            pq.pop();
            // cout << temp.avg << endl;
            temp.avg = (temp.p1 + 2) / (temp.p2 * 1.0 + 2.0) - (temp.p1 + 1.0) / (temp.p2 * 1.0 + 1.0);
            temp.p1++;
            temp.p2++;
            pq.push(temp);
        }
        double ans = 0;
        while(!pq.empty()){
            stud temp = pq.top();
            pq.pop();
            // cout << temp.p1 / (temp.p2 * 1.0) << endl;
            ans = ans + temp.p1 / (temp.p2 * 1.0);
        }
        return ans / classes.size();
    }
};
