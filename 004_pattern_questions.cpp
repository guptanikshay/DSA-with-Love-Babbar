#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     cout<<"\n";
    // }
    // 1
    // 2 3
    // 3 4 5
    // 4 5 6 7
    // for(int i=1; i<=n; i++){
    //     for(int j=i; j<2*i; j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    // 1 2 3 4 5 5 4 3 2 1
    // 1 2 3 4 * * 4 3 2 1
    // 1 2 3 * * * * 3 2 1
    // 1 2 * * * * * * 2 1
    // 1 * * * * * * * * 1
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout<<j<<" ";
        }
        for(int j=1; j<i; j++){
            cout<<"* * ";
        }
        for(int j=n-i+1; j>0; j--){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}