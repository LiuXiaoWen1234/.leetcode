/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
//注意vector数组的填充push_back 与pop_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //矩阵行数
        int n = matrix[0].size(); //矩阵列数
        vector<int> result;
        //判断行长还是列长
        int fflag = m < n ? m : n;

        int loop = fflag/2; //循环圈数
        int startx = 0;
        int starty = 0;
        int flag = 1;
        int z = 0;

        while(loop>0){
            int x = 0,  y = 0;

            //上排
            for(y=starty; y<n-flag; y++){
                result.push_back(matrix[startx][y]);
            }

            //右列读取
            for(x=startx; x<m-flag; x++){
                result.push_back(matrix[x][y]);
            }

            //下排
            for(;y>=flag;y--){
                result.push_back(matrix[x][y]);
            }

            //左列
            for(; x>=flag; x--){
                result.push_back(matrix[x][y]);
            }

            startx++;
            starty++;
            flag++;
            loop--;
        }

        //若是行>列且列为奇，则循环过程中：中间列未读
        if(m>n && n%2==1){
            while(startx <= m-flag){
                result.push_back(matrix[startx][starty]);
                startx++;
            }
        }else if(n>=m && m%2==1){ //若是列>行且行为奇，则循环过程中：中间行未读
            while(starty <= n-flag){
            result.push_back(matrix[startx][starty]);
            starty++;
            } 
        }

        return result;


    }
};
// @lc code=end

