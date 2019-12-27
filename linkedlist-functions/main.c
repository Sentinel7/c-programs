#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;


void print_list(LinkedList* L) {
    Node* current_node = L->head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}


void add_to_front(LinkedList* L, int new_element){
    Node* new_node = malloc(sizeof(Node));

    new_node->value = new_element;
    new_node->next = L->head;

    L->head = new_node;
}


void add_to_end(LinkedList* L, int new_element){
    Node* new_node = malloc(sizeof(Node));

    new_node->value = new_element;
    new_node->next = NULL;

    if (L->head == NULL) {
        L->head = new_node;
    } else {
        Node* current_node = L->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

}


int sum_elements(LinkedList* L){
    Node* current_node = L->head;
    int sum = 0;
    while (current_node != NULL) {
        sum += current_node->value;
        current_node = current_node->next;
    }
    return sum;
}


int count_elements(LinkedList* L){
    Node* current_node = L->head;
    int count = 0;
    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }
    return count;
}


int delete_first(LinkedList* L){
    Node* first_node = L->head;
    int value;
    if (first_node == NULL) {
        return -999;
    } else {
        L->head = first_node->next;
        value = first_node->value;
        free(first_node);
    }
    return value;
}


int delete_last(LinkedList* L){
    Node* last_node = L->head;
    int value;

    if (last_node == NULL)
        return -999;
    else if (last_node->next == NULL) {
        L->head = NULL;
        value = last_node->value;
        free(last_node);
        return value;
    }

    while (last_node->next->next != NULL) {
        last_node = last_node->next;
    }
    value = last_node->next->value;
    free(last_node->next);
    last_node->next = NULL;
    return value;
}


void free_linkedlist(LinkedList* L) {
    Node* tmp = L->head;
    while (L->head != NULL) {
        tmp = L->head;
        L->head = L->head->next;
        free(tmp);
    }
}


int main() {

    //Set up two empty lists L1 and L2
    LinkedList L1;
    L1.head = NULL;

    LinkedList L2;
    L2.head = NULL;

    //Add some elements to L1
    add_to_front(&L1, 6);
    add_to_front(&L1, 10);
    add_to_front(&L1, 17);
    //At this point, L should contain 17, 10, 6
    print_list(&L1);


    //Add more elements to L1
    add_to_end(&L1, 100);
    add_to_end(&L1, 200);
    //At this point, L should contain 17, 10, 6, 100, 200
    print_list(&L1);

    //Add some elements to L2
    for(int i = 0; i < 10; i++){
        add_to_end(&L2, i*i);
    }
    print_list(&L2);


    printf("L1 contains %d elements\n", count_elements(&L1));
    printf("L2 contains %d elements\n", count_elements(&L2));

    printf("Sum of L1: %d\n", sum_elements(&L1));
    printf("Sum of L2: %d\n", sum_elements(&L2));


    //Now try deleting some things
    printf("Deleting from front of L1: %d\n", delete_first(&L1));
    printf("Deleting from front of L1: %d\n", delete_first(&L1));
    printf("Deleting from front of L1: %d\n", delete_first(&L1));
    printf("Contents of L1: " );
    print_list(&L1);


    // Challenge exercise: Implement delete_last
    printf("Deleting from end of L2: %d\n", delete_last(&L2));
    printf("Deleting from end of L2: %d\n", delete_last(&L2));
    printf("Deleting from end of L2: %d\n", delete_last(&L2));
    printf("Contents of L2: ");
    print_list(&L2);



    free_linkedlist(&L1);
    free_linkedlist(&L2);

    return 0;
}