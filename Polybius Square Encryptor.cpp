#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main ()
{
    int n;
    char ch;
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
    cout<<"Your file is ready";

    FILE *fp1,*fp2;
    fp1=fopen("text.txt","r+");
    fp2=fopen("file2.txt","w+");
while(feof(fp1)==0)
{
    ch=fgetc(fp1);
    if(!feof(fp1))
    {
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
            if(stalpha[i][j]==ch)
            {
                if(i<10&&j<10)
                {
                   temp1=i;
                   temp2=j;
                   temp1+=48;
                   temp2+=48;
                   fputc(temp1,fp2);
                   fputc(temp2,fp2);
                }
                if(i>=10)
                {
                    temp1=i/10;
                    temp2=i%10;
                    temp1+=48;
                    temp2+=48;
                    fputc(temp1,fp2);
                    fputc(temp2,fp2);
                }
                if(i<10&&j>=10)
                {
                    temp1=i;
                    temp1+=48;
                    fputc(temp1,fp2);

                }
                if(j>=10)
                {
                    temp1=j/10;
                    temp2=j%10;
                    temp1+=48;
                    temp2+=48;
                    fputc(temp1,fp2);
                    fputc(temp2,fp2);
                }
                if(j<10&&i>=10)
                {
                    temp1=j;
                    temp1+=48;
                    fputc(temp1,fp2);
                }
                goto label;
            }
        }
      }
      if(ch==32)
        {
            fputc('0',fp2);
            fputc('0',fp2);
        }
        label:
          {

          }

     }
}
fclose(fp1);
fclose(fp2);

}
