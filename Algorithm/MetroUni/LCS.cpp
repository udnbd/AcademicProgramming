#include<bits/stdc++.h>
using namespace std;
#define diagonal 1
#define up 2
#define left 3
int main()
{
    int i,j,n,m;
    char ch[100],ch1[100];
    int sh[100][100],b[100][100];
    while(scanf("%s%s",ch,ch1)==2)
    {
        n=strlen(ch);
        m=strlen(ch1);
        for(i=0; i<=m; i++)
            sh[i][0]=0;
        for(j=0; j<=n; j++)
            sh[0][j]=0;
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(ch1[i-1]==ch[j-1])
                {
                    sh[i][j]=sh[i-1][j-1]+1;
                    b[i][j]=diagonal;

                }
                else if(ch1[i-1]!=ch[j-1])
                {
                    if(sh[i-1][j]>sh[i][j-1])
                    {
                        sh[i][j]=sh[i-1][j];
                        b[i][j]=up;

                    }
                    else
                    {
                        sh[i][j]=sh[i][j-1];
                        b[i][j]=left;
                    }

                }


            }
        }
        i=m;
        j=n;
        string res="";
        while(i>0&&j>0)
        {
            if(b[i][j]==diagonal)

            {
                res+=ch1[i-1];
                i--;
                j--;
            }
            else if(b[i][j]==up)
                i--;
            else
                j--;
        }
        reverse(res.begin(),res.end());
        printf("%d\n",sh[m][n]);
        cout<<res<<endl;


    }
    return 0;
}
