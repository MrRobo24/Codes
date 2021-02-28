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
vector<Car> carArr;

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


  //taking in Street info for each street
  for (lli i=0;i<S;i++) {
    lli B, E, L;
    string name;
    getline(inputFile, line);
    istringstream split2(line);
    split2 >> B >> E >> name >> L;

    strArr.push_back(Street(B, E, name, L));
    strMap[name] = strArr[strArr.size()-1];
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
      curr.carStrArr.push_back(strMap[strName]);
    }

    carArr.push_back(curr);

  }

}


void test() {
  lli cnt = 0;
  for (auto &car: carArr) {
    cout << cnt++ << "\n";
    for (lli j=0;j<car.p;j++) {
      cout << car.carStrArr[j].b << " " << car.carStrArr[j].e << "\n";
    }
    cout << "\n";
  }
}


int main() {
  // Create and open a text file

  string filepath = "a.txt";
  takeInput(filepath);
  test();

  // Close the file
  out.close();
  return 0;

}