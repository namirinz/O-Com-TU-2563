#include <iostream>
using namespace std;

int count = 0;
void permute(string s,int n,int index){ 
    if ( s[index-1] == '0' && s[index-2] == '0') return;
    else if ( n == 0 ) {
        count++;
        return;
    }
    else {
        s.push_back('0');
        permute(s,n-1,index+1);
        s.pop_back();
        s.push_back('1');
        permute(s,n-1,index+1);
        s.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    
    permute(s,n,0);
    cout << count;
    return 0;
}