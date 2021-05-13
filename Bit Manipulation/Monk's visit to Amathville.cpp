   #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long int in;
     
    in dp[(1<<15)];
     
    int main() 
    {
		in m=(1<<15);
 
    	in t,b[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    	cin>>t;
     
    	while(t--)
    	{
            in n,p,i,j,mask,val=0;
    		    cin>>n>>p;
 
			dp[0]=1;
			
			in a[n];
 
			for(i=0;i<n;++i)
			a[i]=i+1;
            
    		for(i=1;i<n;++i)
    		{
    			val=0;
     
    			for(j=0;j<15;++j)
    			if(a[i]%b[j]==0)
    			val=val|(1<<j);
 
				//cout<<val<<" ";
     
    			dp[val]=1;
     
    			for(mask=1;mask<m;++mask)
    			if((mask&val)==0)
    			{
    				dp[(mask|val)]=(dp[(mask|val)])|(dp[mask]);
    			}
    			
    		}
 
			//cout<<"\n";
     
    		in ans=1e18,so=0,ma=1e18;
 
			for(mask=1;mask<m;++mask)
			if(dp[mask])
			{
				if((__builtin_popcountll(mask))>so) 
				{
					//cout<<" i ";
					so=(__builtin_popcountll(mask));
 
					ma=mask;
				}
				else if((__builtin_popcountll(mask))==so)
				ma=min(ma,mask); 
			}
 
			n=so+1;
 
			in c[n],k;
 
			c[0]=1;
      
			for(i=0;i<n-1;++i)
			{
          if((1<<i)&ma)
					c[i+1]=b[i];
			}
 
			in cp[(1<<n)][n];
 
			for(mask=0;mask<(1<<n);++mask)
			for(i=0;i<n;++i)
			if((__builtin_popcountll(mask))>1)
			cp[mask][i]=1e18;
      else
			cp[mask][i]=0;
 
			for(mask=1;mask<(1<<n);++mask)
    {
        for(j=0;j<n;++j)
        if(mask&(1<<j))
        {
            in msk=mask^(1<<j);
 
            for(k=0;k<n;++k)
            if(msk&(1<<k))
            {
              cp[mask][j]=min(cp[mask][j],cp[msk][k]+(c[j]*c[k])%p);
            }
        }
    }
 
		for(i=0;i<n;++i)
		ans=min(ans,cp[(1<<n)-1][i]);
      
			
        //cout<<ma<<" "<<so<<"\n";
     
    		for(i=0;i<m;++i)
    		{
				  dp[i]=0;
    		}
     
    		cout<<ans<<"\n";
    	    
    	}
     
    	return 0;
    }