// Link : https://www.hackerrank.com/challenges/sherlock-and-cost/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];
int solve(int i,int choice,vector<int>&b,int n){
    if(i==n)return 0;
    if(dp[i][choice]!=-1)return dp[i][choice];
    int ans1,ans2;
    if(choice){
        ans1=abs(b[i]-b[i-1])+solve(i+1,1,b,n);
        ans2=abs(1-b[i-1])+solve(i+1,0,b,n);
        return dp[i][choice]=max(ans1,ans2);
    }
    else{
         ans1=abs(b[i]-1)+solve(i+1,1,b,n);
        ans2=abs(1-1)+solve(i+1,0,b,n);
        return dp[i][choice]=max(ans1,ans2);
    }
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>b[i];
        if(n==1)cout<<0<<"\n";
        else if(n==2)cout<<b[1]-1<<"\n";
        else{
            for(int i=0;i<=n;i++){
                for(int j=0;j<2;j++)dp[i][j]=-1;
            }
            cout<<max(solve(1,0,b,n),solve(1,1,b,n))<<"\n";
        }
    }
    return 0;
    
}