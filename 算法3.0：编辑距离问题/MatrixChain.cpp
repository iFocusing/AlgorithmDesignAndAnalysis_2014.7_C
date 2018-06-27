/*穷举法;
1.先找到最优的完全加括号次序； 
2.穷举各种可能，比较找出最小的（记录这种可能）； 
  
A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25  

p[0-6]={30,35,15,5,10,20,25}  
  
int RecurMatrixChain(int i,int j,int **s,int *p);//递归求最优解  
void Traceback(int i,int j,int **s);//构造最优解  
*/

#include<stdio.h>
#include<stdlib.h>
#define L 7 
int g=0;   
/*矩阵连乘的动态规划法*/
void MatrixChain(int p[L-1],int n,int m[][L-1],int s[][L-1]){
    for(int i=0;i<n;i++) m[i][i]=0;    //构造m这个二维数组；主对角线上的数都为0；
     
    for(int r=1;r<n;r++){              //r表示要计算多少个斜对角； 
        for(int i=0;i<n-r;i++){       //i控制上三角每一个斜对角需要计算元素的个数； 
            int j=i+r;       
            m[i][j]=m[i][i]+m[i+1][j]+p[i]*p[i+1]*p[j+1]; // 数组越界 、？？？？？？？？？？
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(t<m[i][j]) {m[i][j]=t;s[i][j]=k;}        
            } 
        }        
    }    
} 
void Traceback(int i,int j,int s[L-1][L-1]){
     if(i==j) return;
     if(j!=i+1){
                g++;
     printf("第%d次从A%d后面断开；\n",g,s[i][j]);
     }
     Traceback(i,s[i][j],s);
     Traceback(s[i][j]+1,j,s);
}
  
int main(){
    int m[L-1][L-1],s[L-1][L-1];
    int p[L]={30,35,15,5,10,20,25};
    int n=6;
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++){
          m[i][j]=0;
          s[i][j]=0;
          }
    MatrixChain(p,n,m,s);
    printf("此矩阵连乘最少的相乘次数为：%d\n",m[0][n-1]);
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          printf("%5ld    ",m[i][j]);
          }
       printf("\n");
       }
    printf("\n\n\n");
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
          printf("%5ld    ",s[i][j]);
          }
       printf("\n");
       }
    printf("此矩阵连乘的最优完全加括号为：\n");
    Traceback(0,n-1,s);
    getchar();
    system("pause");
    return 0;       
}
