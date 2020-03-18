/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> g;
        vector<int> temp;
        if(numRows == 1)
        {
            temp.push_back(1);
            g.push_back(temp);
            return g;
        }
       
        for(int i = 0; i < numRows; ++i)
        {
            temp.push_back(1);//在每一层的开始的地方弹入一个1
            for(int j = 1; j < i; ++j)
            {
                temp.push_back(g[i - 1][j] + g[i - 1][j -1]);
            }
            if(i > 0)
            temp.push_back(1);//在每层的结束地方弹入一个1
            g.push_back(temp);
            temp.clear();
        }
        return g;
    }
};
/* 杨辉三角 首先要保证第一层是1
后面每一层的第一个都是1 最后一个都是1

