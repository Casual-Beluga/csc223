#include <stdio.h>
#include "ctest.h"
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
    TEST("Can find a value in a list")
    {
        Node *mylist = NULL;

        mylist = make_node(1);
        mylist->next = mylist;

        Node *two = make_node(2);
        two->next = mylist;
        mylist->next = two;
        ASSERT_EQ(find_in_clist(mylist, 2), 2);

        END_TESTING();
    }
}
