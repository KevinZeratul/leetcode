class Solution {
public:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if( i<0 || i>=rows || j<0 || j>=cols || board[i][j]!=word[k]) return false;
        if(k == word.size() - 1) return true;

        board[i][j] =  '\0';
        bool res = dfs(board, word, i+1, j, k+1) || dfs(board, word, i, j+1, k+1) ||
        dfs(board, word, i, j-1, k+1) || dfs(board, word, i-1, j, k+1);
        board[i][j] = word[k];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};