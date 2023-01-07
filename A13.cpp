#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    unordered_map<int, int> m; //this method has least time complexity of O(nlogn)
    for (int i=0;i<n;i++)  m[a[i]]++;
    for (auto i : m)
        cout<< i.first <<" "<< i.second <<"\n";
       return 0;
}