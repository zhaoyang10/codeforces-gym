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
    int n;
    int i;
    string name;
    map<string, int> map_name;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        cin>>name;
        if(map_name[name] == 0) {
            printf("OK\n");
            map_name[name] += 1;
        }else{
            cout<<name<<map_name[name]<<endl;
            map_name[name] += 1;
        }
    }
    return 0;
}
