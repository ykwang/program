#include<stdio.h>
 
int main()
{
    int k;
    while(scanf("%d",&k),k){
         
        int i,v,vp,vl,vs,ve;
        long int max,sum;
        scanf("%d",&v);
        sum=v;
        max=v;
        vp=vl=vs=ve=v;
        int vv=v;
        for(i=1;i<k;i++){
            scanf("%d",&v);
            if(sum>0){
                sum+=v;
                ve=v;
            }
            else{
                sum=v;
                vs=ve=v;
            }
            if(max<sum){
                max=sum;
                vp=vs;
                vl=ve;
            }
        }
        if(max==0)printf("0 0 0\n");
        else if(max<0)printf("%ld %ld %ld\n",0,vv,v);
        else
            printf("%ld %ld %ld\n",max,vp,vl);
    }
    return 0;
}