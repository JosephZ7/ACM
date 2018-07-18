#include<stdio.h>
#include<math.h>
#define eps 1e-10
#define pi 3.1415926535898
#define N 1010
/*
point[]������ĵ㼯
ch[]�������͹���ϵĵ㼯��������ʱ�뷽������
n��point�еĵ����Ŀ
len�������͹���ϵĵ�ĸ���
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
    k=0; //�ҵ�������ƫ����Ǹ���
    for(i=1; i<n; i++)
        if(point[i].y<point[k].y||(point[i].y==point[k].y&&(point[i].x<point[k].x)))
            k=i;
    t=point[0];//�������ָ��Ϊpoint[0];
    point[0]=point[k];
    point[k]=t;
    //�����Ǵ�С����,����ƫ�̽�������
    for(i=1; i<n-1; i++)
    {
        k=i;
        for(j=i+1; j<n; j++)
            if(multi(point[j],point[k],point[0])>0||(fabs(multi(point[j],point[k],point[0]))<=eps&&
                    (dis(point[0],point[j])<dis(point[0],point[k]))))
                k=j; //k���漫����С���Ǹ���,������ͬ����ԭ�����
        t=point[i];
        point[i]=point[k];
        point[k]=t;
    }
    //������������ջ
    ch[0]=point[0];
    ch[1]=point[1];
    ch[2]=point[2];
    top=2; //�ж����������е�Ĺ�ϵ
    for(i=3; i<n; i++)
    {
        //����������ת�Ĺ�ϵ,ջ��Ԫ�س�ջ
        while(multi(point[i],ch[top],ch[top-1])>0||fabs(multi(point[i],ch[top],ch[top-1]))<=eps)
            top--;
        //��ǰ����ջ�����е����������ϵ,�����ջ
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
