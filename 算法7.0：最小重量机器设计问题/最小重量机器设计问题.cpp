/**最小重量机器设计问题：
数据结构：
    输入数据：用c[i][j]存储第i个部件在第j个供应商中买到的价格；
              用w[i][j]表示第i个部件在第j个供应商中买到的重量；
              n表示有n个部件；
              m表示有m个供应商；
              d表示最优解的价格上限（约束条件）； 
    临时数据：x[i]存储每个部件的供应商；
              cw存储每条路径的重量和； 
    输出数据：bestw表示最小重量（最优解的）；
              bestx[i]表示每个部件的供应商（最优解的）；
算法思想：
    借用回溯法的BackTrace（int k）来遍历； 
*/

#include<stdio.h>
#include<stdlib.h>
#define LEN 100
int d,n,m;
int x[LEN],bestx[LEN],bestw=50,cw,c[LEN][LEN],w[LEN][LEN];

int Ok(int k){
    int s=0;
    for(int j=1;j<=k;j++){
            int p=x[j];
            s=s+c[j][p];
    } 
    printf("s=%d\n",s);   
    if(s>d) return 0;
    return 1;
}
 
 
void BackTrace(int t){
    printf("执行BackTrace（%d）\n",t);
    if(t>n){
        if(cw<bestw){
             for(int j=1;j<=n;j++) bestx[j]=x[j];
             bestw=cw;             
        }        
        return;
    }          
    else{
        for(int i=1;i<=m;i++){
            x[t]=i;
            cw+=w[t][i];printf("cw=%d\n",cw);
            if(Ok(t)){BackTrace(t+1);}
            cw-=w[t][i];
            x[t]=0;        
        }   
    }
}


int main(){
    scanf("%d %d %d",&n,&m,&d);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
         scanf("%d",&c[i][j]);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
         scanf("%d",&w[i][j]);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
        printf("%d ",c[i][j]);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
         printf("%d ",w[i][j]);
         
         
    BackTrace(1);
    printf("%d\n",bestw);
    for(int i=1;i<=n;i++)
         printf("%d",bestx[i]); 
         
    system("pause");
    return 0;  
}
