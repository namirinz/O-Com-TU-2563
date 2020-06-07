#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
int n;
int arr[N];
int set[N];
void subsetSum(int key,vector<int> mySet,int index,int n){
    int total = 0;
    for(auto k: mySet){
        total += k;
    }
    if (total == key){
        for (auto k: mySet){
            cout << k << " ";
        }
        cout << endl;
    }
    else if (index == n) return;
    else {
        subsetSum(key,mySet,index+1,n);
        mySet.push_back(arr[index]);
        subsetSum(key,mySet,index+1,n);
        return;
    } 
}

int main(){
    cin >> n ;
    vector<int> mySet;
    for (size_t i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    subsetSum(k,mySet,0,n);

    return 0;
}