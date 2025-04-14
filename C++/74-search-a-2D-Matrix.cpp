class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int l = 0, r = m - 1, mid = 0;
        while(l <= r){
            mid = (l + r) / 2;
            int num = matrix[mid][0];
            if(target == num)return true;
            else if(target < num)r = mid - 1;
            else l = mid + 1;
        }
        int row = (l + r) / 2;
        l = 0, r = matrix[row].size() - 1;
        while(l <= r){
            mid = (l + r) / 2;
            int num = matrix[row][mid];
            if(target == num)return true;
            else if(target < num)r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
