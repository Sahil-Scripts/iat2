#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int f[MAX],HT[MAX]={0},L;
int id;
char name[20];
float salary;
void probe(int k,int key)
{
    L=k%MAX;
    if(HT[L]==0)
    HT[L]=key;
    else
    probe(k+1,key);
}
void display()
{
    int i;
    printf("\nHash Table:");
    for(i=0;i<MAX;i++)
    {
        printf("\nHT[%d]:%d",i,HT[i]);
    }
}
void main()
{
    int i=0,num;
    FILE *fp;
    fp=fopen("emp.txt","r");
    printf("\n FILE");
    do
    {
        fscanf(fp,"%d %s %f", &id, name, &salary);
        printf("\n%d %s %f",id,name,salary);
        f[i++]=id;
    }
    while (!feof(fp));
    for(i=0;i<MAX;i++)
    {
        L=f[i]%MAX;
        if(HT[L]==0)
        HT[L]=f[i];
        else
        probe(f[i]+1,f[i]);
    }
    display();
}
