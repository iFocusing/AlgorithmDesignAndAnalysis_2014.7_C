/*问题描述：邮局选址问题：为邮局选择一个各个农舍到它总距离最小的地址； （先把数据用快速排序全部排好序，再找出中位数，这种方法并不是寻找中位数最优的算法）； 
步骤：1.输入各农舍的位置（横坐标存放在a数组，纵坐标存放在b数组）；
      2.用快速排序算法对a，b数组排序；
      3.确定中位数位置(邮局的地址)，计算各农舍到邮局的距离并输出； 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN 100
void Swap(int &a, int &b){
     int temp = a;
     a = b;
     b = temp;
}

int Partition(int *a,int p,int r){
     int i=p,j=r+1;
     int x=a[p];
     while(true){
          while(a[++i]<x&&i<r);
          while(a[--j]>x);
          if(i>=j) break;
          Swap(a[i],a[j]);            
     } 
     a[p]=a[j];
     a[j]=x;
     return j;    
}

void QuickSort(int *a,int p,int r){
     if(p<r){
      int q=Partition(a,p,r);
      QuickSort(a,p,q-1);
      QuickSort(a,q+1,r);          
     }
}

int main(){
    int n,sum=0;
    int a[LEN],b[LEN];
    printf("请输入油田口数目：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            } 
    //用快速排序对a，b数组进行排序； 
    QuickSort(a,0,n-1);  
    QuickSort(b,0,n-1);
    int k;
    k=(n-1)/2;   //确定中位数的位置，对于本问题就是邮局的地址(a[k],b[k])； 
    for(int i=0;i<n;i++){
        sum+=abs(a[i]-a[k])+abs(b[i]-b[k]);   //计算各个居民点到邮局的距离总和；     
    }
    printf("各数据到中位数的总距离为：%d\n",sum);
    system("pause");
    return 0;
    } 
