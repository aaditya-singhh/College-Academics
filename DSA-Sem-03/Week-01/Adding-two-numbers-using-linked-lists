#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* newNode(int value) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = value;
node->next = NULL;
return node;
}
void pushFront(struct Node** head, int new_val) {
struct Node* new_node = newNode(new_val);
new_node->next = *head;
*head = new_node;
}
void printList(struct Node* head) {
if (head == NULL)
return;
printList(head->next);
printf("%d ", head->data);
}
struct Node* add(struct Node* l1, struct Node* l2) {
struct Node* ans = newNode(0);
struct Node* current = ans;
int carry = 0;
while (l1 || l2) {
int sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
carry = sum / 10;
sum %= 10;
current->next = newNode(sum);
current = current->next;
if (l1) l1 = l1->next;
if (l2) l2 = l2->next;
}
if (carry) {
current->next = newNode(carry);
}
ans = ans->next;

return ans;
}
void freeList(struct Node* head) {
while (head) {
struct Node* temp = head;
head = head->next;
free(temp);
}
}
int main() {
struct Node* l1 = NULL;
struct Node* l2 = NULL;
char digit;
printf("Enter the first number (digits separated by spaces): ");
while ((digit = getchar()) != '\n' && digit != EOF) {
if (digit >= '0' && digit <= '9') {
pushFront(&l1, digit - '0');
}
}
printf("Enter the second number (digits separated by spaces): ");
while ((digit = getchar()) != '\n' && digit != EOF) {
if (digit >= '0' && digit <= '9') {
pushFront(&l2, digit - '0');
}
}
struct Node* sum = add(l1, l2);
printf("Number 1: ");
printList(l1);
printf("\nNumber 2: ");
printList(l2);
printf("\nSum: ");
printList(sum);
freeList(l1);
freeList(l2);
freeList(sum);
return 0;
}
