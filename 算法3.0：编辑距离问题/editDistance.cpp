/*���������ࣺ���༭�������⣩

��A��B��2���ַ�����Ҫ�����ٵ��ַ��������ַ���Aת��Ϊ�ַ���B��������˵���ַ���������:

(1)ɾ��һ���ַ�;
(2)����һ���ַ���
(3)��һ���ַ���Ϊ��һ���ַ���
���ַ���A�任Ϊ�ַ���B���õ������ַ���������Ϊ�ַ���A��B�ı༭����,��Ϊd(A,B)�������һ����Ч�㷨,���θ���2���ַ���A��B,��������ǵı༭����d(A,B)��
Ҫ��
���룺��1�����ַ���A,��2�����ַ���B��
������ַ���A��B�ı༭����d(A,B)

 

 

˼·����̬�滮

��һ����ά����d[i][j]����¼a0-ai��b0-bj֮��ı༭���룬Ҫ����ʱ����Ҫ���Ƕ�����һ���ַ�����ɾ������������������滻�����ֱ𻨷ѵĿ����������ҳ�һ����С�Ŀ�����Ϊ����

�����㷨��

���ȸ�����һ�к͵�һ�У�Ȼ��ÿ��ֵd[i,j]�������㣺d[i][j]   =   min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+(s1[i]  ==  s2[j]?0:1));   
���һ�У����һ�е��Ǹ�ֵ������С�༭����
*/
 

#include <stdio.h>
#include <string.h>
char s1[1000],s2[1000];
int min(int a,int b,int c)
{
    int t = a < b ? a : b;
    return t < c ? t : c;
}
void editDistance(int len1,int len2)
{
    int ** d=new int *[len1+1];
    for (int k=0;k<=len1;k++)
    {
        d[k]=new int [len2+1];
    }
    int i,j;
    for (i = 0;i <= len1;i++)
    {
        d[i][0] = i;
    }
    for (j = 0;j <= len2;j++)
    {
        d[0][j] = j;
    }
    for (i = 1;i <= len1;i++)
    {
        for (j = 1;j <= len2;j++)
        {
            int cost = s1[i] == s2[j] ? 0 : 1;
            int deletion = d[i-1][j] + 1;
            int insertion = d[i][j-1] + 1;
            int substitution = d[i-1][j-1] + cost;
            d[i][j] = min(deletion,insertion,substitution);
        }
    }
    printf("%d\n" ,d[len1][len2]);
    for (int k=0;i<=len1;k++)
    {
        delete[] d[k];
    }
    delete[] d;
}
int main()
{
    while (scanf("%s %s" ,s1,s2) != EOF)
    {
        editDistance(strlen(s1),strlen(s2));
    }
}
