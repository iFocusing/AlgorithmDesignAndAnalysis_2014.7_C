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
        fprintf(fp1, "%s%d \n", "��ҳ����Ϊ��",n);
        for(i=0;i<=9;i++)
        {          
         fprintf(fp1, "%s%d%s%d \n","����",i,"���ֵĴ���Ϊ��",a[i]);
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
    printf("���ļ��ж�ȡ��ҳ������%d\n",n);
    m=n;
    L=ceil(log10(n+1));
    for(i=0;i<10;i++)
       a[i]=0;
    for(j=0;j<L;j++)
    {
        len=ceil(log10(m+1)); 
        k=m/pow(10.0,len-1); //�Ӹ�λ����λȡ����λ����ֵ
        for(i=0;i<10;i++)   //С��K*pow(10.0,len-1)������ֵ0-9���ֵĴ���
            a[i]+=k*(len-1)*pow(10.0,len-2);
        for(i=0;i<k;i++)
            a[i]+=pow(10.0,len-1); //��jλС����ֵK�������ֵĴ���
        a[k]+=m-k*pow(10.0,len-1)+1; //��jλ��ֵK�������ֵĴ���
        m=m-k*pow(10.0,len-1);
        
    }
    for(i=0;i<L;i++) //ȥ��ǰ��0��
        a[0]-=pow(10.0,i);
   for(i=0;i<=9;i++){
      printf("����%d���ֵĴ���Ϊ:%d\n",i,a[i]);  
    }
    SaveToFile(n,a);
    printf("�Ѿ����浽�ļ���;\n");
   }
   getchar();getchar();getchar();getchar();
  return 0;
}
