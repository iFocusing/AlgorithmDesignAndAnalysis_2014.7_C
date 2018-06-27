#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LEN 100
/*�ʾ�ѡַ���⣻����n�����꣨x��y�������ǿ��Էֱ���Xi��Yi����λ����
*/ 
void SaveToFile(int n)
{ 
    FILE *fp1;
    int i;
    fp1=fopen("D:\\t2.txt","a");
	if(fp1==NULL)
	 {
	  printf("Storage file is missing.\n"); 
	  exit(0);
      }
    else
    {
        fprintf(fp1, "%d \n",n); 
    } 
    fclose(fp1);    
}

void Swap(int &a, int &b){
     int temp = a;
     a = b;
     b = temp;
}

int Random(int p, int r){//�����
   return rand()*(r-p)/32767+p;
}

int Partition(int* a,int p,int r){
    int i=p,j=r+1;
    int x=a[p];
    while(true){
       while(a[++i]<x&&i<r);
       while(a[--j]>x);  //���Լ�1�ٱȽϣ� 
       if(i>=j) break;
       Swap(a[i],a[j]);            
    }    
    a[p]=a[j];
    a[j]=x;
    return j;
}

int RandomizedPartition(int y[LEN], int p, int r){
    int i = Random(p,r);
    Swap(y[i],y[p]);
    return Partition(y,p,r);
}

int RandomizedSelect(int* a,int p,int r,int k){
    if(p==r) return a[p];
    int i=RandomizedPartition(a,p,r);
    int j=i-p+1;
    if(k<=j) return RandomizedSelect(a,p,i,k);
    else return RandomizedSelect(a,i+1,r,k-j);
}

int main(){
    int n,w,aMid,bMid,k,i,j;
    int b[LEN],a[LEN];
    FILE *p;
    
    p=fopen("D:\\t1.txt","r");
    if (p == NULL){
        printf("�޷����ļ�"); 
        exit(0);
        }
    while (!feof(p)){
    fscanf(p,"%d",&n);
    printf("���ļ��ж�ȡ�����������%d\n",n);
    w=0;
    for(i=0;i<n;i++){
      fscanf(p,"%d",&a[i]);
      fscanf(p,"%d",&b[i]);
    }
    k=(n+1)/2;
    aMid=RandomizedSelect(a,0,n-1,k);
    bMid=RandomizedSelect(b,0,n-1,k);  //mid��������k��Ԫ�ص�ֵ����λ������ 
    for(i=0;i<n;i++)
     w=w+abs(bMid-b[i])+abs(aMid-a[i]);
    SaveToFile(w);
    printf("%d",w);
   
    getchar();getchar();getchar();
    return 0;
    }
}
