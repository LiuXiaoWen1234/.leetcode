/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
private:

    //判断该数字，在该格子填入是否满足规则
    bool isValid(vector<vector<char>>& board, int row, int col, int num){
        //每一列只能出现一次
        for(int i=0; i<9; i++){
            if(board[i][col]==num) return false;
        }
        //每一行只能出现一次
        for(int j=0; j<9; j++){
            if(board[row][j]==num) return false;
        }
        //3x3子网格只能出现一次
        int r = row/3;
        int c = col/3;
        for(int i=r*3; i<r*3+3; i++){
            for(int j=c*3; j<c*3+3; j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){ //逐行进行
            for(int j=0; j<board[0].size(); j++){//该行的所有列
                if(board[i][j]!='.') continue;
                for(char k='1'; k<='9'; k++){
                    if(isValid(board, i, j, k)){
                        board[i][j]=k;
                        //添加if并返回的作用为：最后找到解后，回溯回来，为了避免下一个语句改为'.'，需要直接返回
                        if(backtracking(board)) return true;//递归一次只在棋盘上填一个数
                        //backtracking(board);
                        board[i][j]='.';
                    }
                }
                return false; //9个都试完都不可以就返回false
            }
        }
        //等到填完9行9列，会进不去循环了
        return true; //遍历完没有返回false，说明找到合适解

    }


public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

