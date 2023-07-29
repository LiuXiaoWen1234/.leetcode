/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    bool isValid(int n, int row, int col, vector<string>& chessboard){
        if(row==0) return true;

        //判断同一列
        for(int i=0; i<row; i++){
            if(chessboard[i][col]=='Q') return false;
        }
        //判45度断对角线
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(chessboard[i][j]=='Q') return false;
        }
        //判断135度对角线 
        for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
            if(chessboard[i][j]=='Q') return false;
        }

        return true;
    }


    void backtracking(int n, int row, vector<string>& chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }

        for(int i=0; i<n; i++){
            if(isValid(n, row, i, chessboard)){
                chessboard[row][i]='Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][i]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> chessboard(n, std::string(n,'.'));
        result.clear();
        backtracking(n, 0, chessboard);
        return result;
    }
};
// @lc code=end

