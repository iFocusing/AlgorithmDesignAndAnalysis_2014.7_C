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
        fprintf(fp1, "%s%d \n", "总页码数为：",n);
        for(i=0;i<=9;i++)
        {          
         fprintf(fp1, "%s%d%s%d \n","数字",i,"出现的次数为：",a[i]);
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
    printf("从文件中读取总页码数：%d\n",n); 
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
      printf("数字%d出现的次数为:%d\n",i,a[i]);  
    }
    SaveToFile(n,a);
    printf("已经保存到文件中;\n");
    }
    getchar();getchar();getchar();getchar();
    return 0;
    }


