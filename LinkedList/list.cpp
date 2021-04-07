#include "list.h"

#include <stdio.h>

using namespace std;

void list_print(List p)
{
    if (!p) {
        // printf("Пустой список\n");
        return;
    }
    while (p)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

void list_prepend(List &p, int key)
{
    p = new ListItem{key, p};
}

List list_find(List p, int key)
{
    if (!p) {
        return nullptr;
    }
    while (p && p->key != key)
        p = p->next;
    return p;
};

void list_insert_after(List p, int key)
{
    if (!p) {
        return;
    }
    List q = new ListItem{key, p->next};
    p->next = q;
}

void list_delete_after(List head)
{
    if (!head)
        return;

    List next = head->next;
    head->next = next->next;
    delete next;
}

void list_delete_key(List &head, int key)
{
    if (!head)
        return;

    List i = head;
    while (i->next) {
        if (i->next->key == key) {
            List to_delete = i->next;
            i->next = to_delete->next;
            delete to_delete;
        } else {
            i = i->next;
        }
    }

    if (head->key == key) {
        List old_head = head;
        head = head->next;
        delete old_head;
    }
}

void list_free(List p)
{
    List q;
    while (p)
    {
        q = p;
        p = p->next;
        delete q;
    }
}
