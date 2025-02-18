#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_SIZE 100

typedef struct employee {
    int id;
    char name[20];
} EMPLOYEE;

void initialize_hash_table(EMPLOYEE a[]) {
    for(int i = 0; i < HASH_SIZE; i++) a[i].id = 0;
}

int H(int k) {
    return k % HASH_SIZE;
}

void insert_hash_table(int id, char name[], EMPLOYEE a[]) {
    int h_value = H(id);
    for(int i = 0; i < HASH_SIZE; i++) {
        int index = (h_value + i) % HASH_SIZE;
        if(a[index].id == 0) {
            a[index].id = id;
            strcpy(a[index].name, name);
            return;
        }
    }
    printf("Hash table full\n");
}

void display_hash_table(EMPLOYEE a[]) {
    printf("H_Value\tEmp_id\tEmp_name\n");
    for(int i = 0; i < HASH_SIZE; i++) {
        if(a[i].id != 0) printf("%d\t%d\t%s\n", i, a[i].id, a[i].name);
    }
}

int main() {
    EMPLOYEE a[HASH_SIZE];
    initialize_hash_table(a);

    int choice, id;
    char name[20];
    while(1) {
        printf("1:Insert 2:Display 3:Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter emp id: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                insert_hash_table(id, name, a);
                break;
            case 2:
                printf("Contents of hash table\n");
                display_hash_table(a);
                break;
            case 3:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
}
