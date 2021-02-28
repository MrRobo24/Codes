#include <bits/stdc++.h>
#define lli long long int
using namespace std;

ofstream out("filename.txt");


class Street {
public:
  lli b, e, l;
  string name;
  Street(lli B, lli E, string name,lli L) {
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
vector<lli> strArr;
vector<lli> carArr;

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

  //taking in D I S V F
  istringstream split(line);
  split >> D >> I >> S >> V >> F;


  strArr.resize(S);
  for (auto &i: S) {
    lli B, E, L;
    string name;
    getline(inputFile, line);
    istringstream split2(line);
    split2 >> B >> E >> name >> L;

    strArr.push_back(Street(B, E, name, L));
  }

  for(auto &i: V){
    lli P;
    getline(inputFile, line);
    istringstream split3(line);

    split3 >> P;
    Car curr();
    curr.p = P;
    for (auto &j: P) {
      string strName;
      split3 >> strName;
      curr.carStrArr.push_back(strMap[strName]);
    }
  }

}


int main() {
  // Create and open a text file

  string filepath = "a.txt";
  takeInput(filepath);


  // Close the file
  out.close();
  return 0;

}