/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int res=0;
        int i=0;
        int flag=1;
        while (str[i]==' ') { i++;}
        if (str[i]=='-') { flag=-1;}
        if (str[i]=='+'||str[i]=='-') i++;
        while (i<str.size()&& isdigit(str[i])){
            int r=str[i]-'0';
            if (res>INT_MAX/10||(res==INT_MAX/10&&r>7)){
                return flag>0? INT_MAX:INT_MIN;
            }
            res=res*10+r;
            i++;
        }
        return flag>0? res : -res;
    }
};
// @lc code=end
/*本题的做法比较直接，将空格直接删去 而后判断是否为正数 由于要求只是找到
最前面的连续的数字作为转换对象，所以直接转换即可，由于设定了数值要求不能
溢出，所以必须要考虑

int myAtoi(string str) {
        int d=0;
        istringstream is(str);
        is>>d;
        return d;
    }

方法二 利用isstringstream中的方法 直接将str转换为int 
