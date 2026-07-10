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
    
    void helper(vector<vector<string>> &ans, vector<string> &board, int n,  int current_col, vector<int> upper_left_dia, vector<int> lower_left_dia, vector<int> left_row){

        if(current_col == n){
            ans.push_back(board);
            return;
        }

        // for(int i = 0; i < n; i++){
        //     if(if_possible(board, n, i, current_col)){
        //         board[i][current_col] = 'Q';
        //         helper(ans, board, n, current_col+1);

        //         //backtracking
        //         board[i][current_col] = '.';
        //     }
        // }
        for(int i = 0; i < n; i++){
            if(left_row[i] == 0 && lower_left_dia[i+current_col] == 0 && upper_left_dia[(n-1)+(current_col-i)] == 0){
                left_row[i] = 1;//means a queen is there
                lower_left_dia[i+current_col] = 1;//means a queen is there
                upper_left_dia[(n-1)+(current_col-i)] = 1;//means a queen is there

                board[i][current_col] = 'Q';
                helper(ans, board, n, current_col+1, upper_left_dia, lower_left_dia, left_row);

                //backtracking
                board[i][current_col] = '.';
                left_row[i] = 0;//means a queen is not there
                lower_left_dia[i+current_col] = 0;//means a queen is not there
                upper_left_dia[(n-1)+(current_col-i)] = 0;//means a queen is not there

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

        vector<int> upper_left_dia(2*n - 1, 0), lower_left_dia(2*n-1, 0), left_row(n,0);
        helper(ans, board, n, 0, upper_left_dia, lower_left_dia, left_row);

        return ans; 
    }
};