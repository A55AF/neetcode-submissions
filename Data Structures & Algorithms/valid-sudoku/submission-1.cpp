class Solution {
public:
    int idx(int x, int y) {
        int row = x / 3, col = y / 3;
        return row * 3 + col;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, boxes;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c == '.') continue;
                if(rows[i].count(c) || cols[j].count(c) || boxes[idx(i, j)].count(c))
                    return false;
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[idx(i, j)].insert(c);
            }
        }
        return true;
    }
};