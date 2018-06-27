/*问题抽象归类：（编辑距离问题）

设A和B是2个字符串。要用最少的字符操作将字符串A转换为字符串B。这里所说的字符操作包括:

(1)删除一个字符;
(2)插入一个字符；
(3)将一个字符改为另一个字符。
将字符串A变换为字符串B所用的最少字符操作数称为字符串A到B的编辑距离,记为d(A,B)。试设计一个有效算法,对任给的2个字符串A和B,计算出它们的编辑距离d(A,B)。
要求：
输入：第1行是字符串A,第2行是字符串B。
输出：字符串A和B的编辑距离d(A,B)

 

 

思路：动态规划

开一个二维数组d[i][j]来记录a0-ai与b0-bj之间的编辑距离，要递推时，需要考虑对其中一个字符串的删除操作、插入操作和替换操作分别花费的开销，从中找出一个最小的开销即为所求

具体算法：

首先给定第一行和第一列，然后，每个值d[i,j]这样计算：d[i][j]   =   min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+(s1[i]  ==  s2[j]?0:1));   
最后一行，最后一列的那个值就是最小编辑距离
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
