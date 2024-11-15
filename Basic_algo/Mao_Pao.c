//
// Created by 黄展博 on 2024/11/15.
//
/*
 这个程序主要是用来进行冒泡排序在郝斌老师P165的冒泡排序的基础上进行了改进
 让用户可以自己来确定自己要进行排序的数组
 */

# include <stdio.h>

void sort(int * p, int a)
{
    int g, o, l, w;

    for(g = 1;g < a;++g)
    {
        for(l = 0;l < a - g;++l)
        {
            if(p[l] > p[l + 1])
            {
                w = p[l + 1];
                p[l + 1] = p[l];
                p[l] = w;
            }
        }
    }

}



int main(void)
{
    int n, i;

    printf("请输入你要排序的数组的元素的个数：\n");
    scanf("%d", &n);
    int a[n];

    for(i = 0;i < n;++i)
    {
        printf("请输入第%d个元素：",i+1);
        scanf("%d",&a[i]);
    }

    sort(a,n);

    printf("排序后的数组为：\n");
    for (int i = 0; i < n; ++i)
    {

        printf("%d\n",a[i]);

    }



    return 0;
}
