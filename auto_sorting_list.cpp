#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

void test_autosort_list_constructor();

// list.h
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
        void insert();
        void display_list();
        void display_element();
        std::string to_string();
};


// this method actually instantiates the list, the stuff before was just defining
void list::create_list() {
    // head is the beginning of the linked list
    head = nullptr;
}

// I had this in the insert function at first, but hated that. This
// makes it way simpler, because I can use it it more functions easily
// does not handle string (could use to_string, but that is stolen code)
int list::ask_for_data() {
    // this code does the asking for user input. Returns int.
    int user_data;
    cout << "what is the element?" << endl;
    cin >> user_data;
    return user_data;
    cout << "end of ask_for_data" << endl;
}

// call this in main with my_list.insert()
void list::insert() {
    int size_data = ask_for_data();
    // create new node pointing to nullptr
    node *new_node = new node;
    // the value of the new element is defined here
    new_node->data = size_data;
    new_node->next = nullptr;

    // // clear input buffer
    // // learned at https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/# 
    // // (but was in the google search page)
    // fflush(stdin);

    // if the node points to nullptr, list is empty
    // and if data at the head is larger than the user input
    // place on left side by shifting the pointer
    if (head == nullptr || size_data < head->data) {
        new_node->next = head;
        head = new_node;
        return;
    }

    // else list is populated, so smaller data goes 
    // to front of ptr, larger goes to back

    // had help from chat GPT for this part... 
    // this is the part that sorts.
    // create temporary node starting at the beginning of the list, The "head"
    node *temp = head;
    // traverse the list.
    /* while the temp node does not point at nullptr, and the data of the NEXT 
    node is less than the user input value, */
    while (temp->next != nullptr && temp->next->data < size_data) {
        // shift node and traverse one step in list until it matches size_data
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}



void list::display_list() {
    cout << "begin display_list" << endl;
    node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
        // cout << endl;
    }
    cout << endl;
    cout << "end of display_list" << endl;
}


void list::display_element() {
    cout << "this is supposed to print the single node" << endl;
    // to do: ask for element to search for
    // binary search for that element.
    // if you find the element... do what? display and say success?
    // else, element is not in list.
    // this is my search function
}



// COPY/PASTA LEARNING TO TEST!!!
// --------------------------------------
// idk what this method is for.
string list::to_string() {
    std::stringstream result_string_stream;
    if(head == nullptr){
        result_string_stream << "[empty list]";
    } else {
        node *current = head;
        result_string_stream << "[";
        while (current != nullptr) {
            result_string_stream << current->data;
            if(current->next != nullptr) {
                result_string_stream << ", ";
            }
            current = current->next;
        }
        result_string_stream << "]";
    }

    return result_string_stream.str();
}

void test_autosort_list_constructor() {
    list my_list;

    string expected_result = "[empty list]";

    string actual_result = my_list.to_string();

    cout << "expected_result: \"" << expected_result << "\"" << endl;
    cout << "actual_result: \"" << actual_result << "\"" << endl;
    cout << "expected_result.compare(actual_result): " << expected_result.compare(actual_result) << endl;

    assert(expected_result.compare(actual_result) == 0);
}
// END COPY/PASTA
// ----------------------------------



int main() {
    list my_list;
    my_list.create_list();
    my_list.display_list();
    // test_autosort_list_constructor();
    // my_list.create_list();
    // my_list.to_string();
    // my_list.display_list();
    // my_list.insert(0);
    // my_list.insert(1);
    // my_list.insert(2);
    // my_list.insert(3);
    // my_list.insert(4);
    // my_list.insert(5);
    // my_list.insert(6);

    // how handle the size of list? 
    // Right now it's dictated by these
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.insert();
    my_list.display_list();
    // I know that "pause" is not the best option to use here
    // to keep the window open, but I like the "press any key" thing.
    system("pause");
    return 0;
}
