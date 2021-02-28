#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

ofstream out("filename.txt");


class Street {
public:
  lli b, e, l;
  string name;
  Street() {

  }

  Street(lli B, lli E, string name, lli L) {
    this->b = B;
    this->e = E;
    this->name = name;
    this->l = L;
  }
};

class Car {
  public:
  lli p;
  vector<Street> carStrArr;
};



lli D, I,  S, V,  F;
vector<Street> strArr;
unordered_map<string, Street> strMap;
map<pair<lli,lli>, string> strName;
vector<Car> carArr;


//arr to store number of cars for each intersection path
vector<vector<lli>> nodeCars;

void print(lli n) {

  cout << n << " ";

}

void println(lli n) {
  cout << n << "\n";
}

void takeInput(const string &inputPath) {

  ifstream inputFile;
  inputFile.open(inputPath.c_str());

  if (!inputFile) {
      cout << "FILE ERROR";
      throw uncaught_exception;
  }
    
  string line;
  getline(inputFile, line);

  istringstream split(line);
  split >> D >> I >> S >> V >> F;
  
  nodeCars.resize(I);

  //taking in Street info for each street
  for (lli i=0;i<S;i++) {
    lli B, E, L;
    string name;
    getline(inputFile, line);
    istringstream split2(line);
    split2 >> B >> E >> name >> L;

    strArr.push_back(Street(B, E, name, L));
    strMap[name] = strArr[strArr.size()-1];
    strName[{B, E}] = name;
  }

  //taking in Car info for each car
  for (lli i=0;i<V;i++) {
    lli P;
    getline(inputFile, line);
    istringstream split3(line);

    split3 >> P;
    Car curr;
    curr.p = P;
    for (lli j=0;j<P;j++) {
      string strName;
      split3 >> strName;
      Street str = strMap[strName];
      curr.carStrArr.push_back(str);

      //trying to input values in for ranking later
      
      nodeCars[str.e].push_back(str.b);

    }

    carArr.push_back(curr);


  }

}


void test() {
  
    lli cnt = 0;

    lli d = 0;
    for (auto &i: nodeCars) {
        if (i.size() == 0) {
            d++;
        }
    }

  out << I-d << endl;
  cout << I-d << endl;
  
  for(lli i=0;i<I;i++) {

      lli n = nodeCars[i].size();



      unordered_map<lli,lli> fr;
      for (lli j=0;j<n;j++) {
          
          fr[nodeCars[i][j]]++;
      }


        if (fr.size() == 0) {
            // out << "\n";
            // cout << "\n";
            continue;
        }


        cout << i << endl;
        out << i << endl;


        cout << fr.size() << endl;      
        out << fr.size() << endl;

      

      vector<pair<lli,lli> > f;
      for (auto &m: fr) {
          f.push_back({m.second, m.first});
      }

      //cout << f.size() << "SIZE\n";

      sort(all(f), greater< pair<lli,lli> >());

        lli c = 0;
      for (auto &p: f) {
          lli cars = p.first;
          lli path = p.second;

          lli quant = (rand()%cars)+ 1;

          if (i ==  I-1 && c == f.size()-1) {
            cout << strName[{path, i}] << " " << quant<< endl;
              out << strName[{path, i}] << " " << quant << endl;  
              
        
        } else {
            cout << strName[{path, i}] << " " << quant << endl;
              out << strName[{path, i}] << " " << quant << endl;
        }
        c++;
          
      }

      if (c != fr.size()) {
          break;
          cout << "CHECK\n";
      }

  }




}


int main() {
  // Create and open a text file

    srand(time(0));
  string filepath = "b.txt";
  takeInput(filepath);
  test();

  // Close the file
  out.close();
  return 0;
}

