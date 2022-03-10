// Deletions of Two Adjacent Letters
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    string s[1000];
    char c[1000];
    bool ans[1000];
    bool match = false;

    cin >> num;

    for(int i=0; i<num; i++) {
        match = false;
        cin >> s[i];
        cin >> c[i];

        //find c(char) in s(string)

        for(int j=0;j<s[i].length();j++){
            if(s[i][j] == c[i]) {
                if(j%2 == 0 && (s[i].length()-1-j)%2 == 0){
                    match = true;
                    ans[i] = true;
                    break;
                }
            }
        }
        if(match == false){
            ans[i] = false;
        }
    }

    for(int i=0;i<num;i++){
        if (ans[i]){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" <<endl;
        }
    } 

    return 0;
}