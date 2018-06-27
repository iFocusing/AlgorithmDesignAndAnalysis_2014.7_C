/**/
#include<stdio.h>
#include<stdlib.h>
#define LEN 100
/**/
int EditLength(char* a,char* b){
    int n;
    
    return n;
    }
/**/
int main(){
    char a[LEN],b[LEN];
    int c[LEN][LEN];
    scanf("%s",&a);
    scanf("%s",&b);
    printf("%s\n",a);
    printf("%s\n",b);
    int i=0,j=0,n1=0,n2=0;
    while(a[i]){
          n1++;  
          i++;    
    }
    while(b[j]){
          n2++;  
          j++;    
    }
    printf("%d %d\n",n1,n2);
    int k=0,h=0;
    for(k=0;k<n1;k++){
      for(h=0;h<n2;h++){
              c[k][h]=0;
              printf("%d ",c[k][h]);
              }
      printf("\n");
      }
          
    printf("±à¼­¾àÀëÎª:%d",EditLength(a,b));
    system("pause");
    return 0;
    }
