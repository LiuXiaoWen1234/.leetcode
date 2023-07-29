/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> arr(n, vector<int>(n,0));
        int startx = 0;
        int starty = 0;
        int loop = n/2; //循环多少圈n=3需要循环一圈；n=5需要循环两圈
        int count = 1;
        int flag = 1; //确定每次循环填充几个数，左闭右开第一排填充12

        while(loop>0){
            int i, j;

            //从左到右完成上排
            for(j=startx; j<n-flag; j++){
                arr[starty][j]=count++;
            }

            //从上到下完成右列
            for(i=starty; i<n-flag; i++){
                arr[i][j]=count++;
            }

            //从右向左完成下列
            for(; j>=flag; j--){
                arr[i][j]=count++;
            }

            //从下往上完成左列
            for (; i>=flag; i--){
                arr[i][j]=count++;
            }

            //下一圈开始的位置
            startx += 1;
            starty += 1;
            flag += 1;
            loop--;
        }

        //如果n是奇数，最中间有一个值，将其填充
        if(n%2==1){
            arr[startx][starty]=count;
        }

        return arr;

    }
};
// @lc code=end

