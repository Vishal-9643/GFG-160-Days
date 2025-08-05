// Day 21 : Count Inversions (By Merge Sort).

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }

    return cnt;
}
int mergesort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergesort(arr, low, mid);
    cnt += mergesort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}
int inversionCount(vector<int> &arr)
{
    int n = arr.size();
    return mergesort(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    int ans = inversionCount(arr);
    cout << ans;
}