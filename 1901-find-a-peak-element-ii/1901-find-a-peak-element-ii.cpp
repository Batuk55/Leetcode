class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        if(m == 1 && n == 1) return {0,0};
        //single row
        if(m==1){
            if(mat[0][0] > mat[0][1]) return {0,0};
            if(mat[0][n-1] > mat[0][n-2]) return {0,n-1};
            for(int i = 1 ; i < n-1 ; i++){
                if(mat[0][i] > mat[0][i+1] &&
                 mat[0][i] > mat[0][i-1]) return {0,i};
            }
            return {0, 0};
        }
        if(n==1){
            if(mat[0][0] > mat[1][0]) return {0,0};
            if(mat[m-1][0] > mat[m-2][0]) return {m-1,0};
            for(int i = 1 ; i < m-1 ; i++){
                if(mat[i][0] > mat[i+1][0] && mat[i][0] > mat[i-1][0]) return {i,0};
            }
            return {0, 0};
        }

        if(mat[0][0] > mat[0][1] && mat[0][0] > mat[1][0]) return {0,0};
        if(mat[0][n-1] > mat[0][n-2] && mat[0][n-1] > mat[1][n-1]) return {0,n-1};
        if(mat[m-1][0] > mat[m-1][1] && mat[m-1][0] > mat[m-2][0]) return {m-1,0};
        if(mat[m-1][n-1] > mat[m-1][n-2] && mat[m-1][n-1] > mat[m-2][n-1]) return {m-1,n-1};



        for(int i = 1 ; i < n-1 ; i++){
            if(mat[0][i] > mat[0][i-1] && mat[0][i] > mat[0][i+1] && mat[0][i] > mat[1][i] ) return {0,i};
            if(mat[m-1][i] > mat[m-1][i-1] && mat[m-1][i] > mat[m-1][i+1] && mat[m-1][i] > mat[m-2][i] ) return {m-1,i};
        }
        // for(int i = 1 ; i < n ; i++){
        // }


        for(int i = 1 ; i < m-1 ; i++){
            if(mat[i][0] > mat[i-1][0] && mat[i][0] > mat[i+1][0] && mat[i][0] > mat[i][1] ) return {i,0};
            if(mat[i][n-1] > mat[i-1][n-1] && mat[i][n-1] > mat[i+1][n-1] && mat[i][n-1] > mat[i][n-2] ) return {i,n-1};
        }
        // for(int i = 1 ; i < m ; i++){
        // }

        for(int i = 1; i < m-1 ; i++ ){
            for(int j = 1; j < n-1 ; j++){
                if(mat[i][j] > mat[i-1][j] &&
                 mat[i][j] >mat[i][j-1] && 
                 mat[i][j] > mat[i+1][j] && 
                 mat[i][j] > mat[i][j+1]){
                    return {i,j};
                 }
            }
        }
        return {0, 0};
        
    }
};