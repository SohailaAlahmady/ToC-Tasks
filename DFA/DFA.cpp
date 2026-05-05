#include <iostream>
#include <string>
using namespace std;

bool DFA_recognizer(string s){
    int state=0;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        switch(state){
            case 0:
                if(ch == '0')
                    state = 0;
                else if(ch == '1')
                    state = 1;
                else
                    return false;
                break;
            case 1:
                if(ch == '0')
                    state = 2;
                else if(ch == '1')
                    state = 1;
                else
                    return false;
                break;
            case 2:
                if(ch == '0')
                    state = 0;
                else if(ch == '1')
                    state = 1;
                else
                    return false;
                break;
        }
    }
    if(state == 2)
        return true;
    else
        return false;
}

int main(){
    cout << "\n\tDFA Recognizer for Binary Strings Ending with '10'" << endl;

    string token;
    cout << "Enter the DFA Binary String: ";
    cin >> token;
    if(DFA_recognizer(token))
        cout << "String is accepted!" << endl;
    else
        cout << "String is rejected" << endl;
    return 0;
}