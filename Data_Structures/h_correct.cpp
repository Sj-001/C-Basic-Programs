#include <bits/stdc++.h>
const int mod  = 1e8+7;

using namespace std;
typedef unsigned long long ull;
ull x =  rand() % (mod-1) + 1;
struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

ull polyHash(string s){
    ull hash = 0;
    for(int i = 0; i < s.size(); ++i){
        hash += ((int(s[i] - 'a')*(ull)pow(x,i))) % mod;
    }
    return hash % mod;
}

vector<ull> precomp(string p, string t){
    vector<ull> hashes(t.size()-p.size() + 1);
    string str = t.substr(t.size() - p.size(), p.size());
    hashes[t.size() - p.size()] = polyHash(str);
    int y = 1;
    for(int i = 0; i<p.size(); ++i) y = (y*x)%mod;
    for(int i = t.size()-p.size() - 1; i >= 0; --i){
        hashes[i] = (x*hashes[i+1] + int(t[i] - 'a') - y*int(t[i+p.length()-1]-'a')) % mod;
        
    }
    return hashes;
}

bool areEqual(string s1, string s2){
    return (s1 == s2);
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<ull> hashes = precomp(s, t);
    vector<int> ans;
    ull hash = polyHash(s);
    for (size_t i = 0; i < hashes.size(); ++i)
    {
        //cout<<hashes[i]<<" ";
        //cout<<t.substr(i, s.size())<<" ";
        if(hashes[i] != hash) continue;
        if(areEqual(s, t.substr(i, s.size())))
            ans.push_back(i);
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
 