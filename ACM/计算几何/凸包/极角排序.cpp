#include<stdio.h>
#include<math.h>
#define eps 1e-10
#define pi 3.1415926535898
#define N 1010
/*
point[]：输入的点集
ch[]：输出的凸包上的点集，按照逆时针方向排列
n：point中的点的数目
len：输出的凸包上的点的个数
*/
struct node
{
    double x,y;
} point[N],ch[N];
int n,len;
double multi(node a,node b,node c)
{
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void graham_scan(node point[N],node ch[N],int n)
{
    int i,j,k,top;
    struct node t;
    k=0; //找到最下且偏左的那个点
    for(i=1; i<n; i++)
        if(point[i].y<point[k].y||(point[i].y==point[k].y&&(point[i].x<point[k].x)))
            k=i;
    t=point[0];//将这个点指定为point[0];
    point[0]=point[k];
    point[k]=t;
    //按极角从小到大,距离偏短进行排序
    for(i=1; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(multi(point[j],point[k],point[0])>0||(fabs(multi(point[j],point[k],point[0]))<=eps&&
                    (dis(point[0],point[j])<dis(point[0],point[k]))))
                k=j; //k保存极角最小的那个点,或者相同距离原点最近
        t=point[i];
        point[i]=point[k];
        point[k]=t;
    }
    //第三个点先入栈
    ch[0]=point[0];
    ch[1]=point[1];
    ch[2]=point[2];
    top=2; //判断与其余所有点的关系
    for(i=3; i<n; i++)
    {
        //不满足向左转的关系,栈顶元素出栈
        while(multi(point[i],ch[top],ch[top-1])>0||fabs(multi(point[i],ch[top],ch[top-1]))<=eps)
            top--;
        //当前点与栈内所有点满足向左关系,因此入栈
        ch[++top]=point[i];
    }
    len=top+1;
}
int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%lf%lf",&point[i].x,&point[i].y);
        graham_scan(point,ch,n);
        for(i=0; i<len; i++)
            printf("%lf %lf\n",ch[i].x,ch[i].y);
    }
    return 0;
}
