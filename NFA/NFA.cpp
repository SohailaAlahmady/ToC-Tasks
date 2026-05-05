#include <iostream>
#include <string>
#include <set>
using namespace std;

bool NFA_recognizer(string s){
    set<int> current_states;
    current_states.insert(0);

    for(char ch : s){
        set<int> next_states;

        for(int state : current_states){
            switch (state){
                case 0:
                    if(ch == 'a' || ch == 'b') next_states.insert(0);
                    if(ch == 'a') next_states.insert(1);
                    break;
                case 1:
                    if(ch == 'b') next_states.insert(1);
                    if(ch == 'b') next_states.insert(2);
                    break;
                case 2:
                    break;
            }
        }
        current_states = next_states;
    }
    return current_states.count(2);
}

int main(){
    cout << "\n\tNFA Recognizer for Language (a+b)* a b* b" << endl;
    
    string token;
    cout << "Enter the NFA String: ";
    cin >> token;
    if(NFA_recognizer(token))
        cout << "String is accepted!" << endl;
    else
        cout << "String is rejected " << endl;
    return 0;
}