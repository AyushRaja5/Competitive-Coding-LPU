//  Link : https://www.hackerrank.com/challenges/coin-change/problem
#include<bits/stdc++.h>
using namespace std;
long table[50][250];
bool calculated[50][250];

long solve(int i, int make, vector<long> c) {
    if (make < 0 ) {
        return 0;
    }
    if (make == 0) {
        return 1;
    }
    if (i >= c.size()) {
        return 0;
    }
    if (calculated[i][make] == false) {
        table[i][make] = solve(i, make - c[i], c) + solve(i+1, make, c);
        calculated[i][make] = true;
    }
    return table[i][make];
}
long getWays(int n, vector<long> c) {
    return solve(0, n, c);
}

int main(){
    
}