#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <string> 

using namespace std;
unsigned int microseconds;

// Standard variables
double bal = 0;
int pre_id = 1;
int player_id = pre_id + 1;
int req_bait = 5;
int tool_tear = 10;
int current_bait = 0;
int tool_wear = 100;
int fish_amount = 0;
int fish_caught;

void menuGUI() {
    std::cout << "Type num of task to continue: \n";
    std::cout << "##########[ Menu ]##########\n";
    std::cout << "# [1] Go fishing           #\n";
    std::cout << "# [2] Go to inventory      #\n";
    std::cout << "# [3] See balance          #\n";
    std::cout << "#                          #\n";
    std::cout << "# Travel to:               #\n";
    std::cout << "# [4] The market           #\n";
    std::cout << "# [5] The black market     #\n";
    std::cout << "# [6] The boat dealership  #\n";
    std::cout << "############################\n\n";

    int menu_ans;
    std::cin >> menu_ans;
    std::string fish_ans;
    std::string fish_cont;


    if(menu_ans == 1) {
        std::cout << "//Fishing//\n";
        std::cout << "Fishing costs " << req_bait << " bait and " << tool_tear << "% of your fishing tool\n";
        std::cout << "Would you like to continue?\n";
        std::cout << "[Yes] or [No]\n\n";

        std::cin >> fish_ans;

        if(fish_ans == "Yes") {
            fish_caught = rand() % 5;
            fish_amount += fish_caught;
            std::cout << "\nYou caught " << fish_caught << " little fishies!\n";
            std::cout << "You now have " << fish_amount << " fish\n\n";

            std::cout << "Type [Y] to fish again\n";
            
            
            if (cin.get() == 'Y')
                fish_caught = rand() % 5;
                fish_amount += fish_caught;
                std::cout << "\nYou caught " << fish_caught << " little fishies!\n";
                std::cout << "You now have " << fish_amount << " fish\n\n";
        }
        else if(fish_ans == "No") {
            std::cout << "\nNo cont";
        }
        else {
            std::cout << "\nAn error occured";
        }
        
    }
    else if(menu_ans == 2) {
        std::cout << "//Inventory//";
    }
    else if(menu_ans == 3) {
        std::cout << "//Balance//";
    }
    else if(menu_ans == 4) {
        std::cout << "//Market//";
    }
    else if(menu_ans == 5) {
        std::cout << "//B-Market//";
    }
    else if(menu_ans == 6) {
        std::cout << "//Dealership//";
    }

}

int main() {

    std::string s = "Welcome to fishing simulator!";

    for (const auto c : s) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
    std::cout << "-----------------------------\n";

    menuGUI ();

}


