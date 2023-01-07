#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin>>n;
    char a[n][100],temp[100];
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(strcmp(a[i],a[j])>0)
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
    for (int i=0;i<n;i++) cout<<a[i]<<"\n";
    return 0;
}