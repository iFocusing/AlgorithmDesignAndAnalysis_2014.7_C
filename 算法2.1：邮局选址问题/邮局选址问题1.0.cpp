/*�����������ʾ�ѡַ���⣺Ϊ�ʾ�ѡ��һ������ũ�ᵽ���ܾ�����С�ĵ�ַ�� ���Ȱ������ÿ�������ȫ���ź������ҳ���λ�������ַ���������Ѱ����λ�����ŵ��㷨���� 
���裺1.�����ũ���λ�ã�����������a���飬����������b���飩��
      2.�ÿ��������㷨��a��b��������
      3.ȷ����λ��λ��(�ʾֵĵ�ַ)�������ũ�ᵽ�ʾֵľ��벢����� 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LEN 100
void Swap(int &a, int &b){
     int temp = a;
     a = b;
     b = temp;
}

int Partition(int *a,int p,int r){
     int i=p,j=r+1;
     int x=a[p];
     while(true){
          while(a[++i]<x&&i<r);
          while(a[--j]>x);
          if(i>=j) break;
          Swap(a[i],a[j]);            
     } 
     a[p]=a[j];
     a[j]=x;
     return j;    
}

void QuickSort(int *a,int p,int r){
     if(p<r){
      int q=Partition(a,p,r);
      QuickSort(a,p,q-1);
      QuickSort(a,q+1,r);          
     }
}

int main(){
    int n,sum=0;
    int a[LEN],b[LEN];
    printf("�������������Ŀ��");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            } 
    //�ÿ��������a��b����������� 
    QuickSort(a,0,n-1);  
    QuickSort(b,0,n-1);
    int k;
    k=(n-1)/2;   //ȷ����λ����λ�ã����ڱ���������ʾֵĵ�ַ(a[k],b[k])�� 
    for(int i=0;i<n;i++){
        sum+=abs(a[i]-a[k])+abs(b[i]-b[k]);   //�����������㵽�ʾֵľ����ܺͣ�     
    }
    printf("�����ݵ���λ�����ܾ���Ϊ��%d\n",sum);
    system("pause");
    return 0;
    } 
