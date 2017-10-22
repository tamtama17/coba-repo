#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int i=1,N,T,sisa,bagi,urut=1,stat=1;
pthread_t tid[100];

void *prima(void *arr)
{
    while(stat == 0){}
    if(stat == 1){
        stat=0;
        printf("ini thread ke-%d\n", urut);
        urut++;
        int j,count,x;
        if(sisa > 0){
            x=i+bagi;
           sisa--;
        }
        else x=i+bagi-1;
        for(i;i<=x;i++){
        count=0;
            for(j=1;j<=i;j++){
                if(i%j==0)count++;
            }
        if(count==2)printf("%d ",i);
        }
        printf("\n");
    }
    stat=1;
    return NULL;
}

int main()
{
    int a,b;
    printf("N : ");
    scanf("%d", &N);
    printf("T : ");
    scanf("%d", &T);
    bagi = N/T;
    sisa = N%T;
    for(a=0;a<T;a++)
        pthread_create(&(tid[a]), NULL, &prima, NULL);
    for(b=0;b<T;b++)
        pthread_join(tid[b], NULL);
    return 0;
}
