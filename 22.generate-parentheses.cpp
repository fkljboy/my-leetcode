class Solution {
public:
    vector<string> ans={};
    void back(string s,int l,int r,int max)
    {
        
        if (s.size()==max*2) {
            ans.push_back(s);
            return ;
        }
        if(l<max) back(s+"(",l+1,r,max);
        
        if(r<l)  back(s+")",l,r+1,max);

    }
    vector<string> generateParenthesis(int n) {
  
        
        back("",0,0,n);
        return ans;

    }
};

/*官方java题解的c++做法 ，区别在于 在java题解中 使用的是引用传递而不是值传递 所以可以将
ans作为函数的一个参数加入递归函数中运行，但是在c++中 它是作为形参存在的，而形参的寿命就是
本函数以内，所以需要将ans作为一个全局变量声明在函数外，其他的好理解 。