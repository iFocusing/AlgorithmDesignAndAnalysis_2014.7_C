#include <stdio.h>
#define active_num 5 //活动数
#define true 1          //记录被选的活动
#define false 0         //未被选择的活动
int greedySelector(int s[],int f[],int b[])
//  算法
{
    b[0] = true;
    int j = 0;
    int i = 1;
    int count = 1;
    for(i = 1;i <=active_num; i++ )
    {
        if(s[i] > f[j])
        {
            b[i] = true;
            j = i;
            count++;
        }
        else
        b[i] = false;
    }
    printf("active number is %d\n",count);
    for(i=0;i<active_num;i++)
    {
        if(b[i] == 1)
            printf("%d ",i+1);
    }
    return 0;
}
int main()
{

        int i;
        int start_time[active_num];
        int finish_time[active_num];
        int boolean[active_num];

        printf("please input the start time\n");
        for(i = 0; i < active_num; i++)
                scanf("%d",&start_time[i]);

        printf("please input the finish time\n");
        for(i = 0; i < active_num; i++)
                scanf("%d",&finish_time[i]);

        greedySelector(start_time ,finish_time ,boolean);

        return 0;
}
