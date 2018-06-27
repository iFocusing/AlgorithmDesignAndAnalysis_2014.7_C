#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN 100

int x[LEN],n;
int sum=0;

int Place(int k){
     for(int j=1;j<k;j++){
             if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) return 0;
     }
     return 1;       
}

void BackTrace(int t){
     if(t>n) {
             sum++;
             for(int i=1;i<=n;i++)
                printf("%d ",x[i]);
     }
     else{
          for(int i=1;i<=n;i++){
                  x[t]=i;
                  if(Place(t)) BackTrace(t+1);       
          }     
     }     
}

int main(){
    printf("Plase input n:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            x[i]=0;        
    }    
    BackTrace(1);
    printf("output:%d\n",sum);
    system("pause");
}
