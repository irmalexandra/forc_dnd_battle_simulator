#include "Battle.h"

void battle_menu(Payload* payload, FileHandler* file_handler){
    int choice;
    string filename;
    string folder = "Saves/";
    while(true){
        cout << "1. Start Battle\n2. Load different roster and start battle\n0. Quit" << endl;
        cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case 1:
                start_battle();
                break;
            case 2:
                cout << "Enter the filename of the roster you want to load: ";
                cin >> filename;
                file_handler->load_roster(payload, &filename);
                start_battle();
                break;
            case 0:
                return;
            default:
                cout << choice << " is not an option" << endl;
                break;
        }
    }
}

void start_battle(){

}