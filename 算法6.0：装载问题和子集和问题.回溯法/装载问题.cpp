#include <stdio.h>
#include<stdlib.h>
int c1,c2,n;
int *w,*bestx,*x;
int remain;
int bestw;
int cw;
void Load(int i)
{
   int k; 
 if(i>n)
   {
    for(k=1;k<=n;k++)
     { bestx[k]=x[k];
      }
    bestw=cw;
    return ;
   }
   remain-=w[i];
   if(cw+w[i]<=c1)
   {
    x[i]=1;
    cw+=w[i];
    Load(i+1);
    cw-=w[i];
   }
   if(remain+cw>bestw)
   {
    x[i]=0;
     Load(i+1); 
    
   }
   remain-=w[i];
}
int BestAnswer()
{
 int i;
 remain=0;
   bestx=(int *)malloc(sizeof(int)*(n+1));
    x=(int *)malloc(sizeof(int)*(n+1));
 for(i=1;i<=n;i++)
  { remain+=w[i];
   x[i]=0;
   }
   bestw=0;
 Load(1);
 return bestw;
 }
int main()
{
 while(1)
 {   int i,r=0;
  scanf("%d %d %d",&c1,&c2,&n);
  if(n==0)
    break;
   w=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++)
   { scanf("%d",&w[i]);
    
   }
  bestw=BestAnswer();
  for(i=1;i<=n;i++)
   {
     if(bestx[i]!=1)
         r+=w[i];
     }
   if(c2>=r)
    printf("yes\n");
    else
    printf("no\n");
}
    system("pause");
    return 0;
}
