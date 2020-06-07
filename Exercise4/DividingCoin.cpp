#include <iostream>
using namespace std;
int main(){
    int n,m;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&m);
        int arr[n+5];
        int w = 0;
        for (int j=0;j<m;j++){
            scanf("%d",&arr[i]);
            w += arr[i];
        }
        bool ans[(w/2)+1] = {false};
        ans[0] = true;
        for (int i=0;i<m;i++){
            for (int j=(w/2);j>=0;j--){
                if (ans[j] && j+arr[i] <= w/2) ans[j+arr[i]] = true;
            }      
        }
        int loop;
        for (loop=w/2;!ans[loop];loop--);
        //cout << loop;
        printf("%d\n",w-loop-loop);
    }
    return 0;
}