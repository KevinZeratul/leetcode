/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int good = 0;
        int ans = 0;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, 1, -1, 0};
        queue<pair<int,int>> rot;
        for (int i = 0; i < row; ++i){  // 烂橘入队
            for (int j = 0; j < col; ++j){
                if (grid[i][j] == 2)
                    rot.push({i, j});
                if (grid[i][j] == 1)
                    ++good;
            }
        }

        while (!rot.empty()){
            int vol = rot.size();  // 烂橘数量
            for (int i = 0; i < vol; ++i){  // 当前步所有烂橘出队，向四个方向污染
                auto cur = rot.front();
                rot.pop();
                for (int a = 0; a < 4; ++a){
                    int nextx = cur.first + dx[a];
                    int nexty = cur.second + dy[a];
                    if (nextx >= 0 && nextx < row && nexty >= 0 && nexty < col 
                    && grid[nextx][nexty] == 1){
                        grid[nextx][nexty] = 2;
                        --good;
                        rot.push({nextx, nexty});
                    }
                }
            }
            if (!rot.empty)  // 若为空说明当前步没有污染橘子
                ++ans;
        }
        return good == 0 ?  res : -1;
    }
};
// @lc code=end

