// Link : https://www.hackerrank.com/challenges/sam-and-substrings/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    long long int M = 1000000007, i, temp, ans;
    ans = temp =  s[0]-'0';
    for (int i = 1; i < s.size(); i++)
    {
        temp = ((temp * 10) + ((s[i] - '0') * (i + 1))) % M;
        ans = (ans + temp) % M;
    }
    cout<<ans;
    return 0;
}
