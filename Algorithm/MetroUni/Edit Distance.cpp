#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,n,m,n1,a,b,c,d,p,s,in,del,sam,sub,t;
    char ch[100],ch1[100],sh1[100][100],par[100][100],ar[100];
    int sh[100][100];
    while(scanf("%s%s",&ch,&ch1)==2)
    {
        p=0;
        int mini;
        n=strlen(ch);
        n1=strlen(ch1);
        k=max(n,n1);
        for(j=0; j<=n; j++)
            sh[0][j]=j;
        for(i=0; i<=n1; i++)
            sh[i][0]=i;
        for(i=1; i<=n1; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(ch1[i-1]==ch[j-1])
                {
                    sh[i][j]=sh[i-1][j-1];
                    par[i][j]=ch1[i-1];
                }
                else if(ch1[i-1]!=ch[j-1])
                {
                    in=sh[i-1][j]+1;
                    del=sh[i][j-1]+1;
                    sub=sh[i-1][j-1]+2;
                    if(in<del)
                        a=in;
                    else
                        a=del;
                    if(sub<a)
                        mini=sub;
                    else
                        mini=a;
                    if(mini==sub)
                    {
                        sh[i][j]=mini;
                        //par[i][j]=ch1[i-1];
                        par[i][j]='@';
                    }
                    else if(mini==del)
                    {
                        sh[i][j]=mini;
                        par[i][j]='*';
                    }
                    else if(mini==in)
                    {
                        sh[i][j]=mini;
                    }


                }
            }
        }
        i=n1;
        j=n;

        while(p<k)
        {
            if(par[i][j]=='@')
            {
                ar[p++]='@';
                i=i-1;
                j=j-1;
            }
            else if(par[i][j]=='*')
            {
                ar[p++]='*';
                i=i;
                j=j-1;
            }
        }

        printf("%d\n",sh[n1][n]);
        printf("%s\n",ch);
        for(i=p-1; i>=0; i--)
            printf("%c",ar[i]);
        printf("\n");

    }

}
