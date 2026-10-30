class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<char> board(9, ' ');
        vector<vector<int>> winningPatterns = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                                               {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                                               {0, 4, 8}, {2, 4, 6}};

        // Place moves on the board
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            int index = row * 3 + col;

            // A plays X, B plays O
            board[index] = (i % 2 == 0) ? 'X' : 'O';

            // Check winning patterns
            for (auto pattern : winningPatterns) {
                int pos0 = board[pattern[0]];
                int pos1 = board[pattern[1]];
                int pos2 = board[pattern[2]];

                if (pos0 != ' ' && pos0 == pos1 && pos1 == pos2) {
                    return pos0 == 'X' ? "A" : "B";
                }
            }
        }

        // All 9 cells filled and nobody won

        if (moves.size() == 9) {
            return "Draw";
        }

        return "Pending";
    }
};