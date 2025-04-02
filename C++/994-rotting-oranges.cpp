class Solution {
public:
    void handle_rot(queue<pair<int, int>> &rot, set<pair<int, int>> &unrot, int x, int y, int m, int n){
        if(x < 0 || x >= m || y < 0 || y >= n)return;
        if(unrot.find({x, y}) != unrot.end()){
            unrot.erase({x, y});
            rot.push({x, y});
        }

    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rot;
        set<pair<int, int>> unrot;
        // 构建队列以及集合
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)unrot.insert({i, j});
                if(grid[i][j] == 2)rot.push({i, j});
            }
        }

        int cnt = 0;
        // 广度优先搜索
        while(!rot.empty()) {
            if(unrot.empty())break;
            int num = rot.size();
            for(int i = 0; i < num; ++i){
                auto idx = rot.front();
                rot.pop();
                int x = idx.first, y = idx.second;
                // 处理上下左右四个角 
                handle_rot(rot, unrot, x - 1, y, m, n);
                handle_rot(rot, unrot, x + 1, y, m, n);
                handle_rot(rot, unrot, x, y - 1, m, n);
                handle_rot(rot, unrot, x, y + 1, m, n);
            }
            cnt++;
        }

        return unrot.empty()? cnt: -1;
    }
};
