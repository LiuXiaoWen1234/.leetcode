/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
/*
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumab; //key存放ab相加之和，value存放出现次数
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                sumab[sum]++;
            }
        }

        int count = 0;
        for(int i=0; i<nums3.size(); i++){
            for(int j=0; j<nums4.size(); j++){
                int tmp = 0 - nums3[i] - nums4[j];
                auto iter = sumab.find(tmp);
                if(iter!=sumab.end()){
                    count = count + iter->second;
                }
            }
        }

        return count;
    }
    
};
*/
//简洁版加深理解
class Solution{
public:
    int fourSumCount(vector<int>&nums1, vector<int>&nums2, vector<int>&nums3, vector<int>&nums4){
        unordered_map<int, int> sumab;
        for(int a : nums1){
            for(int b:nums2){
                sumab[a+b]++;
            }
        }
        int count =0;
        for(int c:nums3){
            for(int d:nums4){
                if(sumab.find(-c-d)!=sumab.end()){
                    count += sumab[-c-d];
                }
            }
        }
        return count;
    }

};
 
// @lc code=end

