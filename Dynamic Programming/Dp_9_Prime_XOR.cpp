// 9. https://www.hackerrank.com/challenges/prime-xor/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'primeXor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
void mark_primes(vector<bool>& is_prime){
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2; i < sqrt(is_prime.size());i++){
        for(unsigned int j=i; i*j<is_prime.size();j++)
            is_prime[i*j]=0;
    }
}

int max_num = 8192;
unsigned long long int P = 1000000007;
int primeXor(vector<int> a) {
    vector<unsigned long long int> hist(4501,0);
    vector<unsigned long long int> unique_sets(max_num+1,0);
    unique_sets[0]=1;
    vector<bool> is_prime(max_num+1,1);
    
    mark_primes(is_prime);
    
    for(int i = 0; i < a.size(); i++)
        hist[a[i]]++;

    for(int i = 3500; i <= 4500; i++){
        if(hist[i]==0)
            continue;
        vector<unsigned long long int> temp(unique_sets);
        for(int j=0;j<=max_num;j++){
            if(unique_sets[j]==0)
                continue;
            temp[j]+= (unique_sets[j]*(hist[i]/2))%P;
            temp[j^i]+= (unique_sets[j]*((1 + hist[i])/2))%P;
        }
        unique_sets = temp;
    }
    
    unsigned long long int sum = 0;
    for(int i = 0; i <= max_num; i++)
        sum+= (unique_sets[i]*is_prime[i])%P;
    return sum%P;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

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
