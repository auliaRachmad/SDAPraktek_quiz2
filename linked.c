#include "linked.h"

boolean isEmpty(address P){
    return (P == Nil);
}

address createNode (infotype info){
    address P = (address) malloc(sizeof(ElmtList));
    if (P == Nil) return Nil;
    P->info = info;
    P->next = Nil;
    return P;
}

void printList (address P){
    if(!isEmpty(P)){
        address temp;
        temp = P;
        do {
            printf("%d ", temp->info);
            temp = temp->next;

        } while (!isEmpty(temp->next));
    }
}

void insertFirst (address *P, address PNew){
    address temp;

    if(isEmpty(P)){
        *P = PNew;
    }else{
        temp = *P;
        PNew->next = temp;
        
        *P = PNew;
    }
}

void insertLast (address *P, address PNew){
    address temp;

    if(isEmpty(P)){
        *P = PNew;
    }else{
        temp = P;
        while(!isEmpty(temp->next)){
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

void insertValueAfter(address * P, infotype value, address PNew){
    address temp;

    if(isEmpty(P)){
        *P = PNew;
    }else{
        temp = P;
        while(temp->info != value && !isEmpty(temp->next)){
            temp = temp->next;
        }
        if(temp->info == value){
            PNew->next = temp->next;
            temp->next = PNew;
        }
    }
}

void deleteFirst (address * P){
    address temp;

    if(!isEmpty(P)){
        temp = P;
        (*P) = (*P)->next;

        free(temp);

        temp = Nil;
    }
}

void deleteLast (address * P){
    address temp,temp2;

    if(!isEmpty(P)){
        temp = P;
        while(!isEmpty(temp->next->next)){
            temp = temp->next;
        }
        temp2 = temp->next;
        free(temp2);
        temp2 = Nil;
        temp->next = Nil;
    }
}

void deleteValue(address * P, infotype value){
    address temp, temp2;

    if(!isEmpty(P)){
        temp = P;

        if(temp->info == value){
            deleteFirst(P);
        }else{
            while (temp->next->info != value && !isEmpty(temp->next->next)){
                temp = temp->next;
            }
            if(temp->next->info == value){
                temp2 = temp->next;
                temp->next = temp2->next;
                free(temp2);
                temp2 = Nil;
            }
        }
        
    }
}

void deleteOdd(address * P){
    address temp;

    if(!isEmpty(P)){
        temp = P;

        while(!isEmpty(temp->next)){
            if(temp->info % 2 == 1){
                deleteValue(P, temp->info);
            }
            temp = temp->next;
        }
    }
}