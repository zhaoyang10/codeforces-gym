#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <bitset>
#include <utility>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {return b ? gcd(b, a%b): a;}
int gcd(int a, int b) {return b ? gcd(b, a%b): a;}



#define LEN 1000010

string& trim(string & s) {
    if (s.empty()) return s;
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);
    return s;
}

int main() {
    string str_in, str_out;
    cin>>str_in;

    int pos = str_in.find("WUB");
    while(pos != -1) {
        str_in = str_in.replace(pos, 3, " ");
        pos = str_in.find("WUB");
    }

    str_out = trim(str_in);
    cout << str_out;

    return 0;
}
