/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/*
//使用哈希数据结构unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());//将nums1的元素全部拷贝给nums1_set

        for(int num : nums2){
            if(nums1_set.find(num)!=nums1_set.end())
                result.insert(num);
        }
        return vector<int>(result.begin(), result.end());

    }
};
*/

//数组方法求解
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result;
        int hash[1005] = {0}; //默认为0
        for( int num : nums1){
            //nums1中出现的字母在hash中做记录
            hash[num]=1;
        }
        for(int num : nums2){
            if(hash[num]==1)
                result.insert(num);
        }

        return vector<int>(result.begin(), result.en
        d());

    }
};

// @lc code=end

