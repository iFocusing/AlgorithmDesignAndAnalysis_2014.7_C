#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Sample
{
 int bi;
 int ei;
}s[10010]; 
int cmp(const void *a,const void *b)
{
    return (*(Sample *)a).ei>(*(Sample *)b).ei?1:-1;
}
int main()
{  
 int m,n,i,j,num,a;
 scanf("%d",&m);
 while(m--){
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%d %d",&s[i].bi,&s[i].ei);
  qsort(s,n,sizeof(s[0]),cmp);
  num=1;
  for(i=0;i<n-1;)
  {   a=0;
   for(j=i+1;j<n;j++)//此 for 循环从 1 到  n 全部进行了判断，所以判断结束后如果 a=0, 则说明没有可以再
                                                         //安排的活动了 ，所以 a=0就可以直接不用再判断了 
   {
    if(s[j].bi>s[i].ei)
    {
     num++;
     i=j;
     a=1;
     break;
    }
   }
   if(a==0)
   break;
     
  }
  printf("%d\n",num);
 }
 return 0;
}
