#include <iostream>
using namespace std;
int A[] = {10,3,5,1,2,7};

bool subsetSum(int s,int value){
    if (value == 0) return true;
    if (s == 0) return false;
    if (value >= A[s]){
        return (subsetSum(s-1,value) || subsetSum(s-1,value-A[s]));
    }else {
        return subsetSum(s-1,value);
    }
}

bool BU_subsetSum(int s,int value){
    bool check[s+1][value+1];
    for (int i=0;i<=s;i++){
        for (int j=0;j<=value;j++){
            if (j == 0) check[i][j] = true;
            else if (i == 0) check[i][j] = false;
            else if ( j < A[i-1]) check[i][j] = check[i-1][j];
            else check[i][j] = (check[i-1][j] | check[i-1][j-A[i-1]]);
        }
    }
    return check[s][value];
}

int check[1000][1000];
bool TD_subsetSum(int s,int value){
    if (value == 0) return true;
    else if ( s == 0 ) return false;
    else {
        if (value >= A[s-1]){
            return check[s][value] = (TD_subsetSum(s-1,value) || TD_subsetSum(s-1,value-A[s-1]));
        }else {
            return check[s][value] = TD_subsetSum(s-1,value);
        }
    }
}



int main(){
    int k;
    cin >> k;
    cout << subsetSum(5,k) << endl; 
    cout << BU_subsetSum(6,k) << endl; 
    cout << TD_subsetSum(6,k) << endl; 
    return 0;
}