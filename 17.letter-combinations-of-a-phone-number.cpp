/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char,string> m={{'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}} 
        int size=digits.size();
        queue<string> que;
        for(int j=0;j<m(digits[0]).size();j++){
    `       string str;
			str.push_back(m[digits[0]][j]);//char转string
			que.push(str);//string入队
        }
        string s;//用于存储队头元素
		for (int i = 1; i < size; i++)
		{
			int length = que.size();//当前队列长度
			while (length--)
			{
				for (int j = 0; j < m[digits[i]].size(); j++)
				{
					s = que.front();
					s = s + m[digits[i]][j];//队头元素加上新元素
					que.push(s);//入队
				}
				que.pop();//队头出队
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());//队头元素存储至res
			que.pop();//队头出队
		}
		return res;//返回
    }
};
/*这道题的思路有两种，即深度优先和广度优先，使用队列方法即可实现深度优先遍历
具体实现方法通俗的说就是
首先将第一个数字包含的字母放入队列，依次将后面的各个数字代表的字母入队 并且和
队首的元素组成一个字符串 存入队列末端 并将队首的元素弹出 经过循环 最终队列中
保存的就是所有配好对的字符串 再将其全部弹出即可



// @lc code=end



vector<string> res;
    map<char,string> m={{'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    void backtrack(string combination, string next_digits)
    {
        
        if (next_digits.size()==0)
            res.push_back(combination);
        else 
            for(auto c:m[next_digits[0]]){
                backtrack(combination+c, next_digits.substr(1));
                
    }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size()!=0){
            backtrack("", digits);
        }
        return res;

方法二 ：广度优先遍历方法 ，具体实现方法是递归，深度优先和广度优先的区别是什么呢? 以字符串"23"为例,说白了深度
优先就是先ad ae af  而广度就是先ad bd cd 。 对于递归而言，设定递归的终止条件是全部的digits数列遍历完成，
递归的主体是将第一个数字映射的三个字母分别放入下一层递归，与剩余的数字映射的字母进行配对 知道没有剩余的数字
为止

