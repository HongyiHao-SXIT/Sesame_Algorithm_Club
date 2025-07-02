#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct polynomial {
    int coef;
    int exp;
    struct polynomial *next;
} *Link, Node;

void inputPoly(Link head);
void print(Link head);
bool insert(Link head, int coef, int exp);
void combin2List(Link heada, Link headb, Link headab);

int main() {
    Link headA = (Link)malloc(sizeof(Node));
    Link headB = (Link)malloc(sizeof(Node));
    Link headAB = (Link)malloc(sizeof(Node));

    if (!headA || !headB || !headAB) {
        printf("Memory allocation failed!\n");
        free(headA); free(headB); free(headAB);
        return 1;
    }

    headA->next = NULL;
    headB->next = NULL;
    headAB->next = NULL;

    printf("Enter the coefficients and exponents of the first polynomial, ending with (0 0):\n");
    inputPoly(headA);
    printf("First ");
    print(headA);

    printf("Enter the coefficients and exponents of the second polynomial, ending with (0 0):\n");
    inputPoly(headB);
    printf("Second ");
    print(headB);

    combin2List(headA, headB, headAB);
    printf("Merged ");
    print(headAB);

    Link temp;
    while (headA != NULL) {
        temp = headA;
        headA = headA->next;
        free(temp);
    }
    while (headB != NULL) {
        temp = headB;
        headB = headB->next;
        free(temp);
    }
    while (headAB != NULL) {
        temp = headAB;
        headAB = headAB->next;
        free(temp);
    }

    return 0;
}

void inputPoly(Link head) {
    int coef, exp;
    while (true) {
        printf("Enter coefficient and exponent (e.g., 2 3 means 2x^3): ");
        scanf("%d %d", &coef, &exp);
        if (coef == 0 && exp == 0)
            break;
        if (!insert(head, coef, exp)) {
            printf("Insertion failed, out of memory!\n");
            break;
        }
    }
}

bool insert(Link head, int coef, int exp) {
    if (coef == 0) return true;

    Link prev = head;
    Link curr = head->next;

    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->exp == exp) {
        curr->coef += coef;
        if (curr->coef == 0) {
            prev->next = curr->next;
            free(curr);
        }
        return true;
    }

    Link newNode = (Link)malloc(sizeof(Node));
    if (!newNode) return false;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = curr;
    prev->next = newNode;
    return true;
}

void print(Link head) {
    Link p = head->next;

    printf("Polynomial:\n");

    if (!p) {
        printf("0\n");
        return;
    }

    bool isFirst = true;
    while (p) {
        if (!isFirst && p->coef > 0) {
            printf("+");
        }

        if (p->exp == 0) {
            printf("%d", p->coef);
        } else {
            if (p->coef == -1)
                printf("-");
            else if (p->coef != 1)
                printf("%d", p->coef);

            printf("x");
            if (p->exp != 1)
                printf("^%d", p->exp);
        }

        isFirst = false;
        p = p->next;
    }
    printf("\n");
}

void combin2List(Link heada, Link headb, Link headab) {
    Link pa = heada->next;
    Link pb = headb->next;

    while (pa && pb) {
        if (pa->exp > pb->exp) {
            insert(headab, pa->coef, pa->exp);
            pa = pa->next;
        } else if (pa->exp < pb->exp) {
            insert(headab, pb->coef, pb->exp);
            pb = pb->next;
        } else {
            int sum = pa->coef + pb->coef;
            if (sum != 0)
                insert(headab, sum, pa->exp);
            pa = pa->next;
            pb = pb->next;
        }
    }

    while (pa) {
        insert(headab, pa->coef, pa->exp);
        pa = pa->next;
    }
    while (pb) {
        insert(headab, pb->coef, pb->exp);
        pb = pb->next;
    }
}