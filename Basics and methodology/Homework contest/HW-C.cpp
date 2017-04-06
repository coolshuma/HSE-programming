#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_tab(const string& command, int tab) {
    for (size_t i = tab - 1; i > -1; --i) {
        if (command[i] != ' ')
            return true;
    }
    return false;
}



void do_cycle(int number) {

}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    string command;
    int cur_tab = 0;
    int cur_cycle = -1;
    vector<vector<string>> cycle;
    vector<int> cycle_iteration;

    while (getline(cin, command)) {
        if (is_tab(command, cur_tab)) {
            if (cur_cycle > -1) {
                cycle[cur_cycle].push_back();
            }
        }
    }


    return 0;
}


