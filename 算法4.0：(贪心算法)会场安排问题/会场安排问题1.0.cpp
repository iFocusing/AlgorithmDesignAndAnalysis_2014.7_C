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
   for(j=i+1;j<n;j++)//�� for ѭ���� 1 ��  n ȫ���������жϣ������жϽ�������� a=0, ��˵��û�п�����
                                                         //���ŵĻ�� ������ a=0�Ϳ���ֱ�Ӳ������ж��� 
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
