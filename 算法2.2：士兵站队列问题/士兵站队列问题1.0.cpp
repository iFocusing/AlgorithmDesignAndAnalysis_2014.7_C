/*问题描述：士兵站队列问题：选择一个位置使所有士兵以它为起点排成一行所走的总距离最远； （先把数据用快速排序全部排好序，再找出中位数，这种方法并不是寻找中位数最优的算法）； 
步骤：1.输入各士兵的位置（横坐标存放在a数组，纵坐标存放在b数组）；
      2.用快速排序算法对a，b数组排序；
      3.b数组的中位数位置就是y的位置，用a数组的中位数来确定x的位置；
      4.计算总距离输出； 
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
    int a[LEN],b[LEN],x;
    printf("请输入士兵总数目：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            } 
    //用快速排序对a，b数组进行排序； 
    QuickSort(a,0,n-1);  
    QuickSort(b,0,n-1);
    int k;
    k=(n-1)/2;   //确定中位数的位置； 
    x=a[k]-k;  //x的位置； 
    for(int i=0;i<n;i++){
        sum+=abs(a[i]-(x+i))+abs(b[i]-b[k]);   //计算士兵排成一行所走的距离总和；     
    }
    printf("各士兵排成一行所走的距离总和：%d\n",sum);
    system("pause");
    return 0;
    } 
