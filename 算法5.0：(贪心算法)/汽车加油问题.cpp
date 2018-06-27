//汽车加油问题，先用贪心算法尝试；

#include<stdio.h>
#include<stdlib.h>
#define LEN 100

int qichejiayou(int n,int k,int a[LEN]){
    int m=0;  //m代表加油的次数，使这个函数要返回的值； 
    int q=n;  //q代表车里的油还能行驶多长距离； 
    for(int i=0;i<=k;i++){  
        if(q-a[i]>=0){
            q=q-a[i]; 
            printf("q:%d\n",q);          
        }else{
               m++;
               printf("m:%d\n",m);
               q=n;
               printf("q:%d\n",q);
               i--;
              }
    }
    return m;
}

int main(){
    int n,k;
    int a[LEN];
    int m=0;
    printf("Please input the n & k:\n");
    scanf("%d%d",&n,&k);
    printf("Please input the lenth:\n");
    for(int i=0;i<=k;i++){
            scanf("%d",&a[i]);        
    }    
    m=qichejiayou(n,k,a);
    printf("output:%d\n",m);        
    system("pause");
    return 0;                
} 
