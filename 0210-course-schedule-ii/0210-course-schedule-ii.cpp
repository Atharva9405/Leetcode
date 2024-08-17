class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            graph[prerequisite].push_back(course);
            inDegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topologicalOrder;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            topologicalOrder.push_back(course);
            
            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        if (topologicalOrder.size() == numCourses) {
            return topologicalOrder;
        }
        else {
            return vector<int>();
        }
    }
};