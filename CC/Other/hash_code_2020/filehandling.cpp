#include <bits/stdc++.h>
#define LLI long long
using namespace std;


void readFile(const string &inputPath) {

    ifstream inputFile;
    inputFile.open(inputPath.c_str());

    if (!inputFile) {
        cout << "FILE ERROR";
        throw uncaught_exception;
    }

    //taking in B L D

    //taking each line one by one as input inside line string
    string line;
    getline(inputFile, line);


    // splitting each line
    istringstream split(line);
    split >> B >> L >> D;
    //cout << B << "\n" << L << "\n" << D << "\n";
    
    //taking in scores
    getline(inputFile, line);
    istringstream split2(line);
    cout << "\n";
    for (LLI i=0;i<B;i++) {
        LLI val;
        split2 >> val;
        bookScores.push_back(val);
        //cout << bookScores[i] << " ";
    }

    LLI garbage = 0; // where L >= D
    for (LLI i=0;i<L;i++) {

        getline(inputFile, line);
        istringstream split3(line);
        LLI N, T, J;
        split3 >> N >> T >> J;
        Library lb(i, N, T, J);


        getline(inputFile, line);
        istringstream split4(line);
        for (LLI j=0;j<N;j++) {
            LLI val;
            split4 >> val;
            lb.libBooks.push_back(val);
        }
        
        if (T < D) {
            libraries.push_back(lb);
        } else {
            garbage++;
        }
        
    }

    L -= garbage; //removing the garbage count
}



int main() {

    string names[] = {
        "a_example.txt", 
        // "b_read_on.txt", 
        // "c_incunabula.txt", 
        // "d_tough_choices.txt", 
        // "e_so_many_books.txt", 
        // "f_libraries_of_the_world.txt"
    };

    LLI ans = 0;
    for (LLI i=0;i<6;i++) {
        readFile(names[i]);
       
        cout << "Preprocessing\n";
        preprocessBooks();
        cout << "Solving " << char('a' + i) << "\n";
        ans += solve();
    }
    //readFile("d_tough_choices.txt");
    

    cout << "ANS: " << ans << "\n";
    //ANS: 22858460
    return 0;
}