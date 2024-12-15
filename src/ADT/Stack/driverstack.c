#include <stdio.h>
#include "stack.h"

int main() {
    Stack myStack;
    CreateEmptyS(&myStack);

    Purchase item1 = {{{"AK47", 2, 200}}, 1, 100};
    Purchase item2 = {{{"Sticky Web Gun", 5, 2500}}, 1, 500}; 
    Purchase item3 = {{{"Inator Neutralizer", 3, 3000}}, 1, 1000}; 

    Push(&myStack, item1);
    Push(&myStack, item2);
    Push(&myStack, item3);

    printf("Barang pada stack:\n");
    for (int i = 0; i <= myStack.top; i++) {
        for (int j = 0; j < myStack.purchases[i].count; j++) { 
            printf("Nama Barang: %s, Banyak: %d, Total: %d\n", 
                   myStack.purchases[i].items[j].name, 
                   myStack.purchases[i].items[j].quantity, 
                   myStack.purchases[i].items[j].total);
        }
    }

    Purchase poppedItem;
    Pop(&myStack, &poppedItem);
    
    printf("\nBarang yang di Pop:\n");
    for (int j = 0; j < poppedItem.count; j++) { 
        printf("Nama Barang: %s, Banyaknya: %d, Total: %d\n", 
               poppedItem.items[j].name, 
               poppedItem.items[j].quantity, 
               poppedItem.items[j].total);
    }

    return 0;
}