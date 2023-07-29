/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    //小顶堆
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>&rhs){
            return lhs.second>rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计元素出现的频率
        unordered_map<int, int> mmap;
        for( int i=0; i<nums.size(); i++){
            mmap[nums[i]]++;
        }

        //对频率排序,优先队列
        //priority_queue<Type, Container, Functional> Type类型，Container容器类型
        priority_queue <pair<int,int>, vector<pair<int, int>>, mycomparison> pri_que;

        //用固定大小为k的小顶堆，扫描所有频率的数值
        for(unordered_map<int, int>::iterator it = mmap.begin(); it!=mmap.end(); it++){
            pri_que.push(*it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }

        vector<int> result(k);//保存待返回的结果
        for(int i=k-1; i>=0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();

        }
        return result;

    }
};
// @lc code=end

