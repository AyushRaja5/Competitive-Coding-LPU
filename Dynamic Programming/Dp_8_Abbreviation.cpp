// 8. https://www.hackerrank.com/challenges/abbr/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int solve(string a, string b, int idx_a, int idx_b, vector<vector<int>>&dp){
    if(dp[idx_a][idx_b] != -1) return dp[idx_a][idx_b];
    // if len(a) < len(b), return 0
    if(idx_a < idx_b) return dp[idx_a][idx_b] = 0;

    char chA = a[idx_a-1], chB = b[idx_b-1];
    // if chA is lower
    if(islower(chA)){
        // upper(chA) = chB, then either remove chA or consider chA
        if(toupper(chA) == chB)
            return dp[idx_a][idx_b] = solve(a, b, idx_a-1, idx_b, dp) or solve(a, b, idx_a-1, idx_b-1, dp);
        // upper(chA) != chB, remove chA
        return dp[idx_a][idx_b] = solve(a, b, idx_a-1, idx_b, dp); 
    }
    // if chA is upper
    else{
        // if chA == chB, then consider it
        if(chA == chB)
            return dp[idx_a][idx_b] = solve(a, b, idx_a-1, idx_b-1, dp);
        // else return 0
        return dp[idx_a][idx_b] = 0;
    }
}


string abbreviation(string a, string b) {
    vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, -1));
    dp[0][0] = 1;
    solve(a, b, a.length(), b.length(), dp);
    return dp[a.length()][b.length()]? "YES": "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

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
