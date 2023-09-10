#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18;
#define ninf -1e18;
class SGtree{
vector<int>seg;
public:
SGtree(int n)
{
    seg.resize(4*n);
}
void build(int ind,int l,int  r,vector<int>&nums)
{
    if(l==r)
    {
        seg[ind]=nums[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*ind+1,l,mid,nums);
    build(2*ind+2,mid+1,r,nums);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r)
{
    if(high<l || r<low)
    {
        return inf;
    }
    if(low>=l && high<=r)
    {
        return seg[ind];
    }
    int mid=(low+high)>>1;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}
void update(int ind,int low,int high,int i,int val)
{
    if(high==low)
    {
        seg[ind]=val;
    }
    int mid=(low+high)>>1;
    if(i<=mid)
    update(2*ind+1,low,mid,i,val);
    else
    update(2*ind+2,mid+1,high,i,val);
}
};
int32_t main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    SGtree sg(n);
    sg.build(0,0,n-1,nums);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sg.query(0,0,n-1,l,r)<<"\n";
    }
}