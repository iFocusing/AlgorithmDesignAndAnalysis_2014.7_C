#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LEN 100
/*邮局选址问题；共有n个坐标（x，y）；我们可以分别求Xi，Yi的中位数；
*/ 
void SaveToFile(int n)
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
        fprintf(fp1, "%d \n",n); 
    } 
    fclose(fp1);    
}

void Swap(int &a, int &b){
     int temp = a;
     a = b;
     b = temp;
}

int Random(int p, int r){//随机化
   return rand()*(r-p)/32767+p;
}

int Partition(int* a,int p,int r){
    int i=p,j=r+1;
    int x=a[p];
    while(true){
       while(a[++i]<x&&i<r);
       while(a[--j]>x);  //先自减1再比较； 
       if(i>=j) break;
       Swap(a[i],a[j]);            
    }    
    a[p]=a[j];
    a[j]=x;
    return j;
}

int RandomizedPartition(int y[LEN], int p, int r){
    int i = Random(p,r);
    Swap(y[i],y[p]);
    return Partition(y,p,r);
}

int RandomizedSelect(int* a,int p,int r,int k){
    if(p==r) return a[p];
    int i=RandomizedPartition(a,p,r);
    int j=i-p+1;
    if(k<=j) return RandomizedSelect(a,p,i,k);
    else return RandomizedSelect(a,i+1,r,k-j);
}

int main(){
    int n,w,aMid,bMid,k,i,j;
    int b[LEN],a[LEN];
    FILE *p;
    
    p=fopen("D:\\t1.txt","r");
    if (p == NULL){
        printf("无法打开文件"); 
        exit(0);
        }
    while (!feof(p)){
    fscanf(p,"%d",&n);
    printf("从文件中读取总油田个数：%d\n",n);
    w=0;
    for(i=0;i<n;i++){
      fscanf(p,"%d",&a[i]);
      fscanf(p,"%d",&b[i]);
    }
    k=(n+1)/2;
    aMid=RandomizedSelect(a,0,n-1,k);
    bMid=RandomizedSelect(b,0,n-1,k);  //mid是排序后第k个元素的值（中位数）； 
    for(i=0;i<n;i++)
     w=w+abs(bMid-b[i])+abs(aMid-a[i]);
    SaveToFile(w);
    printf("%d",w);
   
    getchar();getchar();getchar();
    return 0;
    }
}
