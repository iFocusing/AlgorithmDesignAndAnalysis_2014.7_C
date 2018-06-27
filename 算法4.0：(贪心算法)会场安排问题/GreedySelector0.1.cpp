/*会场安排问题；
问题描述：在足够多的会场安排一系列活动，要求尽可能使用最少的会场；
解决办法：贪心算法；
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
    int n;        //n代表活动个数；
    int s[L],f[L];  //s[]存储每个活动开始的时间，j[]存储每个活动结束的时间；按照活动结束时间从小到大的顺序存储；
    bool a[L];     //a[]代表记录活动时间是否相容；  
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
                   printf("试探l的值：%d\n",l);
            GreedySelector(n-l,&s[l],&f[l],&a[l]); p++;  
            }
            }
    printf("output:%d",p);
   
    getchar();  getchar();  getchar();  getchar();  getchar();  getchar();
    system("plase");
    return 0;
}
