#include<iostream>
#include<cstring>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    string a;
    while(t--)
    {   
        getline(cin, a);
        while (a.length()==0 )
            getline(cin, a);
            
        int n = 0,i = 0;
        char temp;
        int sum = 0;
        for(int j = 0; j<=(int)a.length()-1; j++)
        {   
            temp = a[j];
            
            if(temp==' ')
            {
                n++;
                i = 0;
            }
            
            else if(temp>=97 && temp<=122)
            sum = sum + (temp - 'a') + (i++);
            
            else if(temp>=65 && temp<=90)
            sum = sum + (temp - 'A') + 36 + (i++);
            
            else if(temp>=49 && temp<=57)
            sum = sum + (temp - '0') + 25 + (i++);
            
            else if(temp==48)
            sum = sum + 35 + (i++);
            
            
            //cout<<sum<<endl;
        }
        
        printf("%d\n",sum*(n+1));    
        
    }
    
    
	return 0;
}