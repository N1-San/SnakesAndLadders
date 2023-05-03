#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll_dice() {
    return rand() % 6 + 1;
}

int main() {
    string player1_name, player2_name;
    int player1_pos = 0, player2_pos = 0;
    int dice_roll = 0;
    srand(time(0));
    
    cout << "Enter name for player 1: ";
    getline(cin, player1_name);
    cout << "Enter name for player 2: ";
    getline(cin, player2_name);
    
    while (player1_pos < 100 && player2_pos < 100) {
        cout << player1_name << " press any key to roll the dice: ";
        cin.get();
        dice_roll = roll_dice();
        player1_pos += dice_roll;
        cout << player1_name << " rolled a " << dice_roll << endl;
        if (player1_pos == 14 || player1_pos == 27 || player1_pos == 42 || player1_pos == 50 || player1_pos == 71 || player1_pos == 85) {
            cout << "Oops! You landed on a snake. Go back 3 positions." << endl;
            player1_pos -= 3;
        }
        else if (player1_pos == 8 || player1_pos == 21 || player1_pos == 43 || player1_pos == 54 || player1_pos == 67 || player1_pos == 87) {
            cout << "Yay! You found a ladder. Go ahead 6 positions." << endl;
            player1_pos += 6;
        }
        cout << player1_name << " is now at position " << player1_pos << endl;
        if (player1_pos >= 100) {
            cout << player1_name << " wins!" << endl;
            break;
        }
        
        cout << player2_name << " press any key to roll the dice: ";
        cin.ignore();
        cin.get();
        dice_roll = roll_dice();
        player2_pos += dice_roll;
        cout << player2_name << " rolled a " << dice_roll << endl;
        if (player2_pos == 14 || player2_pos == 27 || player2_pos == 42 || player2_pos == 50 || player2_pos == 71 || player2_pos == 85) {
            cout << "Oops! You landed on a snake. Go back 3 positions." << endl;
            player2_pos -= 3;
        }
        else if (player2_pos == 8 || player2_pos == 21 || player2_pos == 43 || player2_pos == 54 || player2_pos == 67 || player2_pos == 87) {
            cout << "Yay! You found a ladder. Go ahead 6 positions." << endl;
            player2_pos += 6;
        }
        cout << player2_name << " is now at position " << player2_pos << endl;
        if (player2_pos >= 100) {
            cout << player2_name << " wins!" << endl;
            break;
        }
    }
    return 0;
}
