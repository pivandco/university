#pragma once

typedef struct ListItem *List;

struct ListItem {
    int key;
    List next;
};

void list_print(List);
void list_prepend(List &, int);
void list_insert_after(List, int);
List list_find(List, int);
void list_delete_after(List);
void list_delete_key(List &, int);
void list_free(List);
