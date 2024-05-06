#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <limits>

using namespace std;

int test_module();
void show_menu(void);

int size_of_list = 0; // init at 0

// list.hpp
struct node {
    int data;
    node *next;
};

class list {
    private:
        node *head;

    public:
        void create_list();
        int ask_for_data();
        void insert(int size_data);
        void display_list();
        int search_element(int search_value);
};


// this method actually instantiates the list, the stuff before was just defining
void list::create_list() {
    head = nullptr;
}

/* I had this functionality placed within the insert function at first, but hated that. This 
makes it way simpler, because I can use it in more functions easily 
does not handle string  */
int list::ask_for_data() {
    int user_data;
    cout << "Value: ";
    cin >> user_data;
    return user_data;
}


// int size_data = ask_for_data();

// call this in main with my_list.insert()
void list::insert(int size_data) {
    // create new node pointing to nullptr
    node *new_node = new node;
    // the value of the new element is defined here
    new_node->data = size_data;
    new_node->next = nullptr;

    // if the node points to nullptr, list is empty
    // and if data at the head is larger than the user input
    // place on left side by shifting the pointer
    if (head == nullptr || size_data < head->data) {
        new_node->next = head;
        head = new_node;
        size_of_list++;
        return;
    }

    // else list is populated
    // had help from chat GPT for this part... this is the part that sorts.
    // create temporary node starting at the beginning of the list, The "head"
    node *temp = head;
    // traverse the list.
    /* while the temp node does not point at nullptr, and the data of the NEXT 
    node is less than the user input value, shift node and traverse one step in 
    list until it matches size_data*/
    while (temp->next != nullptr && size_data > temp->next->data) {
        temp = temp->next;
    }

    // this part actually does the assigning of the pointer values.
    new_node->next = temp->next;
    temp->next = new_node;

    size_of_list++;
}



void list::display_list() {
    cout << "Size of list: " << size_of_list << endl;
    /* I like to think of this temp node as a shuttle on a loom 
    or maybe like the head of a typwriter, but this one allows 
    insertion*/
    node *temp = head;
    cout << "List: ";
    // if no nodes, no elements, just a nullptr
    if (temp == nullptr) {
        cout << "[no elements in list]";
    }
    // cycle through and print the list until hits the terminal node
    // adds a whitespace and then goes to next node
    // cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << endl;
    return;
}


int list::search_element(int search_value) {
    cout << "this is supposed to search for a single node, " << endl;
    cout << "idk" << endl;

    // int search_value = ask_for_data();

    // create temporary node to act as shuttle
    node *temp2 = head;
    int index = 0; // init index at 0

    // this begins teh traversal and ends it, but thinking about it, i don't think I need to end it like this.
    while (temp2 != nullptr && temp2->data <= search_value){
        //traverse
        if (temp2->data == search_value) {
            cout << "Value " << search_value << " found at index " << index << endl;
            return index;
        }
        temp2 = temp2->next;
        index++;
    }

    // if not found
    cout << "Sorry, " << search_value << " not found." << endl;
    return 0;
}

void reset_list_size() {
    size_of_list = 0;
}

int test_module() {
    // code here
    reset_list_size();
    cout << "\nTHIS IS THE TEST MODULE!" << endl;
    cout << "------------------------" << endl;
    cout << "This module creates a list, then modifies that list." << endl;
    cout << "Creates separate linked list: \"test_list\"\n" << endl;
    list test_list;
    test_list.create_list();
    cout << "\ndisplay empty test_list" << endl;
    cout << "------------------------" << endl;
    test_list.display_list();
    
    cout << "\n\nadding values..." << endl;
    cout << "------------------------" << endl;
    cout << "adding: 2, 4, -2, 10, 0, 14, 1, -7" << endl;
    test_list.insert(2);
    test_list.insert(4);
    test_list.insert(-2);
    test_list.insert(10);
    test_list.insert(0);
    test_list.insert(14);
    test_list.insert(1);
    test_list.insert(-7);
    cout << "\ndisplay populated list..." << endl;
    cout << "------------------------" << endl;
    test_list.display_list();

    cout << "\n\nsearching test..." << endl;
    cout << "------------------------" << endl;
    test_list.search_element(2);
    test_list.search_element(99);

    cout << "\n\nclearing test data..." << endl;
    cout << "------------------------" << endl;
    reset_list_size();
    return 0;
}


// user menu
void show_menu(void) {
    cout << "What would you like to do? \n"
    "1. Create New List \n"
    "2. Display List \n"
    "3. Add item to List\n"
    "4. Search for item\n"
    "5. Run Test Module \n"
    "6. Populate list \n"
    "7. Quit \n"  << endl;
}


int main() {
    // introduction
    cout << "Auto Sorting List Program" << endl;

    while (true) {
        // I like creating the base list here, instead of above. idk why. Just like it better.
        // Need creater this list to solve call display_list() error on run.
        list my_list;
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
                my_list.insert(my_list.ask_for_data());
                break;
            case 4:
                // Search for item - not even close to working
                my_list.search_element(my_list.ask_for_data());
                break;
            case 5:
                // Test Module - working
                test_module();
                break;
            case 6:
                // populate list
                my_list.insert(1);
                my_list.insert(0);
                my_list.insert(-42);
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
    system("pause");
    return 0;
}




// random code that was used at one point:
    // // test_autosort_list_constructor();
    // // my_list.create_list();
    // // my_list.to_string();
    // // my_list.display_list();
    // int data_asked = my_list.ask_for_data();


