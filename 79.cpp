/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i < board.size(); i++)
            for(int j=0; j < board[0].size(); j++)
                if(DFS(i, j, board, word))
                    return true;
        return false;
    }
    
    bool DFS(int i, int j, vector<vector<char>>& board, string& word)
    {
        if(word.size() == 0) return true;
        if( i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() || 
            board[i][j] != word[0]) return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);  // turncates one letter from beginning of string
        bool ans = DFS(i+1, j, board, s) || DFS(i-1, j, board, s)
                || DFS(i, j+1, board, s) || DFS(i, j-1, board, s);
        board[i][j] = c;
        return ans;
    }
        
};
