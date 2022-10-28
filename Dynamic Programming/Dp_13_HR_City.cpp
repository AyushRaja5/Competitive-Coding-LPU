// 13. https://www.hackerrank.com/challenges/hr-city/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerrankCity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY A as parameter.
 */

int hackerrankCity(vector<int> A) {
    const long MOD = 1e9 + 7;
    int n = A.size();
    vector<long long> d(n+1);
    vector<long long> e(n+1);
    vector<long long> c(n+1);
    vector<long long> s(n+1);
    d[0] = 1;
    e[0] = 0;
    c[0] = 0;
    s[0] = 0;
    for(int i=1; i<=n; i++) {
        long long d0 = d[i-1];
        long long a  = A[i-1];
        long long e0 = e[i-1];
        long long c0 = c[i-1];
        long long s0 = s[i-1];
        d[i] = (d0*4+2) % MOD;
        e[i] = (2*e0 + 3*a) % MOD;
        //c[i] = c0*4 + (3*d0+2)*e0 + (8*d0+3)*a;
        //s[i] = s0*4 + c0*(3*d0+2)*4 + a*d0*(3*d0+2)*4 + a*(2*d0+1)*(2*d0+1);
        long long d1 = (3*d0+2) % MOD;
        long long d2 = (2*d0+1) % MOD;
        long long d3 = (8*d0+3) % MOD;
        c[i] = (c0*4 + (d1*e0)%MOD + (d3*a)%MOD) % MOD;
        s[i] = (s0*4 + ((c0*d1)%MOD) *4 + a* ((d0*d1)%MOD) *4 + a*((d2*d2)%MOD)) % MOD;
    }
    return s.back();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string A_count_temp;
    getline(cin, A_count_temp);

    int A_count = stoi(ltrim(rtrim(A_count_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(A_count);

    for (int i = 0; i < A_count; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = hackerrankCity(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
