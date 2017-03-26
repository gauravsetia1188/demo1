#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000
ll int sizes=0;

ll int b[11];
ll int c[11];
// this is a sexy code
void multiply(ll int f[10][10],ll int m[10][10])
{
    ll int l[10][10]={0};



	for(ll int i=0;i<sizes;i++)
		for(ll int j=0;j<sizes;j++)
			for(ll int k=0;k<sizes;k++)
			{
				l[i][j]+=((f[i][k]%mod)*(m[k][j])%mod)%mod;
			}
    for(ll int i=0;i<sizes;i++)
    {
        for(int j=0;j<sizes;j++)
            f[i][j]=l[i][j];
    }

}





void power(ll int n,ll int f[10][10],ll int m[10][10])
{
	if(n<2)
		return;
	power(n/2,f,m);

	multiply(f,f);

	if(n&1)
		multiply(f,m);


}


ll int solve(ll int k)
{
   	    long long int f[10][10];
        long long int m[10][10];

        for(ll int i=0;i<sizes;i++)
	    	{
	    		for(ll int j=0;j<sizes;j++)
	    			{
	    				f[i][j]=0;
	    				m[i][j]=0;
	    			}
	    	}


	    for(ll int i=0;i<sizes;i++)
	    	{
		    	f[0][i]=c[i];
		    	m[i][i-1]=1;
		    }
        power(k,f,m);
        //return (F[0][0]) % c ;
        ll int ans=0;
        for(ll int i=0;i<sizes;i++)
        {
        	ans=(ans+((f[0][i]%mod)*(b[sizes-i-1])%mod)%mod)%mod;

        }
    	return ans;
}






int main()
{

	ll int t;
	cin>>t;
	while(t--)
	{
		cin>>sizes;
		for(ll int i=0;i<sizes;i++)
			cin>>b[i];

		for(ll int i = 0;i<sizes;++i) b[i] %= mod;

		for(ll int i=0;i<sizes;i++)
			cin>>c[i];

		ll int n;
		cin>>n;

		if(n<=sizes)
			cout<<b[n-1]<<endl;
		else
		{
			ll int ans=solve(n-sizes);

			cout<<(ans%mod)<<endl;
		}

	}
return 0;
}
