#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void SaveToFile(int n,int *a)
{ 
    FILE *fp1;
    int i;
    fp1=fopen("D:\\t2.txt","a");
	if(fp1==NULL)
	 {
	  printf("Storage file is missing.\n"); 
	  exit(0);
      }
    else
    {
        fprintf(fp1, "%s%d \n", "总页码数为：",n);
        for(i=0;i<=9;i++)
        {          
         fprintf(fp1, "%s%d%s%d \n","数字",i,"出现的次数为：",a[i]);
       }   
    } 
    fclose(fp1);    
}

int main()
{
   int a[10];
   int i,j,k,L;
   int n,len,m;
   FILE *p;
    
    p=fopen("D:\\t1.txt","r");
    if (p == NULL)
        exit(0);
    while (!feof(p)){
    fscanf(p,"%d",&n);
    printf("从文件中读取总页码数：%d\n",n);
    m=n;
    L=ceil(log10(n+1));
    for(i=0;i<10;i++)
       a[i]=0;
    for(j=0;j<L;j++)
    {
        len=ceil(log10(m+1)); 
        k=m/pow(10.0,len-1); //从高位到低位取各个位数的值
        for(i=0;i<10;i++)   //小于K*pow(10.0,len-1)的数数值0-9出现的次数
            a[i]+=k*(len-1)*pow(10.0,len-2);
        for(i=0;i<k;i++)
            a[i]+=pow(10.0,len-1); //在j位小于数值K的数出现的次数
        a[k]+=m-k*pow(10.0,len-1)+1; //在j位数值K的数出现的次数
        m=m-k*pow(10.0,len-1);
        
    }
    for(i=0;i<L;i++) //去掉前导0；
        a[0]-=pow(10.0,i);
   for(i=0;i<=9;i++){
      printf("数字%d出现的次数为:%d\n",i,a[i]);  
    }
    SaveToFile(n,a);
    printf("已经保存到文件中;\n");
   }
   getchar();getchar();getchar();getchar();
  return 0;
}
