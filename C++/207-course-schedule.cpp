class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        // 入度向量
        vector<int> in_degree(numCourses, 0);
        stack<int> s;
        // 构建图
        for(int i = 0; i < prerequisites.size(); ++i){
            int start = prerequisites[i][0], end = prerequisites[i][1];
            graph[start][end] = true;
            in_degree[end]++;
        }
        for(int i = 0; i < numCourses; ++i){
            if(in_degree[i] == 0){
                s.push(i);
            }
        }
        // 拓扑排序检查是否有环路
        while(!s.empty()) {
            int i = s.top();
            s.pop();
            for(int j = 0; j < numCourses; ++j){
                if(graph[i][j]){
                    graph[i][j] == false;
                    in_degree[j]--;
                    if(in_degree[j] == 0)s.push(j);
                }
            }
        }

        bool check = true;
        for(int i = 0; i < numCourses; ++i){
            if(in_degree[i] != 0)check = false;
        }
        return check;
    }
};
