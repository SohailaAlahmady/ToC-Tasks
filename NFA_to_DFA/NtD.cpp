#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

set<int> move(set<int> current_states, char input){
    set<int> next_states;

    for(int state : current_states){
        switch(state){
            case 0:
                next_states.insert(1);
                //or if(input == '0' || input == '1') next_states.insert(1);
                if(input == '0') next_states.insert(0);
                break;
            case 1:
                if(input == '1') next_states.insert(1);
                if(input == '1') next_states.insert(0);
                break;
        }
    }
    return next_states;
}

void convert_NFA_to_DFA(){
    map<set<int>, int> dfa_states;
    queue<set<int>> unprocessed;

    set<int> start_state = {0};
    dfa_states[start_state] = 0;
    unprocessed.push(start_state);

    int state_count = 0;
    const int NFA_ACCEPT_STATE = 1;

    cout<<"\n----------- DFA Transition Table -----------"<<endl;
    cout<<"State ID\tStatus\t\tOn 0\tOn 1"<<endl;
    cout<<"--------------------------------------------"<<endl;

    while(!unprocessed.empty()){
        set<int> current = unprocessed.front();
        unprocessed.pop();

        int current_id = dfa_states[current];
        cout << current_id << "\t\t";

        bool isAccepting = current.count(NFA_ACCEPT_STATE); //NFA_state = 1
        cout << (isAccepting ? "Accepting" : "Non-Accepting") << "\t";

        for(char symbol : {'0', '1'}){
            set<int> next = move(current, symbol);

            if(!next.empty() && dfa_states.find(next) == dfa_states.end()){
                dfa_states[next] = ++state_count;
                unprocessed.push(next);
            }

            if(next.empty()) cout << "Trap\t";
            else cout << dfa_states[next] << "\t";
        }
        cout << endl;
    }
}

int main(){
    cout << "\n\t    NFA to DFA Converter" << endl;
    convert_NFA_to_DFA();

    return 0;
}