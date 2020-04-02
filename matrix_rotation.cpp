#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int l,m,Row,Col,mat[300][300];

void rotation(int l, int m, int Row, int Col)
{
       int si,sj,i,j,t,f;
       si = l;
       sj = m;
      
       t = mat[l][m];
      
       for(i=l+1;i<=Row;i++)
       {
              f = mat[i][m];
              mat[i][m] = t;
              t = f;
       }
       l++;
       for(i=m+1;i<=Col;i++)
       {
              f = mat[Row][i];
              mat[Row][i] = t;
              t = f;
       }
       m++;
       if(l-1 < Row)
       {
              for(i=Row-1;i>=l-1;i--)
              {
                     f = mat[i][Col];
                     mat[i][Col] = t;
                     t = f;
              }
       }
       Col--;
       if(m-1 < Col)
       {
              for(i=Col;i>=m;i--)
              {
                     f = mat[l-1][i];
                     mat[l-1][i] = t;
                     t = f;
              }                         
       }
       Row--;
       mat[si][sj] = t;
       return;
}


int main()
{
       int r,c,k,i,j;
       cin>>r>>c>>k;
       int f,K;
       for(i=0;i<r;i++)
       {
              for(j=0;j<c;j++)
              {
                     cin>>mat[i][j];
              }
       }
       l = 0;
       m = 0;
       Row = r-1;
       Col = c-1;
       while(l < Row && m < Col)
       {
              int rot = 2*(Row-l)+2*(Col-m);
              f = k%rot;
              for(i=1;i<=f;i++)
              {
                     rotation(l,m,Row,Col);
              }
              l++;
              m++;
              Row--;
              Col--;
       }     
       for(i=0;i<r;i++)
       {
              for(j=0;j<c;j++)
              {
                     cout<<mat[i][j]<<" ";
              }
              cout<<endl;
       }
    return 0;
}
