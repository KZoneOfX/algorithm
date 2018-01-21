#include <iostream>

typedef struct {
    int *elem;
    int length;
}SqlList;

void inverseLinearList(SqlList *list) {

    for (int i = 0; i < list->length / 2; ++i) {
        list->elem[i] = list->elem[i] ^ list->elem[list->length -i -1];
        list->elem[list->length -i -1] = list->elem[i] ^ list->elem[list->length-i-1];
        list->elem[i] = list->elem[i] ^ list->elem[list->length -i -1];
    }
}
int main() {
    SqlList *list;
    list = (SqlList*)malloc(sizeof(SqlList));

    printf("please input the number of elements:");
    scanf("%d", &list->length);

    list->elem = (int*)(malloc(sizeof(int) * list->length));

    for (int i = 0; i < list->length; ++i) {
        int random = rand()%100;
        list->elem[i] = random;
    }
    printf("before:");
    for (int i = 0; i < list->length; ++i) {
        printf("%d ",list->elem[i]);
    }
    printf("\nafter:");
    inverseLinearList(list);
    for (int i = 0; i < list->length; ++i) {
        printf("%d ",list->elem[i]);
    }
    printf("\n");



    free(list->elem);
    free(list);
    return 0;
}