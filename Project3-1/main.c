#include <stdio.h> 
#include <stdlib.h> 

// ����Ʈ�� ��� ������ ����ü�� ����
float coef;
typedef struct Listnode {
    float coef;
    int expo;
    struct Listnode* link;
}Listnode;

typedef struct Listhead {
    Listnode* head;
}Listhead;

//���� ���׽� ����Ʈ�� �����ϴ� ����
Listhead* createlinkedlist(void) {
    Listhead* L;
    L = (Listhead*)malloc(sizeof(Listhead));
    L->head = NULL;
    return L;
}

void appendTerm(Listhead* L, float coef, int expo) {
    Listnode* newnode;
    Listnode* p;
    newnode = (Listnode*)malloc(sizeof(Listnode));
    newnode->coef = coef;
    newnode->expo = expo;
    newnode->link = NULL;

    if (L->head == NULL) {   //���׽� ����Ʈ�� ������ ���
        L->head = newnode;
        return;
    }

    else {      //���׽� ����Ʈ�� ������ �ƴ� ���
        p = L->head;
        while (p->link != NULL) {
            p = p->link;   //����Ʈ�� ������ ��带 ã��
        }
        p->link = newnode;   //�� ��� ����
    }
}

// �� ���׽��� ������ ���ϴ� ����
void mulpoly(Listhead* A, Listhead* B, Listhead* C) {
    Listnode* pA = A->head;   //pA�� A�� ù ��° ����� �ּ� ����
    Listnode* pB = B->head;   //pB�� B�� ù ��° ����� �ּ� ����
    float sum;            //�� ���׽��� ����� ���� ����
    int exposum;         //�� ���׽��� ���� ����

    // 
    while (pA) {
        while (pB) {
            sum = pA->coef * pB->coef; //sum���� �� ���׽��� ����� ���� ����
            exposum = pA->expo + pB->expo; //exposum���� �� ���׽��� ������ ���� ����
            appendTerm(C, sum, exposum); //appendTerm �Լ��� C, sum, exposum ��
            pB = pB->link;
        }
        pA = pA->link;
        pB = B->head;
    }
}

//���׽� ����Ʈ�� ����ϴ� ����
void printpoly(Listhead* L) {
    Listnode* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" +");
    }
}

//���Լ�
void main(void) {
    Listhead* A, * B, * C, * D,* E,* F;

    // ���� ���׽� ����Ʈ A,B,C ���� 
    A = createlinkedlist();
    B = createlinkedlist();
    C = createlinkedlist();
    D = createlinkedlist();
    E = createlinkedlist();
    F = createlinkedlist();

    appendTerm(A, 4, 3);   //���׽� ����Ʈ A��     ��� �߰�
    appendTerm(A, 3, 2);   //���׽� ����Ʈ A��     ��� �߰�
    appendTerm(A, 2, 1);   //���׽� ����Ʈ A��     ��� �߰�
    appendTerm(A, 1, 0);   //���׽� ����Ʈ A��     ��� �߰�
    printf("\n A(x) =");
    printpoly(A);          //���׽� ����Ʈ A ���

    appendTerm(B, 3, 2);   //���׽� ����Ʈ B��     ��� �߰�
    appendTerm(B, 2, 1);   //���׽� ����Ʈ B��     ��� �߰�
    appendTerm(B, 8, 0);   //���׽� ����Ʈ B��     ��� �߰�
    printf("\n B(x) =");
    printpoly(B);          //���׽� ����Ʈ B ���
    mulpoly(A, B, C);      //���׽� ���� ���� ����
    printf("\n 1�� �� : C(x) =");
    printpoly(C);         // ���׽� ����Ʈ C ���
    printf("\n-----------------------------------------------------------------------------------------------------------------------");
    
    
    appendTerm(D, 7, 6);   //���׽� ����Ʈ D��     ��� �߰�
    appendTerm(D, 5, 3);   //���׽� ����Ʈ D��     ��� �߰�
    appendTerm(D, 9, 2);   //���׽� ����Ʈ D��     ��� �߰�
    appendTerm(D, 1, 0);   //���׽� ����Ʈ D��     ��� �߰�
    printf("\n D(x) =");
    printpoly(D);         //���׽� ����Ʈ D ���

    appendTerm(E, 5, 3);   //���׽� ����Ʈ E��     ��� �߰�
    appendTerm(E, 2, 2);   //���׽� ����Ʈ E��     ��� �߰�
    appendTerm(E, 1, 1);   //���׽� ����Ʈ E��     ��� �߰�
    appendTerm(E, 10, 0);   //���׽� ����Ʈ E��     ��� �߰�
    printf("\n E(x) =");
    printpoly(E);         //���׽� ����Ʈ E ���

    mulpoly(D, E, F);      //���׽� ���� ���� ����
    printf("\n 2�� �� : F(x) = ");
    printpoly(F);         // ���׽� ����Ʈ F ���

    getchar();
}