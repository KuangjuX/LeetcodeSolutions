/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief 
 * Double Pointer, O(n), O(1)
 * I didn't come up with a solution for double pointers.
 */

class Solution {
public:
    // Brute force, TimeOut
    // int maxArea(vector<int>& height) {
    //     int len = height.size();
    //     int area = 0;
    //     for(int i = 0; i < len; i++){
    //         for(int j = i + 1; j < len; j++) {
    //             area = max(area, (j - i) * min(height[i], height[j]));
    //         }
    //     }
    //     return area;
    // }

    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0;
        int j = len - 1;
        int area = 0;
        while(i != j) {
            area = max(area, (j - i) * min(height[i], height[j]));
            if(height[j] <= height[i]) {
                j--;
            }else{
                i++;
            }
        }
        return area;
    }
};
// @lc code=end


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() -  1;
        int ans = 0;
        while(l != r){
            ans = std::max(ans, (r - l) * std::min(height[l], height[r]));
            if(height[l] < height[r])l++;
            else r--;
        }
        return ans;
    }
};
