//删数问题；

#include<stdio.h>
#include<stdlib.h>
#define LEN 100

int deleteTheNumber(int n,int k){
    int m=0;  //这个函数返回的值，是删除数之后最小的值；
    int i=0;
    int l=0;
    int a[LEN],b[LEN];
    while(n!=0){
        a[i]=n%10;
        n=n/10;
        i++;                   
    }
    l=i;   //l代表数字n的位数；
    printf("\nl:%d\n\n",l);
     
    for(int j=0,i=l-1;i>=0;j++,i--)
       b[j]=a[i];
       
    for(int j=0;j<l;j++)
       printf("%d",b[j]);
    printf("\n\n");
    
    
    for(int h=1;h<=k;h++){
          for(int i=0;i<l-h+1;i++){
                  if(b[i]>b[i+1]){ 
                      for(int j=i;j<l-h;j++){
                         b[j]=b[j+1];        
                         }
                      i--;
                      break;
                  }
                  
          } 
         for(int r=0;r<l-h;r++)
              printf("%d",b[r]); 
        printf("\n");           
    } 
    int s=l-k;  //剩下的数的位数；
    int x=s-1; 
    int y=1;
    while(0!=s){
       m=m+y*b[x--];
       s--;
       y=y*10;
    }
    return m;
}

int main(){
    int n,k,m=0;
    printf("Please input the n & k:\n");
    scanf("%d%d",&n,&k);
    m=deleteTheNumber(n,k);
    printf("output:%d\n",m);
    system("pause");
    return 0;    
} 
