#include <bits/stdc++.h>
using namespace std;
 
void preprocess(char* str){
 
    int a[26][26]={0};
    int b[26][26]={0};
    for(int i=0; i<26; i++)
        a[0][i]=1;
 
    for(int i=1;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=j+1;k<26;k++){
                a[i][j]=a[i][j]+a[i-1][k];
            }
        }
    }
 
 
    b[0][0]=1;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++){
            if(j!=0)
             b[i][j]=b[i][j-1]+a[i][j-1];
            if(j==0 && i!=0)
                b[i][j]=b[i-1][25]+a[i-1][25];
        }
 
 
 
    int len = strlen(str);
    int result = 0;
    int mvindx = 0;
    for(int i=len-1; i>=0 ; i--){
        char ch = str[len-1-i];
        int indx = int(str[len-1-i])-'a';
        if(i!=0)
            mvindx=b[i-1][indx+1];
        else 
           mvindx = 0;
        result = result + b[i][indx]-mvindx;
    }
    cout<<"\nResult----"<<str<<"----"<<result;
 
}
 
int main(){
    char a[4] = "aez";
    char b[3]="bc";
    preprocess(b);
    preprocess(a);
 
 
    return 0;
}