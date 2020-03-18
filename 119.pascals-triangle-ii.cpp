/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
     vector<int> temp,pre;
        if(rowIndex == 0)
        {
            temp.push_back(1);
            return temp;
        }
         for(int i = 0; i < rowIndex+1; ++i)
        {
            temp.clear(); 
            temp.push_back(1);//在每一层的开始的地方弹入一个1
            for(int j = 1; j < i; ++j)
            {
                temp.push_back(pre[j] + pre[j -1]);
            }
            if(i > 0)
            temp.push_back(1);//在每层的结束地方弹入一个1
            pre=temp;
        }
        return temp;
    }
};
/*和上题的区别在于，取消了大的动态数组，然后将temp.clean()置于最前
用于清空

