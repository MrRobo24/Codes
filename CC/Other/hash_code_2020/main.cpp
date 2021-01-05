#include <bits/stdc++.h>
#define LLI unsigned long long
using namespace std;
//LLI c = 0;
LLI B,L,D;
vector<LLI> bookScores;

bool bookScoreComp(LLI first, LLI second) {
    return (bookScores[first] > bookScores[second]);
}

class Library {
public:
    LLI N, T, M, H, ID, bookLim;
    vector<LLI> libBooks;

    Library(LLI ID, LLI N, LLI T, LLI  M) {
        this->ID = ID;
        this->N = N;
        this->T = T;
        this->M = M;
        this->H = 0;
        this->bookLim = 0;
    }

    void sortBooksInLib() {
        //cout << c++ << "\n";
        sort(libBooks.begin(), libBooks.end(), bookScoreComp);
    }

    void calcHeuristic() {
        H = 0;
        bookLim = min((D-T)*M, N);
        // if (bookLim < 0) {
        //     H = -1;
        //     return;
        // }
        for (LLI i=0;i<bookLim; i++) {
            H += bookScores[libBooks[i]];
        }

        //cout << "HEURISTIC : " << H << "\n";
    }

};
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

void preprocessBooks() {
    //sorting all books in each library
    //cout << "L: " << L;
    for (LLI i=0;i<L;i++) {
        //cout << libraries[i].N << " " << libraries[i].T << " " << libraries[i].M << "\n";
        libraries[i].sortBooksInLib();
    }
}


LLI solve() {
    //calculating Heuristic Value for each library
    vector<Library> ans;
    LLI score = 0, dprev = 0;
    while (D > 0 && !libraries.empty()) {
        dprev = D;
        LLI maxim = 0, id = -1, garbage = 0;
        //removing garbage
        vector<Library> temp;
        for (LLI i=0;i<L;i++) {
            if (libraries[i].T < D) {
                temp.push_back(libraries[i]);
            }
        }

        libraries = temp;
        L = libraries.size();


        for (LLI i=0;i<L;i++) {    
            libraries[i].calcHeuristic();
            //cout << libraries[i].H << " " << maxim << "\n";
            if (libraries[i].H > maxim) {
                maxim = libraries[i].H;
                id = libraries[i].ID;
                //cout << maxim << " " << id << "\n";
            }
        }

        for (LLI i=0;i<L;i++) {
            if (libraries[i].ID == id) {
                D -= libraries[i].T;
                score += libraries[i].H;
                //cout << score << " SCORE\n";
                L--;
                ans.push_back(libraries[i]);
                libraries.erase(libraries.begin() + i);
                break;
            }
        }


        //cout << D << " " << dprev << "\n";
        if (D == dprev) {
            break;
        }
    }

    return score;
}


int main() {

    string names[] = {
        "a_example.txt", 
        "b_read_on.txt", 
        "c_incunabula.txt", 
        "d_tough_choices.txt", 
        "e_so_many_books.txt", 
        "f_libraries_of_the_world.txt"
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