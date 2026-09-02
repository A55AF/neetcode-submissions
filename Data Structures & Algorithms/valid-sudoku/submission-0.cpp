class Solution {
public:
    int idx(int x, int y) {
        int row = x / 3, col = y / 3;
        return row * 3 + col;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9), cols(9), boxes(9);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    rows[i].push_back(c - '0');
                    cols[j].push_back(c - '0');
                    boxes[idx(i, j)].push_back(c - '0');
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            vector<bool> vis(10);
            for(int j = 0; j < rows[i].size(); j++) {
                int cur = rows[i][j];
                if(vis[cur]) return false;
                vis[cur] = true;
            }
        }
        for(int i = 0; i < 9; i++) {
            vector<bool> vis(10);
            for(int j = 0; j < cols[i].size(); j++) {
                int cur = cols[i][j];
                if(vis[cur]) return false;
                vis[cur] = true;
            }
        }
        for(int i = 0; i < 9; i++) {
            vector<bool> vis(10);
            for(int j = 0; j < boxes[i].size(); j++) {
                int cur = boxes[i][j];
                if(vis[cur]) return false;
                vis[cur] = true;
            }
        }
        return true;
    }
};