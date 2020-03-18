/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L=0,H=numbers.size()-1;
        while (L<H){
            if (numbers[L]+numbers[H]>target) H--;
            else if (numbers[L]+numbers[H]<target) L++;
            else return {L+1,H+1};
        }
        return {-1,-1};
    }
};
/*巧妙利用双指针一个在最前一个在最后 然后如果二者的和大于target则高指针减一 反之低指针加一
知道相等后返回 否则返回未找到 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> result;
        map <int,int> res;
        for (int i=0;i<numbers.size();i++){
            //res.insert(pair<int,int>(numbers[i],i))  这种插入方法是错误的 由于map中不能存在重复的键值insert
            //方法遇到重复的键值是不会执行覆盖操作的 而是将后面的重复键值直接忽略 如果想要实现覆盖 则需要使用下面的方法:

        }
        for (i=0;i<number.size();i++){
                if (res.count(target-number[i])==1){
                    result.push_back(i+1);
                    result.push_back(res[target-number[i]]+1);
                    return result;
                }
        }
        return 0; 
    }
};
/* 第二种方法是利用哈希表的值和索引的对应关系解决该问题 先将所有的元素以“键”的形式存入map 然后遍历
数组 如果map中存在相应和键值和数组中的元素相加等于target 则可以将两个键的“值”返回即可
