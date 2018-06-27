/*两个矩阵相乘；
编程过程中出现的问题是：二维数组做函数形参的时候怎么写；*/
#include<stdio.h>
#include<stdlib.h>
#define LEN 100
/**/
void matrixMultiply(int a[][LEN],int b[][LEN],int c[][LEN],int ra,int ca,int rb,int cb){
     int sum=0;
     for(int i=0;i<ra;i++){//最外面的一层，乘和运算； 
         for(int n=0;n<cb;n++){
             for(int j=0;j<ca;j++)
             {
               sum+=a[i][j]*b[j][n];
               } 
              c[i][n]=sum;        
         }        
     }     
}

int main(){
    int ra=0,ca=0,rb=0,cb=0;
    int i,j,m,n;
    int a[LEN][LEN],b[LEN][LEN],c[LEN][LEN];
    printf("请输入两个矩阵的行列值："); 
    scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
    if(ca!=rb){
         printf("输入的这两个矩阵不能相乘;\n");
         } 
    printf("请输入矩阵a(%d*%d)：",ra,ca); 
    for(int i=0;i<ra;i++){
       for(int j=0;j<ca;j++){
          scanf("%d",&a[i][j]);
       }               
    }
    printf("请输入矩阵b(%d*%d)：",rb,cb); 
    for(m=0;m<rb;m++){
       for(n=0;n<cb;n++){
          scanf("%d",&b[m][n]);
       }               
    }
    for(i=0;i<ra;i++)
      for(j=0;j<cb;j++)
          c[i][j]=0;      
    matrixMultiply(a,b,c,ra,ca,rb,cb);//两个矩阵相乘的函数；
    for(int i=0;i<ra;i++){
      for(int j=0;j<cb;j++){
          printf("%d ",c[i][j]);      
          }
      printf("\n");
      }
    system("pause");
    return 0;
    }
