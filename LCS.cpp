#include <iostream>
#include <cstring>
#define MAXN 10005
using namespace std;

int dp[MAXN][MAXN];
/* ****
** usage-��������ַ����Ĺ����Ӵ�
** param-��һ���ַ������ڶ����ַ�����������Ӵ���������Ӵ�����
** ���Ӷ�-O(mn), ����m��n�ֱ�Ϊ�����ַ����ĳ���
*/
void LCS(string s1, string s2, string & common_string, int & max_len)
{
    int len1=s1.length();
    int len2=s2.length();
    int start=0; // ��Ӵ���ʼλ��
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
                    int start_temp = i - dp[i][j] + 1; // ��¼��ǰ����Ӵ���s1�п�ʼλ��
                    if(start_temp==start) // �����ͬһ���Ӵ�
                    {
                        string s="X";
                        s[0]=s1[i];
                        common_string.append(s);
                    }
                    // ����ֵ�´�
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
    cout<<"�������һ���ַ�����"<<endl;
    cin>>str1;
    cout<<"������ڶ����ַ�����"<<endl;
    cin>>str2;
    memset(dp,0,sizeof(dp));
    LCS(str1,str2,common,length);
    cout<<"������Ӵ�Ϊ��"<<common<<"\n�䳤��Ϊ��"<<length<<endl;
    return 0;
}
