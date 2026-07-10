class Solution {
public:
    bool if_possible(vector<string> &board, int n, int i, int current_col){

        int row = i;
        int col = current_col;

        int a = 0;
        //check entire column
        // for(a = 0; a < n; a++){
        //     if(board[a][col] == 'Q'){
        //         return false;
        //     }
        // }  //there will be 1 queen only in every iteration of if_possible()    

        //check entire row
        for(a = 0; a<col; a++){ //        for(a = 0; a< n; a++){ because (col) aur uske ke baad to sirf '.' honge
            if(board[row][a] == 'Q'){
                return false;
            }
        }
        //check diagonals //No need to check the right side because no queens have been placed there yet.
        // top left
        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // bottom left
        row = i;
        col = current_col;
        while(row<n && col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;

    }
    
    void helper(vector<vector<string>> &ans, vector<string> &board, int n,  int current_col){
        if(current_col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            if(if_possible(board, n, i, current_col)){
                board[i][current_col] = 'Q';
                helper(ans, board, n, current_col+1);

                //backtracking
                board[i][current_col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n,'.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }

        helper(ans, board, n, 0);

        return ans; 
    }
};