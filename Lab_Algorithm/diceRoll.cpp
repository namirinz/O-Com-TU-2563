#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> cube {1,2,3,4,5,6};
void diceRoll(vector<int> mySet,int n,int index){
    if (mySet.size() == n){
        for (auto k: mySet){
            cout << k << " ";
        }
        cout << endl;
        return;
    }
    else {
        for (int i=0;i<6;i++){
            mySet.push_back(cube[i]);
            diceRoll(mySet,n,index+1);
            mySet.pop_back();
        }
    }
}

int main(){
    cin >> n;
    vector<int> mySet;
    diceRoll(mySet,n,0);

    return 0;
}