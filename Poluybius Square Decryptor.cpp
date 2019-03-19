#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int temp1,temp2;
    char stalpha[10][10];
    cout<<"Enter the key";
    cin>>n;
    if(n==0)
    {
        exit(0);
    }
    if(n==10)
    {
        n=1;
    }
    if(n>10)
    {n=n%10;}
    int k=97;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            stalpha[i][j]=k;
            k++;
            if(k>122)
            {
                k=97;
            }
        }
    }
    FILE *fp1,*fp2;
    fp1=fopen("file2.txt","r+");//encrypted file
    fp2=fopen("file3.txt","w+");//decrypted file
    char ch;
    cout<<"Your file is ready";
    while(feof(fp1)==0)
    {
    ch=fgetc(fp1);
    if(!feof(fp1)){
          ch=ch-48;
          temp1=ch;
     }
     ch=fgetc(fp1);
    if(!feof(fp1)){
          ch=ch-48;
          temp2=ch;
     }
     if(!feof(fp1)){
            if(temp1==0&&temp2==0)
            {
                fputc(' ',fp2);
                continue;
            }
     fputc(stalpha[temp1][temp2],fp2);
     }
    }
    fclose(fp1);
    fclose(fp2);
}
