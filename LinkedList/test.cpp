#include <cstdlib>

#include "list.h"

int main()
{
    List p = nullptr;

    for (int i = 1; i <= 5; i++)
        p = list_prepend(p, i);
    p = list_prepend(p, 10);
    list_print(p);

    List q = list_find(p, 3);
    list_insert_after(q, 10);
    list_print(p);

    q = list_find(p, 2);
    list_delete_after(q);
    list_print(p);

    p = list_delete_key(p, 5);
    list_print(p);

    p = list_delete_key(p, 10);
    list_print(p);

    p = list_delete_key(p, 2);
    list_print(p);

    list_free(p);

    system("pause");

    return 0;
}
