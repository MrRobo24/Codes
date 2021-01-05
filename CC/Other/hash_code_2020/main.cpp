#include <bits/stdc++.h>
#define LLI unsigned long long

using namespace std;

class Library {
public:
    LLI N, T, M;
    vector<LLI> libBooks;

    Library(LLI N, LLI T, LLI  M) {
        this->N = N;
        this->T = T;
        this->M = M;
    }
};

LLI B,L,D;
vector<LLI> bookScores;
vector<Library> libraries;



void readFile(const string &inputPath) {
    cout << inputPath << "\n";
    ifstream inputFile;
    inputFile.open(inputPath.c_str());

    if (!inputFile) {
        cout << "FILE ERROR";
        throw uncaught_exception;
    }

    //taking in B L D
    string line;
    getline(inputFile, line);
    istringstream split(line);
    split >> B >> L >> D;
    cout << B << " " << L << " " << D << "\n";
    
    //taking in scores
    getline(inputFile, line);
    istringstream split2(line);
    for (LLI i=0;i<B;i++) {
        LLI val;
        split2 >> val;
        bookScores.push_back(val);
    }

    for (LLI i=0;i<L;i++) {

        getline(inputFile, line);
        istringstream split3(line);
        LLI N, T, J;
        split3 >> N >> T >> J;
        Library lb(N, T, J);


        getline(inputFile, line);
        istringstream split4(line);
        for (LLI j=0;j<N;j++) {
            LLI val;
            split4 >> val;
            lb.libBooks.push_back(val);
        }

        libraries.push_back(lb);
    }
}


int main() {
    readFile("a_example.txt");
    return 0;
}