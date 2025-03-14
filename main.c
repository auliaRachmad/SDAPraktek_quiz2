#include "linked.h"

int main(){
    address List = Nil;

    insertFirst(List, createNode(7));
    printList(List);
    insertLast(List, createNode(11));
    printList(List);
    insertValueAfter(List, 7, createNode(9));
    printList(List);
    insertFirst(List, createNode(5));
    printList(List);
    insertLast(List, createNode(13));
    printList(List);
    deleteLast(List);
    printList(List);
    deleteValue(List, 7);
    printList(List);
    deleteFirst(List);
    printList(List);
    deleteOdd(List);
    printList(List);
}