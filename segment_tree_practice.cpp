#include<bits/stdc++.h>
using namespace std;


void construct_tree(int arr[],int segtree[],int low,int high,int pos)
{

	if(low==high)
	{
		segtree[pos]=arr[low];
		return;
	}
	int mid=(low+high)>>1;
	construct_tree(arr,segtree,low,mid,(2*pos)+1);
	construct_tree(arr,segtree,mid+1,high,(2*pos)+2);
	segtree[pos]=min(segtree[(2*pos)+1],segtree[(2*pos)+2]);

}

// Below function computes minimum in a range
int range_query(int arr[],int segtree[],int qlow,int qhigh,int low,int high,int pos){
	
	if(qlow<=low && qhigh >=high)  //total overlap
	{
		return segtree[pos];
	}

	if(qlow>high || low>qhigh)    // No Overlap
	{
		return INT_MAX;
	}
	int mid=(low+high)>>1;
	
	return min(range_query(arr,segtree,qlow,qhigh,low,mid,2*pos+1),range_query(arr,segtree,qlow,qhigh,mid+1,high,2*pos+2));

}



int main()
{
	int n;
	cin>>n;
	int arr[n];
	int segtree[4*n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	construct_tree(arr,segtree,0,n-1,0);
	int t;
	cin>>t;
	while(t--)
	{
		int qlow,qhigh;
		cin>>qlow>>qhigh;
		cout<<range_query(arr,segtree,qlow,qhigh,0,n-1,0)<<endl;
	}
	return 0;

}