/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.13%)
 * Total Accepted:    426.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, flag, j;
	vector <char> res;
    string res1;
	int num1 = strs.size() - 1;
	int num2 = strs[0].size() - 1;
	for (i = 0; i < num2; i++)
	{
		for (j = 0; j < num1; j++)
		{
			if (strs[j][i] == strs[j+1][i])
			{
				flag = 1;
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			res.push_back(strs[i][j]);
			continue;
		}
		else
		{
            for(int n=0;n<res.size();n++)
            {
                res1+=res[n]
            }
			return res1;
			break;
		}

	}
    }
};*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string prefix=strs[0];
        for(auto i=1;i<strs.size();i++)
        {
            int j=0,len=min(prefix.size(),strs[i].size());
            while(j<len && prefix[j]==strs[i][j])j++;
            prefix.erase(prefix.begin()+j,prefix.end());
            if(prefix=="")
                break;
        }
        return prefix;
    }
};
/*erase函数可以起到删除元素的作用
（1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
（2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
（3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）