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

int main() {
    int n, s, i;
    string str_in;

    scanf("%d", &n);
    s = 0;
    for(i = 0; i < n; i ++) {
        cin>>str_in;
        if(str_in == "Tetrahedron") s += 4;
        if(str_in == "Cube") s += 6;
        if(str_in == "Octahedron") s += 8;
        if(str_in == "Dodecahedron") s += 12;
        if(str_in == "Icosahedron") s += 20;
    }
    printf("%d", s);

    return 0;
}
