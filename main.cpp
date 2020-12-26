// Include all libraries
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <string> 
#include <fstream>

// Defining requirements
using namespace std;
unsigned int microseconds;

// Define numeric checker
bool isNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //when a non numeric value is found, return false
      return true;
}

// Standard variables
double bal = 0; // Player balance
int pre_id; // Public previous player ID
int player_id; // Defining new player id
int current_bait = 50; // Standard bait amount
int tool_wear = 100; // Standard tool wear
int tool_usage = 10; // Standard tool usage
int tool_up_cost; // Defining upgrade cost for tool
int req_bait = 5; // Standard required bait
int bait_usage = 5; // Standard bait usage
int fish_amount = 0; // Defining fish amount
int fish_caught; // Defining fish caught
int fish_chance = 5; // Defining chance for fishing
int fish_price; // Defining fish price for market
int fish_value = 5; // Defining value interval per fish
int fish_total; // Defining total cashout after selling
std::string fish_ans; // Defining fishing std::cin answer
std::string player_name;

// MenuGUI function()
void menuGUI() {
    std::cout << "\n----------------------------\n\n";
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
    std::cout << "#                          #\n";
    std::cout << "# [7] DEBUG                #\n";
    std::cout << "############################\n\n";

    std::cout << "Num: ";
    std::string menu_ans;
    std::string market_ans;
    std::cin >> menu_ans;
    std::cout << "\n";

    if(isNumeric(menu_ans)) {
        if(menu_ans == "1") {
            // Line break
            std::cout << "----------------------------\n";

            // Fishing-task
            std::cout << "\n//Fishing//\n";
            std::cout << "Fishing costs " << req_bait << " bait and " << tool_usage << "% of your fishing tool\n";
            std::cout << "Would you like to continue?\n";
            std::cout << "[Yes] or [No]\n\n";
            std::cin >> fish_ans;

            while(fish_ans == "Yes" && current_bait >= req_bait && tool_wear >= tool_usage) {
                fish_caught = rand() % fish_chance;
                fish_amount = fish_amount + fish_caught;
                tool_wear = tool_wear - tool_usage;
                current_bait = current_bait - bait_usage;

                // Line break
                std::cout << "----------------------------\n";

                std::cout << "\nBait = " << current_bait;
                std::cout << "\nTool = " << tool_wear;
                std::cout << "\nFish = " << fish_amount;
                std::cout << "\n\n";
            
                // Line break
                std::cout << "----------------------------\n";

                std::cout << "\n//Fishing//\n";
                std::cout << "Fishing costs " << req_bait << " bait and " << tool_usage << "% of your fishing tool\n";
                std::cout << "Would you like to continue?\n";
                std::cout << "[Yes] or [No]\n\n";

            std::cin >> fish_ans;
            }
            if(fish_ans == "No") {
                std::cout << "\n----------------------------\n";
                std::cout << "\nSending you back to the menu\n\n";
                menuGUI();
            } 
            else if(current_bait < req_bait) {
                std::cout << "\n----------------------------\n";
                std::cout << "\n### You do not have enough bait ###\n";
                menuGUI();
            }
            else if(tool_wear < tool_usage) {
                std::cout << "\n----------------------------\n";
                std::cout << "\n### Your tool does not have enough wear ###\n";
                menuGUI();
            }
        }
        else if(menu_ans == "2") {
            // Line break
            std::cout << "----------------------------\n";

            // Show inventory
            std::cout << "Bait = " << current_bait << "     ";
            std::cout << "Tool = " << tool_wear;
            std::cout << "\nFish = " << fish_amount << "      ";
            std::cout << "Chances = 1/" << fish_chance;
            std::cout << "\n";
            menuGUI();
        }
        else if(menu_ans == "3") {

            std::string bal_ans;

            // See balance
            std::cout << "\n//Balance//\n";
            std::cout << "You currently have $" << bal;
            std::cout << "\n\nWould you like to go back?\n";
            std::cout << "[Yes] or [No]\n\n";

            std::cin >> bal_ans;

            if(bal_ans == "Yes") {
                menuGUI();
            }
            else {
                std::cout << "\nWell this is awkward.. How long do you want to stay lol\n\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                std::string loading = ".....\n";

                for (const auto c : loading) {
                    std::cout << c << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                std::cout << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                std::cout << "Jesus can we go back soon?\n\n";

                for (const auto c : loading) {
                    std::cout << c << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                std::cout << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                std::cout << "Fine I'll force you to go back!\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                menuGUI();
            }

        }
        else if(menu_ans == "4") {
            std::cout << "--------------------------------\n\n";
            std::cout << "##########[  Market  ]##########\n";
            std::cout << "# [1] Sell your fish           #\n";
            std::cout << "# [2] Upgrade your tool        #\n";
            std::cout << "# [3] Buy new tool             #\n";
            std::cout << "# [4] Buy bait.                #\n";
            std::cout << "# [5] Improve your reputation  #\n";
            std::cout << "#                              #\n";
            std::cout << "# [6] %B14ck M4rk3t%           #\n";
            std::cout << "################################\n\n";

            std::cout << "Num: ";
            std::cin >> market_ans;

            if(market_ans == "1") {
                std::cout << "\n//Selling fish//\n";
                fish_price = rand() % fish_value;

                fish_total = fish_price * fish_amount;

                bal = bal + fish_total;

                std::cout << "\nSelling fish for $" << fish_price << " pr/fish\n";

                fish_amount = 0;

                std::cout << "Wow" << player_name << "! After selling your fish, you now have $" << bal;

                menuGUI();
            }
            else if(market_ans == "2") {
                tool_up_cost = bal / 5 * 2;

                if(tool_up_cost < 10) {
                    tool_up_cost = 10;
                }

                std::cout << "\n//Tool forge//\n";
                std::cout << "Here you can upgrade your tool.\nA tool upgrade costs $" << tool_up_cost << " to upgrade.\n\nDo you really want to upgrade?\n";
                std::cout << "[Yes] or [No]\n\n";

                std::string toolup_ans;
                std::cin >> toolup_ans;

                if(toolup_ans == "Yes" && bal > 10) {
                    bal = bal - tool_up_cost;
                    tool_wear = tool_wear + 150 * 1.1;
                    fish_chance = fish_chance * 1.5;
                    std::cout << "Your tool wear has been upgraded by 10% and your chance of getting fish is now 1/" << fish_chance;

                    menuGUI();
                }
                else {
                    menuGUI();
                }
            }
            else if(market_ans == "3") {
                menuGUI();
            }
            else if(market_ans == "4") {
                std::cout << "\n//Bait shack//\n";
                std::cout << "Bait costs $1 pr/bait.\n\nHow much do you want to buy?\n";

                int bait_ans;
                std::cin >> bait_ans;

                if(bait_ans <= bal) {
                                    
                    bal = bal - bait_ans;
                    current_bait = current_bait + bait_ans;

                    std::cout << "You bought $" << bait_ans << " worth of bait and currently have $" << bal << " left in your wallet";

                    menuGUI();
                }
                else if(bait_ans >= bal) {
                    std::cout << "\nNot enough cash\n";
                    menuGUI();
                }
            }
            else if(market_ans == "5") {
                menuGUI();
            }
            else if(market_ans == "6") {
                menuGUI();
            }
        }
        else if(menu_ans == "5") {
            // Go to black market
            std::cout << "//B-Market//";
        }
        else if(menu_ans == "6") {
            // Go to dealership
            std::cout << "//Dealership//";
        }
        else if(menu_ans == "7") {
            ofstream ids;
            ids.open ("playerIDs.txt");
            ids << player_name << "-" << pre_id << "\n";
            ids.close();

            std::string idb_out;

            ifstream idb;
            idb.open ("playerIDs.txt");
            while (getline(idb, idb_out)) {
                idb_out = player_id;
                std::cout << "Your id is " << player_id << "\n";
            idb.close();
            }
        }
        else {
            // Send back to menu if answer is not valid
            std::cout << "Answer not accepted";
            menuGUI();
        }
    }
    else {
        std::cout << "Answer is not alphanumeric";
        menuGUI();
    }
}

// main function()
int main() {

    std::string s = ""; // Welcome message "Welcome to fishing simulator!"

    for (const auto c : s) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;

//    std::cout << "\n----------------------------\n";
//    std::cout << "\nWhat do you want your username to be?\n";
//    std::cout << "Name: ";
//    std::cin >> player_name;
//    std::cout << "\n";
//    std::cout << "Cool! Welcome " << player_name << ", hope you enjoy the game\n";

    menuGUI();

}


