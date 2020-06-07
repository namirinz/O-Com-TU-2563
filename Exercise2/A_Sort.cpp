#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vi(n);
    for (size_t i=0;i<n;i++){
        cin >> vi[i];
    }
    sort(vi.begin(),vi.end());
    for (auto k: vi) cout << k << " ";
    return 0;
}