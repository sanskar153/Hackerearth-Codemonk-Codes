#include<iostream>
#include<queue>
using namespace std;
 
int main()
{
    int q,x,y;
    char c;
    vector<queue<pair<int,int> > > que;
    queue<pair<int,int> >tempq;
    cin >> q;
 
    while(q--)
    {
        cin >> c;
        if(c=='D')
        {
         cout<<que[0].front().first<<" "<<que[0].front().second<<endl;
            que[0].pop();
            if(que[0].empty())
                que.erase(que.begin());
        }
        else
        {
            cin >> x >> y;
            int idx=0;
            while(idx<que.size() && que[idx].front().first!=x)
                idx++;
            if(idx==que.size())
            {
                tempq.push(make_pair(x,y));
                que.push_back(tempq);
                tempq.pop();
            }
            else
                que[idx].push(make_pair(x,y));
        }
    }
 
 
    return 0;
}