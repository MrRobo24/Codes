#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second

map<string,int> path_len;
map<string,int> edge_to_node;
map<string,int> reord;
vector<int> adj[100009];
set <int> en[100009],st[100009];
ll total_time,nodes,edges,cars,points;
map<pair<int,int>,string> mp;
map<pair<int,int>,int> mp1;     // which street index connects a and b
bool vis[100009];
int arr[100009];
vector<pair<int,string> > paths[100009];
vector<pair<string,int>> ans[100009];
void readFile(const string &inputPath)
{
    ifstream inputFile;
    inputFile.open(inputPath.c_str());

    if (!inputFile)
    {
        cout << "FILE ERROR";
        throw uncaught_exception;
    }

    string line;
    getline(inputFile, line);
    istringstream split(line);
    split >> total_time >> nodes >> edges >> cars >> points;
    for(int i=0;i<edges;i++)
    {
        getline(inputFile, line);
        istringstream split1(line);
        int a,b;
        split1>>a>>b;
        string street_name;
        split1>>street_name;
        reord[street_name]++;
        mp[{a,b}]=street_name;
        int street_len;
        split1>>street_len;
        path_len[street_name] = street_len;
        edge_to_node[street_name] = b;
    }
    for(int i=0;i<cars;i++)
    {
      getline(inputFile, line);
      istringstream split1(line);
      split1>>arr[i];
      for(int j=0;j<arr[i];j++)
      {
        string s;
        split1>>s;
        if(j==0)continue;
        paths[i].pb({path_len[s],s});
      }
    }
    for(int i=1;i<=total_time;i++)
    {

      for(int j=0;j<cars;j++)
        {

          for(auto it: paths[j])
          {
            if(it.F==i)
            {
              ans[edge_to_node[it.second]].pb({it.second,1});
            }
          }
        }
    }
    ofstream MyFile("C:\\Users\\manis\\Documents\\a_out.txt");
    int cnt=0;
    for(int i=0;i<100009;i++)
    {
      if(ans[i].size()>0)
      {
        cnt++;
      }
    }
    MyFile<<cnt<<endl;
    for(int i=0;i<100009;i++)
    {
      if(ans[i].size()>0)
      {
        MyFile<<i<<endl;
        MyFile<<ans[i].size()<<endl;
        for(auto it: ans[i])
        {
          MyFile<<it.F<<" "<<it.second<<endl;
        }
      }
    }



    
    
}
void finds()
{
    
    
}
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string file_name = "C:\\Users\\manis\\Documents\\a.txt";
    readFile(file_name);
}