#include <iostream>
#include "auto_sort.hpp"
#include "auto_sort.cpp"

using namespace std;

int main() {
    // introduction
    cout << "Auto Sorting List Program" << endl;

    while (true) {
        // I like creating the base list here, instead of above. idk why. Just like it better.
        // Need create this list to solve error on display_list() function call.
        list my_list;
        my_list.create_list();
        int menu1;
        int menu_start = 1;
        int menu_end = 7;
        cout << "\n" << endl;

        show_menu();

        if (cin >> menu1 && menu1 >= menu_start && menu1 <= menu_end) {
            switch (menu1) {
            case 1:
                // create list - working
                // create new list effectively deletes the old linked list, but not literally.
                // "forgets" but does not delete.
                list my_list;
                my_list.create_list();
                reset_list_size();
                break;
            case 2:
                // display list - working
                my_list.display_list();
                break;
            case 3:
                // Add item to list - working
                cout << "Value to add: ";
                my_list.insert(my_list.ask_for_data());
                break;
            case 4:
                // Search for item - not even close to working
                cout << "Value to search: ";
                my_list.search_element(my_list.ask_for_data());
                break;
            case 5:
                // Test Module - working
                test_module();
                break;
            case 6:
                // Populate list - used in testing
                my_list.insert(1);
                my_list.insert(0);
                my_list.insert(4);
                my_list.insert(9);
                my_list.insert(7);
                my_list.insert(2);
                my_list.insert(3);
                break;
            case 7:
                // Quit - working
                cout << "Quitting..." << endl;
                system("pause");
                return 0;
            default:
                break;
            }
        } else {
            cout << "Please choose a valid menu choice" << endl;
            cin.clear();
            // this prevents string input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}
