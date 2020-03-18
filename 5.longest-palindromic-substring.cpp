class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1) return s;//大小为1的字符串必为回文串
        string rev=s;//rev存放s反转结果
        string res;//存放结果
        std::reverse(rev.begin(),rev.end());
        if(rev==s) return s;
        int len=0;//存放回文子串的长度
        for(int i=0;i<s.length();i++)//查找s与rev的最长公共子串
        {
            string temp;//存放待验证子串
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                if(len>=temp.length())
                    continue;
                else if(rev.find(temp)!=-1)//在rev中找到temp
                {
                    string q=temp;//q用来验证temp是否是回文子串
                    std::reverse(q.begin(),q.end());
                    if(q==temp)
                    {
                        len=temp.length();
                        res=temp;
                    }
                }
                else break;
            }
            temp="";
        }
        return res;
    }
};
/*方法一 倒置字符串法 将原字符串倒置 然后逐位寻找公共子串 ，如果存在公共子串 则需要
再加一个判断 判断其本身是不是回文串  所以其实在判断过程中是比较繁琐的 也占用的较多的
时间 所以最好的方法依然是动态规划法*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};
/*详细的分析一下这道题的思路 程序分为以下两步进行，首先我们可以确定的是 “最短的”回文
字符串：单个的字符 都是回文字符串 其次连续两个相同的字符都是回文字符串；
然后，开始从长度为3的字符串开始检索，首先设定长度为3 然后从数列的第一个开始遍历，遍历一遍
以后 ，所有长度为3的子串就全部确定是否为回文串了（注意第一步已经将单个字符的状态全部确定），
然后长度增加为4，遍历（注意第一步已经 将两个字符的状态全部确定），而后就可以通过已经确定的
长度为1,2,3,4的状态，进一步确定后面的所有长度的状态字，最后找到长度最长的。
