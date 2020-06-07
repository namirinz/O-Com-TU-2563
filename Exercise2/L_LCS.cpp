#include<iostream>
using namespace std;

string s;
string a,b;

int LCS(int i,int j){
    if ( i == 0 || j == 0) return 0;
    else if (a[i] == b[j]) {
        cout << a[i] << " " << b[j] << endl;
        return LCS(i-1,j-1)+1;
    }else {
        return max(LCS(i-1,j),LCS(i,j-1));
    }
}

int main(){

    cin >> a;
    cin >> b;
    int len1 =a.length(),len2 = b.length();
    cout << LCS(len1,len2) << endl;
    cout << s;
    return 0;
}