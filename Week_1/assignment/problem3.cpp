#include<bits/stdc++.h>
using namespace std;
int binarySearch(int nums[],int l, int r, int k)
{
    while (l<=r)
    {
        int mid = (l+r)/2;

        if(nums[mid]==k)
        {
            if(l==r) return -1;
            else if(nums[mid+1]==k) return 1;
            else if (nums[mid-1]==k) return 1;
            else return -1;
        }

        if(nums[mid]>k) r=mid-1;
        else l=mid+1;
    }
    return -1;
}


int main()
{
    int n; cin>>n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    int k; cin>>k;

    int ans = binarySearch(nums,0,n-1,k);
    ans==-1 ? cout<<"No"<<endl : cout<<"Yes"<<endl;
    
       
    return 0;
}