// 15. https://www.hackerrank.com/challenges/mr-k-marsh/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define sz(a) ((int)((a).size()))
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define fv(a,b) for(__typeof(a.begin()) b = (a).begin(); b != (a).end(); ++b)
#define all(a)  a.begin(),a.end()

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b);o?(a):(b)
typedef long long LL;
typedef vector <int> VI;
typedef pair< int ,int > PII;

int main() {
    int n,m;
    char land[505][505];
    cin>>n>>m;
    rep(i,n)
        cin>>land[i];
    int left[505][505],up[505][505];
    rep(i,n)
        left[i][0]= land[i][0]=='.'?0:-1;
    rep(j,m)
        up[0][j]= land[0][j]=='.' ?0:-1;
    // setup left[]
    rep(i,n)
        for(int j=1;j<m;j++)
            if(land[i][j]=='.')
                left[i][j]=left[i][j-1]+1;
            else
                left[i][j]=-1;
    //setup up[]    
    rep(j,m)
        for(int i=1;i<n;i++)
            if(land[i][j]=='.')
                up[i][j]=up[i-1][j]+1;
            else
                up[i][j]=-1;

    int max_par=-1;
    rep(r1,n)
        for(int r2=r1+1;r2<n;r2++)
        {
            vector<int> v;
            int rdiff=r2-r1;
            rep(j,m)
                if(up[r2][j]>=rdiff)
                    v.push_back(j);
            int l=0,r;
            for(r=0;r<v.size();r++)
            {
                int min_left= v[r] - min( left[r1][v[r]] , left[r2][v[r]] );
                while(v[l]<min_left)
                    l++;
                if(v[r]>v[l])
                    max_par=max(max_par, 2*(rdiff) + 2*(v[r]-v[l]) );
            }
        }
    if(max_par==-1)
        cout<<"impossible";
    else
        cout<<max_par;
    return 0;
}
