/*����������ˣ�
��̹����г��ֵ������ǣ���ά�����������βε�ʱ����ôд��*/
#include<stdio.h>
#include<stdlib.h>
#define LEN 100
/**/
void matrixMultiply(int a[][LEN],int b[][LEN],int c[][LEN],int ra,int ca,int rb,int cb){
     int sum=0;
     for(int i=0;i<ra;i++){//�������һ�㣬�˺����㣻 
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
    printf("�������������������ֵ��"); 
    scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
    if(ca!=rb){
         printf("��������������������;\n");
         } 
    printf("���������a(%d*%d)��",ra,ca); 
    for(int i=0;i<ra;i++){
       for(int j=0;j<ca;j++){
          scanf("%d",&a[i][j]);
       }               
    }
    printf("���������b(%d*%d)��",rb,cb); 
    for(m=0;m<rb;m++){
       for(n=0;n<cb;n++){
          scanf("%d",&b[m][n]);
       }               
    }
    for(i=0;i<ra;i++)
      for(j=0;j<cb;j++)
          c[i][j]=0;      
    matrixMultiply(a,b,c,ra,ca,rb,cb);//����������˵ĺ�����
    for(int i=0;i<ra;i++){
      for(int j=0;j<cb;j++){
          printf("%d ",c[i][j]);      
          }
      printf("\n");
      }
    system("pause");
    return 0;
    }
