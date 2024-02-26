#include <stdio.h>
#include <ctest.h>
#include "clist.h"

int main()
{
    BEGIN_TESTING("clist.h");

    TEST("Can create node")
    {
        Node *n = make_node(3);
        ASSERT_EQ(n->val, 3);
        ASSERT_EQ(n->next, NULL);
    }

    TEST("Can print list")
    {
        Node *mylist = NULL;
        RETURNS_STR(print_clist, "", (mylist));

        mylist = make_node(1);
        mylist->next = mylist;
        RETURNS_STR(print_clist, "1", (mylist));

        Node *two = make_node(2);
        two->next = mylist;
        mylist->next = two;

        Node *n = make_node(1024);
        n->next = mylist;
        two->next = n;

        RETURNS_STR(print_clist, "1 -> 2 -> 1024", (mylist));
    }

    TEST("Can insert node in order in descending list")
    {
        // Confirm works with empty list
        Node *mylist = NULL;
        Node *n = make_node(4);
        insert_in_order(&mylist, &n);
        RETURNS_STR(print_list, "4", (mylist));
        Node *n2 = make_node(3);
        insert_in_order(&mylist, &n2);
        RETURNS_STR(print_clist, "4 -> 3", (mylist));
        for (int i = 6; i < 10; i += 2)
        {
            Node *n = make_node(i);
            n->next = mylist;
            mylist = n;
        }
        n2->next = mylist;
        // Confirm list is starts as desired
        RETURNS_STR(print_clist, "3 -> 4 -> 6 -> 8", (mylist));
        n = make_node(5);
        insert_in_order(&mylist, &n);
        // Confirm new node inserted in order
        RETURNS_STR(print_list, "3 -> 4 -> 5 -> 6 -> 8", (mylist));
        // Confirm insert smallest at end works
        n = make_node(2);
        insert_in_order(&mylist, &n);
        RETURNS_STR(print_clist, "2 -> 3 -> 4 -> 5 -> 6 -> 8", (mylist));
        // Confirm insert largest at beginning works
        n = make_node(10);
        insert_in_order(&mylist, &n);
        RETURNS_STR(print_clist, "2 -> 3 -> 4 -> 5 -> 6 -> 8 -> 10", (mylist));
    }

    END_TESTING();
}
