#include <iostream>
using namespace std;

bool recur(string s,int left,int right){
    int len = s.length();
    if (s[left] <= 90) s[left] += 32;
    if (s[right] <= 90) s[right] += 32;
    
    if (len%2 == 0){
        if (s[left] == s[right]) return true;
        else return false;
        if (recur(s,left+1,right-1) == false){
            return false;
        }
    }else {
        if (s[left] == s[right] && left != right) return true;
        else if (left != right) return false;
        if (recur(s,left+1,right-1) == false){
            return false;
        }

    }

}

int main(){
    string s;
    getline(cin,s);
    if (recur(s,0,s.length()-1) == true) cout << "Yes";
    else cout << "false";
    return 0;
}