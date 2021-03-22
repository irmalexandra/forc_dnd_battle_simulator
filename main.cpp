#include <chrono>
#include "string"
#include "Helpers/InputHandler.h"

using namespace std;
int main() {
    cout << "Starting... " << endl;
    cout << "Setting random seed" << endl;
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    auto input_handler = new InputHandler();
    input_handler->main_menu();
    cout << "Exiting" << endl;
    return 0;

}
