#include <cstdlib>
#include <locale.h>

#include "list.h"
#include "utils.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    // List p = nullptr;

    // for (int i = 1; i <= 5; i++)
    //     p = list_prepend(p, i);
    // p = list_prepend(p, 10);
    // list_print(p);

    // List q = list_find(p, 3);
    // list_insert_after(q, 10);
    // list_print(p);

    // List null = list_find(p, 123);
    // list_insert_after(null, 10);
    // list_print(null);

    // q = list_find(p, 2);
    // list_delete_after(q);
    // list_print(p);

    // p = list_delete_key(p, 5);
    // list_print(p);

    // p = list_delete_key(p, 10);
    // list_print(p);

    // p = list_delete_key(p, 2);
    // list_print(p);

    // p = list_delete_key(p, 123);
    // list_print(p);

    // list_free(p);

    // -----------------------------------

    List list = nullptr;
    
    int n_keys = input("Количество ключей", 1);
    for (int i = 1; i <= n_keys; i++) {
        int key;
        do {
            printf("Ключ %d: ", i);
            scanf("%d", &key);
        } while (key < 1);
        list_prepend(list, key);
    }
    
    list_print(list);

    int key;
    printf("Какой ключ удалить? ");
    scanf("%d", &key);

    list_delete_key(list, key);
    list_print(list);

    list_free(list);

    system("pause");

    return 0;
}
