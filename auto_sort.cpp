#include <iostream>
#include <limits>
#include "auto_sort.hpp"

using namespace std;

// list size counter (had intended this for binary search)
int size_of_list = 0;

// this method actually instantiates the list, the stuff before was just defining
void list::create_list() {
    head = nullptr;
}

/* I had this functionality placed within the insert function at first, but hated that. This 
makes it way simpler, because I can use it in more functions easily 
does not handle string  */
int list::ask_for_data() {
    int user_data;
    cin >> user_data;
    return user_data;
}

void list::insert(int size_data) {
    // create new node pointing to nullptr. Need this for assigning new spot in list
    // different from temp, because this one is actually inserted. 
    // Learned from Joseph Jess and other online sources.
    node *new_node = new node;
    new_node->data = size_data;
    new_node->next = nullptr;

    // if the head is nullptr, list is empty
    // or if data at the head is larger than the user input
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

    new_node->next = temp->next;
    temp->next = new_node;

    size_of_list++;
}



void list::display_list() {
    cout << "Size of list : " << size_of_list << " elements" << endl;
    /* I like to think of this temp node as a shuttle on a loom 
    or maybe like the head of a typwriter, but this one allows 
    insertion*/
    node *temp = head;
    cout << "List elements: ";
    // if no nodes there are no elements, just a nullptr
    if (temp == nullptr) {
        cout << "[no elements in list]";
    }
    // cycle through and print the list until hits the terminal node
    // adds a whitespace and then goes to next node
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

int list::search_element(int search_value) {
    // create temporary node to act as shuttle
    node *temp2 = head;
    // init index at 0
    int index = 0;

    // this begins the traversal and ends after it hits terminal node
    while (temp2 != nullptr){
        // this prints success message when element is found
        if (temp2->data == search_value) {
            cout << "Value " << search_value << " found at index " << index << endl;
            return index;
        }
        // moves the pointer to next node
        temp2 = temp2->next;
        index++;
    }

    // if element is not found, print consolation message
    cout << "Sorry, " << search_value << " not found" << endl;
    return 0;
}

// the littl'st function!
void reset_list_size() {
    size_of_list = 0;
}

// user menu
void show_menu() {
    cout << "What would you like to do? \n"
    "1. Create New List \n"
    "2. Display List \n"
    "3. Add item to List\n"
    "4. Search for item\n"
    "5. Run Test Module \n"
    "6. Populate list \n"
    "7. Quit \n"  << endl;
}

int test_module() {
    // reset list counter and do a bunch of stuff
    reset_list_size();
    cout << "\nWELCOME TO THE TEST MODULE!" << endl;
    cout << "------------------------" << endl;
    cout << "This module creates a list, then modifies that list." << endl;
    cout << "Creates separate linked list: \"test_list\"\n" << endl;
    list test_list;
    test_list.create_list();
    cout << "\ndisplay empty test_list" << endl;
    cout << "------------------------" << endl;
    test_list.display_list();

    cout << "\n\nsearching empty list..." << endl;
    cout << "------------------------" << endl;
    cout << "Search for 2 - ";
    test_list.search_element(2);
    
    cout << "\n\nadding values..." << endl;
    cout << "------------------------" << endl;
    cout << "adding 10 items (in this order): 2, 4, -2, 10, 0, 1, -7, 6, 3, 5" << endl;

    test_list.insert(2);
    test_list.insert(4);
    test_list.insert(-2);
    test_list.insert(10);

    test_list.insert(0);
    test_list.insert(1);
    test_list.insert(-7);
    test_list.insert(6);

    test_list.insert(3);
    test_list.insert(5);

    cout << "\ndisplay populated list..." << endl;
    cout << "------------------------" << endl;
    test_list.display_list();

    cout << "\n\nsearching test..." << endl;
    cout << "------------------------" << endl;
    cout << "Search for 2 - ";
    test_list.search_element(2);
    cout << "Search for -2 - ";
    test_list.search_element(-2);
    cout << "Search for 0 - ";
    test_list.search_element(0);
    cout << "Search for 99 - ";
    test_list.search_element(99);
    cout << "Search for 42 - ";
    test_list.search_element(42);

    // as before, this doesn't truly delete the linked list
    cout << "\n\nclearing test data..." << endl;
    cout << "------------------------" << endl;
    test_list.create_list();
    reset_list_size();

    cout << "\n\nsearching empty list..." << endl;
    cout << "------------------------" << endl;
    cout << "Search for 2 - ";
    test_list.search_element(2);

    cout << "\ndisplay empty list" << endl;
    cout << "------------------------" << endl;
    test_list.display_list();



    return 0;
}
