#include <iostream>
#include <cstring>
#define MAXN 10005
using namespace std;

int dp[MAXN][MAXN];
/* ****
** usage-求解两个字符串的公共子串
** param-第一个字符串、第二个字符串，最长公共子串、最长公共子串长度
** 复杂度-O(mn), 其中m、n分别为两个字符串的长度
*/
void LCS(string s1, string s2, string & common_string, int & max_len)
{
    int len1=s1.length();
    int len2=s2.length();
    int start=0; // 最长子串起始位置
    if(s1=="" || s2=="")
        max_len=0;
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(s1[i]==s2[j])
            {
                if(i>0&&j>0)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=1;
                }
                if(max_len<dp[i][j])
                {
                    max_len=dp[i][j];
                    int start_temp = i - dp[i][j] + 1; // 记录当前最长的子串在s1中开始位置
                    if(start_temp==start) // 如果是同一个子串
                    {
                        string s="X";
                        s[0]=s1[i];
                        common_string.append(s);
                    }
                    // 否则赋值新串
                    else
                    {
                        start=start_temp;
                        common_string=s1.substr(start,i+1);
                    }
                }
            }
        }
    }
}

int main()
{
    string str1,str2;
    string common="";
    int length=0;
    cout<<"请输入第一个字符串："<<endl;
    cin>>str1;
    cout<<"请输入第二个字符串："<<endl;
    cin>>str2;
    memset(dp,0,sizeof(dp));
    LCS(str1,str2,common,length);
    cout<<"最长公共子串为："<<common<<"\n其长度为："<<length<<endl;
    return 0;
}
