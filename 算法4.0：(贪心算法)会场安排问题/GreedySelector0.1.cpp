/*�᳡�������⣻
�������������㹻��Ļ᳡����һϵ�л��Ҫ�󾡿���ʹ�����ٵĻ᳡��
����취��̰���㷨��
*/

#include<stdio.h>
#include<stdlib.h>
#define L 100 

void GreedySelector(int n,int *s,int *f,bool *a){
     *a=true;
     for(int i=1;i<n;i++){
             if(*(s+i)>=*f)//&&*(a+i)==false) 
             {
             *(a+i)=true; 
             f=&f[i];
             printf("\n%d ",a[i]);
             printf("\n%d %d\n",s[i],f[0]);
             }else
             {
             printf("\n%d ",a[i]);
             printf("\n%d %d\n",s[i],f[i]);
             }
     }     
}

int main(){
    int n;        //n����������
    int s[L],f[L];  //s[]�洢ÿ�����ʼ��ʱ�䣬j[]�洢ÿ���������ʱ�䣻���ջ����ʱ���С�����˳��洢��
    bool a[L];     //a[]�����¼�ʱ���Ƿ����ݣ�  
    printf("Please input the number:");
    scanf("%d",&n);
    printf("Please input the begin time and the end time:\n");
    for(int i=0;i<n;i++){
          a[i]=false;
          scanf("%d%d",&s[i],&f[i]);
          }        
    int p=0;
    int l=0;
    for(int l=0;l<n;l++){
            if(!a[l]){
                   printf("��̽l��ֵ��%d\n",l);
            GreedySelector(n-l,&s[l],&f[l],&a[l]); p++;  
            }
            }
    printf("output:%d",p);
   
    getchar();  getchar();  getchar();  getchar();  getchar();  getchar();
    system("plase");
    return 0;
}
