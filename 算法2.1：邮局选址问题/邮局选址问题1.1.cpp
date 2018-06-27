#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LEN 100
/*邮局选址问题；共有n个坐标（x，y）；我们可以分别求Xi，Yi的中位数；
*/ 
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
    if(p==r) {
      printf("\n\n找到中位数："); 
	  return a[p];
	} 
    system("pause");
    int i=RandomizedPartition(a,p,r);
    printf("在数组的%d到%d之间找第%d大的数，随机选取到的枢轴是%d\n",p,r,k,i);
    int j=i-p+1;
    printf("枢轴%d之前还有%d个数，",i,j); 
    if(k<=j){ 
        printf("所以选择在%d到%d之间选第%d大的数\n",p,i,k);
		return RandomizedSelect(a,p,i,k);
	} 
    else {
    	printf("所以选择在%d到%d之间选第%d大的数\n",i+1,r,k-j);
		return RandomizedSelect(a,i+1,r,k-j);
	}
}
int main(){
    int n,w,aMid,bMid,k,i;//j;//j未用到 
    int b[LEN],a[LEN];
    printf("总油田个数:\n");
    scanf("%d",&n);
    w=0;
    //5 1 2 1 3 3 2 2 3 -2 3
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
      scanf("%d",&b[i]);
   }

    k=(n+1)/2;
    aMid=RandomizedSelect(a,0,n-1,k);
    printf("%d  ",aMid);
    
    bMid=RandomizedSelect(b,0,n-1,k);  //mid是排序后第k个元素的值（中位数）； 
    printf("%d  ",bMid);
    
    for(i=0;i<n;i++)
     w=w+abs(bMid-b[i])+abs(aMid-a[i]);
    printf("%d",w);
   
    getchar();getchar();
    
    return 0;
}
