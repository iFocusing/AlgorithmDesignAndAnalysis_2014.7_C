#include<stdio.h>
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

int main(){
    int a[9];
    int i,n,j,k;
    FILE *p;
    
    p=fopen("D:\\t1.txt","r");
    if (p == NULL)
        exit(0);
      
    while (!feof(p)){
    fscanf(p,"%d",&n);
    printf("���ļ��ж�ȡ��ҳ������%d\n",n); 
    for(i=0;i<=9;i++)
      a[i]=0;
    for(i=1;i<=n;i++){
       k=i%10;
       a[k]++;
       j=i/10;
       while(j!=0){
          k=j%10;
          a[k]++;
          j=j/10;       
         }   
      }
    for(i=0;i<=9;i++){
      printf("����%d���ֵĴ���Ϊ:%d\n",i,a[i]);  
    }
    SaveToFile(n,a);
    printf("�Ѿ����浽�ļ���;\n");
    }
    getchar();getchar();getchar();getchar();
    return 0;
    }


