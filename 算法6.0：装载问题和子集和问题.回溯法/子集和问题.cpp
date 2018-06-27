#include<stdio.h>
#define MAX 10000
int data[MAX] ;
bool v[MAX] ;
int n , c ;
bool traceback(int n){
int p = 0 ,sum = 0 ;
while(p>=0)
{
if(!v[p])
{
v[p] = true ;
sum += data[p] ;
if(c == sum)
return true ;
else if( c < sum)
{
v[p] = false ;
sum -=data[p] ;
}
p++ ;
}
if(p>=n)
{
while( v[p-1] )
{
p-- ;
v[p] = false ;
if(p<1) return false ;
}
while( !v[p-1])
{
p-- ;
if(p<1) return false ;
}
sum -= data[p-1] ;
v[p-1] = false ;
}
}
return false ;
}
int main(){
scanf("%d %d" , &n , &c) ;
for(int i = 0 ; i < n ; i++)
scanf("%d" , &data[i]) ;
if(traceback(n))
{
int first = 1 ;
for(int i = 0 ; i < n; i++)
if(v[i])
{
if(first)
first = 0 ;
else
printf(" ") ;
printf("%d" , data[i]) ;
}
printf("\n") ;
}
else
printf("No Solution!\n") ;
return 0 ;
}
