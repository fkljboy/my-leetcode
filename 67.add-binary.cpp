/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.25%)
 * Total Accepted:    285.3K
 * Total Submissions: 744.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int aLength = a.size();
		int bLength = b.size();
		int maxLength = max(aLength, bLength);
		string result(maxLength, '0');//最大值个‘0’组成的“000...000”串
		//首先进行对齐
		if (aLength < bLength){
			a = string(bLength - aLength, '0') + a;
		}
		else{
			b = string(aLength - bLength, '0') + b;
		}
		//然后从最低到下标为1的相加、进位
		for (int i = maxLength - 1; i > 0; --i){
			result[i] += a[i] - '0' + b[i] - '0';//相加
			if (result[i] >= '2'){//进位
				result[i - 1] += 1;
				result[i] -= 2;
			}
		}
        //最后处理最高位
		result[0] += a[0] - '0' + b[0] - '0';//最高位相加
		if (result[0] >= '2'){//最高位进位
			result[0] -= 2;
			result = '1' + result;
		}
		return result;
    }
};
/*字符串元素str[i]-'0'可以将一个字符类型转换为int类型 因为减去'0'
其实就是减去了'0'的ASCII码
