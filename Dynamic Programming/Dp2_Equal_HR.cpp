// Link : https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
 int a[3]={1,2,5};
int dp[2001];
int getans(int x)
 {
    if(x==0)
        return dp[x]=0;
    if(dp[x]!=-1)
        return dp[x];
    int mini=10000001;
      for(int i=0;i<3;i++)
      {
        if(a[i]<=x)
        mini=min(mini,1+getans(x-a[i]));
      }
    return dp[x]=mini;  
 }
int equal(vector<int> arr) {
   int mins=10000001;
   for(int i=0;i<arr.size();i++)
   {
       if(arr[i]<mins)
        mins=arr[i];
   }
   int ans=10000001;
    for(int j=mins-4;j<=mins;j++)
    { 
        int ans1=0;
    for(int i=0;i<arr.size();i++)
    {
        ans1+=dp[arr[i]-j];
    }
     ans=min(ans,ans1);
    }
    return ans;
}

int main()
{
   int t;
   cin>>t;
   memset(dp,-1,sizeof(dp));
    for(int i=0;i<2001;i++)
    {
        getans(i);
    }
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
          cin>>arr[i];
          cout<<equal(arr)<<endl;
    }
    return 0;
}