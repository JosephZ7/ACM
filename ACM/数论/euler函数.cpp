int euler(int n){ //����euler(n)
     int res=n,a=n;
     for(int i=2;i*i<=a;i++){
         if(a%i==0){
             res=res/i*(i-1);//�Ƚ��г�����Ϊ�˷�ֹ�м����ݵ����
             while(a%i==0) a/=i;
         }
     }
     if(a>1) res=res/a*(a-1);
     return res;
}
// ɸ����Χ�ڵ�ŷ������
void phi_table(int n, int *phi)
{
    for(int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 2;
    for(int i = 2; i <= n; i++) if(!phi[i])
        for(int j = i; j <= i; j+= i)
        {
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i-1);
        }
}
