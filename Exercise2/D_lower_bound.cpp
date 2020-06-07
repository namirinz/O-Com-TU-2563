#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vi(n);
    for (size_t i=0;i<n;i++) cin >> vi[i];
    int q,num;
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> num;
        auto k = lower_bound(vi.begin(),vi.end(),num)-vi.begin();
        if (vi[k] == num) cout << "Yes " << k+1  << endl;
        else cout << "No " << k+1 << endl;
    }
    return 0;
}