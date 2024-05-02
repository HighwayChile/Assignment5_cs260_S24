#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

// using namespace std;
using std::cout;
using std::endl;
using std::string;


void test_autosort_list_constructor();

// list.h
struct node {
    int size_data;
    node *next;
};

class list {
    private:
        node *head;

    public:
        list();
        void insert(int data);
        std::string to_string();
};


// this actually instantiates the list, the stuff before was just defining
list::list() {
    head = nullptr;
}


void list::insert(int size_data) {\
    // create new node pointing to nullptr
    node *new_node = new node;
    new_node->size_data = size_data;
    new_node->next = nullptr;

    // if the node points to nullptr, list is empty
    if(head == nullptr) {
        head = new_node;
    } else {
        // else list is populated, so size_data is compared
        // smaller size_data goes to front of ptr, larger goes to back
        cout << "please finish this code after lunch!" << endl;
    }
}











// COPY/PASTA LEARNING TO TEST!!!
string list::to_string() {
    std::stringstream result_string_stream;
    if(head == nullptr){
        result_string_stream << "[empty list]";
    } else {
        node *current = head;
        result_string_stream << "[";
        while (current != nullptr) {
            result_string_stream << current->size_data;
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

int main() {
    test_autosort_list_constructor();
    system("pause");
    return 0;
    // system("pause");
}

// END COPY/PASTA