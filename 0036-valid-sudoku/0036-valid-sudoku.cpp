class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i< 9; i++){
            int freq[9] = {0};
            for(int j = 0; j <9; j++){
                if(board[i][j] == '.') continue;
                freq[board[i][j] - '1']++;
                if(freq[board[i][j] - '1'] >1) return false;
            }
        }
        for(int i = 0; i< 9; i++){
            int freq[9] = {0};
            for(int j = 0; j <9; j++){
                if(board[j][i] == '.') continue;
                freq[board[j][i] - '1']++;
                if(freq[board[j][i] - '1'] >1) return false;
            }
        }

        for(int row = 0; row<9; row+=3){
            for(int col = 0; col< 9; col+=3){
                vector<int> freq(9,0);

                for(int i = row; i<row+3; i++){
                    for(int j = col; j< col+3; j++){
                        if(board[i][j] == '.') continue;
                        freq[board[i][j] - '1']++;
                        if(freq[board[i][j] - '1'] > 1) return false;
                    }
                }
            }
        }


        return true;
    }
};