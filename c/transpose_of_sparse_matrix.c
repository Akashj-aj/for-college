// Online C compiler to run C program online
#include <stdio.h>

int row ,col,item,k;
typedef struct
{
    int r,c,val;
}TERM;
TERM a[10],b[10];
void printM(TERM p[],int rows)
{
    for(int i =0;i<rows;i++)
    {
        printf("%d %d %d\n",p[i].r,p[i].c,p[i].val);
    }
}
void read()
{
    int i ,j,k=1;
    a[0].r=row;
    a[0].c=col;
    a[0].val=1;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&item);
            if(item!=0)
            {
                a[k].r=i;
                a[k].c=j;
                a[k].val=item;
                k++;
            }
        }
    }
    a[0].val=k-1;
    printf("Sparse Matrix in compressed form\n");
    printM(a,k);
}

void transpose()
{
int n,i, j, currentb;
n = a[0].val;
b[0].r=a[0].c;
b[0].c = a[0].r; 
b[0]. val = n;
if (n > 0) {
currentb = 1;
for (i=0; i < a[0].c; i++){

    for (j= 1; j <= n; j++)

    if (a[j].c == i) {

    b[currentb].r= a[j].c;
    b[currentb].c = a[j].r;
    b[currentb] . val = a[j].val;
    currentb++;
    }
    
}
}
printf("transpose of sparse matrix:\n");
for(int i =0;i<=n;i++)
    {
        printf("%d %d %d\n",b[i].r,b[i].c,b[i].val);
    }
}

void main()
{
    
    printf("ENter the size of rows and column:");
    scanf("%d %d",&row,&col);
    printf("Enter the elements of matrix:");
    read();
    transpose();
}