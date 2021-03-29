#include "list.h"

#include <stdio.h>

using namespace std;

void list_print(List p)
{
    if (!p) {
        printf("������: ������ == null\n");
        return;
    }
    while (p)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

List list_prepend(List p, int key)
{
    return new ListItem{key, p};
}

List list_find(List p, int key)
{
    if (!p) {
        printf("������: ������ == null\n");
        return nullptr;
    }
    while (p && p->key != key)
        p = p->next;
    return p;
};

void list_insert_after(List p, int key)
{
    if (!p) {
        printf("������: ������ == null\n");
        return;
    }
    List q = new ListItem{key, p->next};
    p->next = q;
}

void list_delete_after(List head)
{
    if (!head) {
        printf("������: ������ == null\n");
        return;
    }
    List next = head->next;
    head->next = next->next;
    delete next;
}

List list_delete_key(List head, int key)
{
    if (!head) {
        printf("������: ������ == null\n");
        return nullptr;
    }

    // ������ 1: �������� ������� ��������
    if (head->key == key) {
        List new_head = head->next;
        delete head;
        return new_head;
    }

    // ������ 2: �������� �������� � �������� ��� � �����
    List i = head;
    while (i->next && i->next->key != key)
        i = i->next;

    if (!i->next) {
        printf("������: ���� �� ������\n");
        return head;
    }

    List after_target = i->next->next;
    delete i->next;
    i->next = after_target;
    return head;
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
