/**��С��������������⣺
���ݽṹ��
    �������ݣ���c[i][j]�洢��i�������ڵ�j����Ӧ�����򵽵ļ۸�
              ��w[i][j]��ʾ��i�������ڵ�j����Ӧ�����򵽵�������
              n��ʾ��n��������
              m��ʾ��m����Ӧ�̣�
              d��ʾ���Ž�ļ۸����ޣ�Լ���������� 
    ��ʱ���ݣ�x[i]�洢ÿ�������Ĺ�Ӧ�̣�
              cw�洢ÿ��·���������ͣ� 
    ������ݣ�bestw��ʾ��С���������Ž�ģ���
              bestx[i]��ʾÿ�������Ĺ�Ӧ�̣����Ž�ģ���
�㷨˼�룺
    ���û��ݷ���BackTrace��int k���������� 
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
    printf("ִ��BackTrace��%d��\n",t);
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
