#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink, *rlink;
};
typedef struct node *NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x==NULL) {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return x;
}

NODE ins(int item, NODE first) {
    NODE temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = first;
    if (first!=NULL) 
		first->llink = temp;
    return temp;
}

NODE insl(int item, int itemleft, NODE first) {
    if (!first) {
        printf("\nEmpty list\n");
        return first;
    }
    NODE temp = getnode(), cur = first;
    temp->info = item;
    while (cur && cur->info != itemleft)
        cur = cur->rlink;
    if (!cur) {
        printf("\nNo element found\n");
        free(temp);
    } else if (cur == first) {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    } else {
        temp->llink = cur->llink;
        temp->rlink = cur;
        cur->llink->rlink = temp;
        cur->llink = temp;
    }
    return first;
}

NODE del(int item, NODE first) {
    if (!first) {
        printf("\nLinked list is empty\n");
        return NULL;
    }
    NODE cur = first;
    while (cur && cur->info != item)
        cur = cur->rlink;
    if (!cur) {
        printf("Element not found\n");
        return first;
    }
    if (cur == first) first = first->rlink;
    if (cur->llink) cur->llink->rlink = cur->rlink;
    if (cur->rlink) cur->rlink->llink = cur->llink;
    free(cur);
    printf("Item deleted = %d\n", item);
    return first;
}

void disp(NODE first) {
    if (!first) {
        printf("List is empty\n");
        return;
    }
    for (NODE cur = first; cur; cur = cur->rlink)
        printf("%d ", cur->info);
    printf("\n");
}

int main() {
    int ch, item, itemleft;
    NODE first = NULL;
    for (;;) {
        printf("\nChoices:\n1-Insert\n2-Insert left\n3-Delete node\n4-Display\n5-Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                first = ins(item, first);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                printf("Enter the element to the left of which item should be inserted: ");
                scanf("%d", &itemleft);
                first = insl(item, itemleft, first);
                break;
            case 3:
                printf("Enter the item to be deleted: ");
                scanf("%d", &item);
                first = del(item, first);
                break;
            case 4:
                disp(first);
                break;
            default:
                exit(0);
        }
    }
}
