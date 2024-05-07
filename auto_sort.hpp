#ifndef AUTO_SORT_HPP
#define AUTO_SORT_HPP

#pragma once

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


void reset_list_size();
void show_menu();
int test_module();



#endif