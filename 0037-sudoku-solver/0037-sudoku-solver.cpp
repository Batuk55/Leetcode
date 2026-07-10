class Solution {
public:
    bool ifPossible(vector<vector<char>>& board, char n, int row, int col){

        //check in row and column
        for(int i = 0; i < 9; i++){
            if(board[row][i] == n) return false;
            if(board[i][col] == n) return false;
        }

        int a = 0, b = 0;
        int a_= 8, b_= 8;

        //check in the box
        if(row < 3){
            if(col < 3){
                a_= 2, b_= 2;
            }
            if(col>=3 && col<6){
                b = 3, a_=2, b_=5;
            }
            if(col>=6){
                b = 6, a_=2, b_=8;
            }
        }
        if(row>=3 && row <6){
            if(col < 3){
                a=3, a_= 5, b_= 2;
            }
            if(col>=3 && col<6){
                a=3, b = 3, a_=5, b_=5;
            }
            if(col>=6){
                a = 3, b = 6, a_=5, b_=8;
            }
        }
        if(row>=6){
            if(col < 3){
                a=6, b_= 2;
            }
            if(col>=3 && col<6){
                a = 6, b = 3, a_=8, b_=5;
            }
            if(col>=6){
                a=6, b = 6;
            }
        }

        for(int i = a; i<=a_; i++){
            for(int j = b; j<=b_; j++){
                if(board[i][j] == n) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board){
        // if(board[i][j] != '.') return;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(board[i][j] == '.'){ 
                    for(char n = '1'; n<='9'; n++){
                        if(ifPossible(board, n, i, j)){
                            board[i][j]= n;

                            if(helper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;// basecase // stopping condition
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
