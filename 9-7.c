#include<stdio.h>

void swapLines(int i, int j, int m, float a[][m])
{
    int k ;float c;
    for(k=0;k<=m-1;k++)
        {
        c=a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=c;
        }
}

checkElement(int o,int k,int b[k]){
int i;
for(i=0;i<=k-1;i++){
    if(b[i]==o){return 0;}
}
return 1;
}

int str(int n, int m, float a[][m]) {
int i,j,count,F,b[m],k=0;
for(j=0;j<=m-1;j++){
    count=0;
    for(i=0;i<=n-1;i++){
        if(a[i][j]!=0){
            count++; F=i;
        }

    }
    if(count==0){return 0;}
    else if(count ==1){swapLines(j,F,m,a);b[k]=j;k++;}
}

int P=0; F=0;
while(i<n-1){
    if(checkElement(i,k,b)){continue;}
    j=i+1;
    while(j<=n-1)
        {
        if(checkElement(j,k,b)){continue;}
        P=0;
        if(a[j][j]==0){P=1;}
        if(a[j][j]==0 && a[j][i]!=0){break; }
        if(a[j][j]!=0 && a[j][i]!=0){F=j;}
        j++;
        }
    if(j==n && a[i][i]==0 && F==0){return 0;}
    if(j!=n){swapLines(i,j,m,a);}
    if(j==n && a[i][i]==0 && F!=0){swapLines(i,F,m,a);}
    F=0;
    if(P!=1){i++;}
    }
return 1;
}



void tri( int n, int m, float a[][m])
{ int i, j;
float c;
for(i=-(n-2);i<=0;i++){
if(a[i][-(n-1)]!=0){
     c=a[i][-(n-1)];
    for(j=-(n-1);j<=0;j++){
        a[i][j]-=a[-(n-1)][j]*c/a[-(n-1)][-(n-1)];
        }
       }
    }
   if(n-1>1){tri(n-1,m,a) ;}
}

float def(int n, float a[n][n]){
int i;
float sum=1;
for(i=0;i<=n-1;i++){sum*=a[i][i];}
return sum;
}

int main()
{
int i,j,n,m;
    printf("Enter height and width n\n");
    scanf("%d",&n);
    m=n;
    float a[n][m];
    for(i=0;i<=n-1;i++){
        for(j=0;j<=m-1;j++){
            printf("Enter a[%d][%d]\n",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
    printf("\n\n");
    if(str(n, m, a)==0){ printf("ERROR");return 100; }
    for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
    printf("\n\n");
    tri(n,m, &a[n-1][m-1]);
    for(i=0;i<=n*n-1;i++){if((i-1)/n<i/n){ printf("\n"); };printf("%g ", a[i/n][i%n]);}
    printf("\n\n\nDeterminant = %g", def(n, a) );
    return 0;
}
