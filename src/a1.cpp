/*
 * PLAN
 * ----
 * Input strategy:
 *    How will I collect numbers?
 *         I plan to use a do-while loop with a cin function to allow the user to input a new 
        number each iteration. This seems to be the simplest way to pull this off.
 *    What stops the loop?
 *         I will use a break function to break the loop if the user's input is 0, this 
        should also make it easier to impliment the other criteria for entering a number.
 * 
 * Validation:
 *    What makes a number ivalid?
 *         If it's negative, it's over 999, or there aren't enough numbers input.
 *    What happens to it?
 *         I will ignore it and ask the user to try again.
 * 
 * Statistics:
 *    What values do I need to track?
 *         The max input, min input, how many numbers are input, the sum of all numbers, and...
 * 
 * Favorite Num:
 *    Why did I choose to add the favorite num statistic?
 *         I thought it'd be funny to have a guessing game! I will tell the user how many 
        guesses were more and less than the answer.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /*For General Stats:*/
    int num; // For users input
    int iter = 0; // For iterations
    int max = 1;
    int min = max;
    int total = 0;
    double average = 0.0;

    /*For My Favorite Number:*/
    int greater_fav = 0;
    int less_fav = 0;
    bool guessed = false;

    do {
        cout << "Enter a positive integer from 1 to 999 (0 to quit): " << endl;
        cin >> num;

        /*Input limits other than 0:*/
        if (num != 0) {
            if (num < 0) {
                cout << "I'm sorry, that is not a positive number. Please try again." << endl;
                continue;
            } else if (num >= 1000) {
                cout << "I'm sorry, please enter a whole number from 1 to 999." << endl;
                continue;
            }

            if (num > max) {
                max = num;
            } else if (num < min) {
                min = num;
            }

            /*For my favorite number:*/
            if (num > 435) {
                greater_fav++;
            } else if (num < 435) {
                less_fav++;
            } else {
                guessed = true;
            }

            total += num;
            iter++;
        
        /*Attempt break loop:*/
        } else if (iter < 3) {
            cout << "I'm sorry, you need at least 3 values. Keep going." << endl;
            continue;
        } else {
            break;
        }
    } while(true);

    average = (total * 1.0) / iter;

    cout << "\nGeneral Statistics: " << setw(60) << "Guess My Favorite Number:\n" << endl;

    cout << 
    setw(10) << "Count" << 
    setw(10) << "Minimum" << 
    setw(10) << "Maximum" << 
    setw(10) << "Total" << 
    setw(10) << "Average" << 
    "  |  " << 
    setw(12) << "Greater" << 
    setw(12) << "Lesser" << 
    setw(12) << "Correct?" << endl;

    cout << "==================================================  |  ====================================" << endl;

    cout << 
    setw(10) << iter << 
    setw(10) << min << 
    setw(10) << max << 
    setw(10) << total << 
    setw(10) << fixed << setprecision(2) << average << 
    "  |  " << 
    setw(12) << greater_fav << 
    setw(12) << less_fav << 
    setw(12) << guessed << endl;

    return 0;
}