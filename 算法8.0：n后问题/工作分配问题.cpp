/**
工作分配问题 
*/

#include<stdio.h>
#include<stdlib.h>
#define LEN 100
int n,cw,bestw=10000,c[LEN][LEN];
int x[LEN];

int Ok(int k){
    for(int j=1;j<k;j++){
       if(x[j]==x[k]) return 0;
    } 
    return 1;
}
 
 
void BackTrace(int t){
    if(t>n){
        if(cw<bestw){
             bestw=cw;             
        }        
        return;
    }          
    else{
        for(int i=1;i<=n;i++){
            x[t]=i;
            cw+=c[t][i];
            if(Ok(t)){BackTrace(t+1);}
            cw-=c[t][i];
            x[t]=0;        
        }   
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
         scanf("%d",&c[i][j]);         
    BackTrace(1);
    printf("%d\n",bestw);
    system("pause");
    return 0;  
}
