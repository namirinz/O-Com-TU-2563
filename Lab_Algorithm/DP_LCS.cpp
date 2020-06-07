#include <iostream>
using namespace std;

int LCS(string s1,string s2,int i,int j){
    if (i == 0 || j == 0) return 0;
    else if (s1[i] == s2[j]) return LCS(s1,s2,i-1,j-1)+1;
    else return max(LCS(s1,s2,i-1,j),LCS(s1,s2,i,j-1));
}

int arr[10000][10000];
int TD_LCS(string s1,string s2,int i,int j){
    if (i == 0|| j == 0) return 0;
    else if (s1[i] == s2[j]){
        arr[i][j] = LCS(s1,s2,i-1,j-1)+1;
    }
    else {
        arr[i][j] = max(LCS(s1,s2,i-1,j),LCS(s1,s2,i,j-1));        
    }
    return arr[i][j];
}

int BU_LCS(string s1,string s2,int len1,int len2){
    int arr2[len1+1][len2+1];
    for ( int i=0;i<=len1;i++){
        for (int j=0;j<=len2;j++){
            if ( i == 0 || j == 0) arr2[i][j] = 0;
            else if (s1[i] == s2[j]) arr2[i][j] = arr2[i-1][j-1]+1;
            else arr2[i][j] = max(arr2[i-1][j],arr2[i][j-1]);
        }
    }
    return arr2[len1][len2];
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    
    cout << LCS(s1,s2,len1,len2) << endl;
    cout << TD_LCS(s1,s2,len1,len2) << endl;
    cout << BU_LCS(s1,s2,len1,len2);
    return 0;
}