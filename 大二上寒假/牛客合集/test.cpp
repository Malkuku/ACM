#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e2;
void solve(){
    vector<int> arr(N);
    for(int i = 1; i < N; i++){
        arr[i] = 2*i - 2;
    }
    vector<ll> sum(N);
    for(int i = 1; i < N; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    vector<ll> arr2;
    for(int i = 1; i < arr.size(); i++){
        for(int j = 1; j < i; j++){
            arr2.push_back(sum[i] - sum[j-1]);
        }
    }
    sort(arr2.begin(),arr2.end());
    arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());
    cout << arr2[0] << " ";
    for(int i = 1; i < arr2.size(); i++){
        if(arr2[i] - arr2[i-1] == 4) cout << "! ";
        cout << arr2[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}