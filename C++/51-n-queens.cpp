class Solution {
public:
    bool check_legal(vector<string> queue, int row, int col, int n){
        int min = std::min(row, col);
        int x = row - min, y = col - min;
        while(x < n && y < n){
            if(queue[x++][y++] == 'Q')return false;
        }

        x = 0, y = col + row;
        while(x < n && y >= 0){
            if(queue[x++][y--] == 'Q')return false;
        }
        return true;
    }

    void dfs(vector<vector<string>>& ans, vector<string> queue, int row, vector<bool> flags, int n){
        if(row == n){
            ans.push_back(queue);
            return;
        }
        for(int j = 0; j < flags.size(); ++j){
            if(flags[j] && check_legal(queue, row, j, n)){
                flags[j] = false;
                queue[row][j] = 'Q';
                dfs(ans, queue, row + 1, flags, n);
                flags[j] = true;
                queue[row][j] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> queue;
        vector<bool> flags;
        for(int i = 0; i < n; ++i){
            string s;
            for(int j = 0; j < n; ++j){
                s.push_back('.');
            }
            queue.push_back(s);
            flags.push_back(true);
        }
        dfs(ans, queue, 0, flags, n);
        return ans;
    }
};
