#include <map>
#include <iostream>
#include <iterator>
using namespace std;
int main(){
    int n;
    cin >> n;
    int q;
    string name;
    int data;
    map<string,int> m;
    map<string,int>::iterator it;
    for (int i=0;i<n;i++){
        cin >> q;
        if ( q == 1){
            cin >> name >> data;
            it = m.find(name);
            if (it == m.end()){
                m.insert(make_pair(name,data));
            }else {
                it->second += data;
            }
        }else if ( q == 2){
            cin >> name;
            m.erase(name);
        }else {
            cin >> name;
            it = m.find(name);
            if (it == m.end()) cout << 0 << endl;
            else cout << it->second << endl;
        }
    }
    return 0;
}