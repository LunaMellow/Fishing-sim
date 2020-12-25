// Include all libraries
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <string> 

// Defining requirements
using namespace std;
unsigned int microseconds;

// Standard variables
double bal = 0; // Player balance
int pre_id = 1; // Public previous player ID
int player_id = pre_id + 1; // Defining new player id
int current_bait = 20; // Standard bait amount
int tool_wear = 100; // Standard tool wear
int tool_usage = 10; // Standard tool usage
int req_bait = 5; // Standard required bait
int bait_usage = 5; // Standard bait usage
int fish_amount = 0; // Defining fish amount
int fish_caught; // Defining fish caught
std::string fish_ans; // Defining fishing std::cin answer

// MenuGUI function()
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

    if(menu_ans == 1) {
        // Fishing-task function
        std::cout << "//Fishing//\n";
        std::cout << "Fishing costs " << req_bait << " bait and " << tool_usage << "% of your fishing tool\n";
        std::cout << "Would you like to continue?\n";
        std::cout << "[Yes] or [No]\n\n";

        std::cin >> menu_ans;
        std::cin >> fish_ans;

        while(fish_ans == "Yes" && current_bait > req_bait && tool_wear > tool_usage) {
            fish_caught = rand() % 5;
            fish_amount = fish_amount + fish_caught;
            tool_wear = tool_wear - tool_usage;
            current_bait = current_bait - bait_usage;
            std::cout << "\nBait = " << current_bait;
            std::cout << "\nTool = " << tool_wear;
            std::cout << "\nFish = " << fish_amount;
            std::cout << "\n\n";
        }
        if(fish_ans == "No") {
            std::cout << "You answered no";
        } 
        else if(current_bait >! req_bait) {
            std::cout << "\n### You do not have enough bait ###\n\n";
        }
        else if(tool_wear >! tool_usage) {
            std::cout << "\n### Your tool does not have enough wear ###\n\n";
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
    else {
        std::cout << "Answer not accepted";
        menuGUI();
    }
}

// main function()
int main() {

    std::string s = "S"; //"Welcome to fishing simulator!"

    for (const auto c : s) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
    std::cout << "-----------------------------\n";

    menuGUI ();

}


