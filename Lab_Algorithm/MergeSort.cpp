#include <bits/stdc++.h>
using namespace std;

vector<int> vi(100000);

void myMerge(int left, int right, int m)
{
    int i = left;
    int j = m + 1;
    int k = 0;
    vector<int> T(right-left+1);
    while (i <= m && j <= right) {
        if (vi[i] <= vi[j]) T[k++] = vi[i++];
        else T[k++] = vi[j++];
    }
    while (i <= m) T[k++] = vi[i++];
    while (j <= right) T[k++] = vi[j++];
    for (size_t i1 = 0; i1 < T.size(); i1++){
        vi[left+i1] = T[i1];
    }
}

void mergeSort(int left, int right)
{
    if (left >= right)
        return;
    int m = (left + right) / 2;
    mergeSort(left, m);
    mergeSort(m + 1, right);

    myMerge(left, right, m);
}

int main()
{   
    int n;
    cin >> n;
    for (size_t i=0;i<n;i++) cin >> vi[i];
    mergeSort(0,n1-1);
    for (size_t j=0;j<n;j++) cout << vi[j] << " ";
    return 0;
}