#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> iii;
int main(){
    int n,k;
    while(scanf("%d",&n)!=EOF){
        int arr[n+1];
        for (int i=0;i<n;i++) scanf("%d",&arr[i]);
        scanf("%d",&k);
        //different, lessNum, moreNum
        priority_queue<iii,vector<iii>,greater<iii>> Q;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (arr[i]+arr[j] == k){
                    if (arr[i] > arr[j]) Q.push(make_tuple(arr[i]-arr[j],arr[j],arr[i]));
                    else Q.push(make_tuple(arr[j]-arr[i],arr[i],arr[j]));
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d\n\n",get<1>(Q.top()),get<2>(Q.top()));
    }
    
    return 0;
}