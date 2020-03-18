/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;

    }
};
/*这里用vector<string> rows(min(numRows, int(s.size())));这个语句 将一个一维的vector数组当做一个
二维数组来使用 （与“rows[curRow] += c;”这一行组合使用），这样实现的效果就是可以使蛇形排列的每一“行”
存入同一个字符串中，而所有行则保存于vector rows中  至于蛇形走位的问题，就可以从上到下，遇到底就往回倒
直到遍历完所有的字符串元素。



class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};

/*方法二是纯粹的找规律，发现所有位于第一行的字母的索引都符合k(2⋅numRows−2)
以此类推得到各字母的所在行，