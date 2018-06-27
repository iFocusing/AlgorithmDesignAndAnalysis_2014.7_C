#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LEN 100
/*�ʾ�ѡַ���⣻����n�����꣨x��y�������ǿ��Էֱ���Xi��Yi����λ����
*/ 
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
    if(p==r) {
      printf("\n\n�ҵ���λ����"); 
	  return a[p];
	} 
    system("pause");
    int i=RandomizedPartition(a,p,r);
    printf("�������%d��%d֮���ҵ�%d����������ѡȡ����������%d\n",p,r,k,i);
    int j=i-p+1;
    printf("����%d֮ǰ����%d������",i,j); 
    if(k<=j){ 
        printf("����ѡ����%d��%d֮��ѡ��%d�����\n",p,i,k);
		return RandomizedSelect(a,p,i,k);
	} 
    else {
    	printf("����ѡ����%d��%d֮��ѡ��%d�����\n",i+1,r,k-j);
		return RandomizedSelect(a,i+1,r,k-j);
	}
}
int main(){
    int n,w,aMid,bMid,k,i;//j;//jδ�õ� 
    int b[LEN],a[LEN];
    printf("���������:\n");
    scanf("%d",&n);
    w=0;
    //5 1 2 1 3 3 2 2 3 -2 3
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
      scanf("%d",&b[i]);
   }

    k=(n+1)/2;
    aMid=RandomizedSelect(a,0,n-1,k);
    printf("%d  ",aMid);
    
    bMid=RandomizedSelect(b,0,n-1,k);  //mid��������k��Ԫ�ص�ֵ����λ������ 
    printf("%d  ",bMid);
    
    for(i=0;i<n;i++)
     w=w+abs(bMid-b[i])+abs(aMid-a[i]);
    printf("%d",w);
   
    getchar();getchar();
    
    return 0;
}
