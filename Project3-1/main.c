#include <stdio.h> 
#include <stdlib.h> 

// 리스트의 노드 구조를 구조체로 정의
float coef;
typedef struct Listnode {
    float coef;
    int expo;
    struct Listnode* link;
}Listnode;

typedef struct Listhead {
    Listnode* head;
}Listhead;

//공백 다항식 리스트를 생성하는 연산
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

    if (L->head == NULL) {   //다항식 리스트가 공백인 경우
        L->head = newnode;
        return;
    }

    else {      //다항식 리스트가 공백이 아닌 경우
        p = L->head;
        while (p->link != NULL) {
            p = p->link;   //리스트의 마지막 노드를 찾음
        }
        p->link = newnode;   //새 노드 연결
    }
}

// 두 다항식의 곱셈을 구하는 연산
void mulpoly(Listhead* A, Listhead* B, Listhead* C) {
    Listnode* pA = A->head;   //pA에 A의 첫 번째 노드의 주소 저장
    Listnode* pB = B->head;   //pB에 B의 첫 번째 노드의 주소 저장
    float sum;            //두 다항식의 계수의 곱을 저장
    int exposum;         //두 다항식의 합을 저장

    // 
    while (pA) {
        while (pB) {
            sum = pA->coef * pB->coef; //sum값에 두 다항식의 계수의 곱을 대입
            exposum = pA->expo + pB->expo; //exposum값에 두 다항식의 지수의 합을 대입
            appendTerm(C, sum, exposum); //appendTerm 함수에 C, sum, exposum 함
            pB = pB->link;
        }
        pA = pA->link;
        pB = B->head;
    }
}

//다항식 리스트를 출력하는 연산
void printpoly(Listhead* L) {
    Listnode* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d", p->coef, p->expo);
        if (p->link != NULL) printf(" +");
    }
}

//주함수
void main(void) {
    Listhead* A, * B, * C, * D,* E,* F;

    // 공백 다항식 리스트 A,B,C 생성 
    A = createlinkedlist();
    B = createlinkedlist();
    C = createlinkedlist();
    D = createlinkedlist();
    E = createlinkedlist();
    F = createlinkedlist();

    appendTerm(A, 4, 3);   //다항식 리스트 A에     노드 추가
    appendTerm(A, 3, 2);   //다항식 리스트 A에     노드 추가
    appendTerm(A, 2, 1);   //다항식 리스트 A에     노드 추가
    appendTerm(A, 1, 0);   //다항식 리스트 A에     노드 추가
    printf("\n A(x) =");
    printpoly(A);          //다항식 리스트 A 출력

    appendTerm(B, 3, 2);   //다항식 리스트 B에     노드 추가
    appendTerm(B, 2, 1);   //다항식 리스트 B에     노드 추가
    appendTerm(B, 8, 0);   //다항식 리스트 B에     노드 추가
    printf("\n B(x) =");
    printpoly(B);          //다항식 리스트 B 출력
    mulpoly(A, B, C);      //다항식 곱셈 연산 수행
    printf("\n 1번 답 : C(x) =");
    printpoly(C);         // 다항식 리스트 C 출력
    printf("\n-----------------------------------------------------------------------------------------------------------------------");
    
    
    appendTerm(D, 7, 6);   //다항식 리스트 D에     노드 추가
    appendTerm(D, 5, 3);   //다항식 리스트 D에     노드 추가
    appendTerm(D, 9, 2);   //다항식 리스트 D에     노드 추가
    appendTerm(D, 1, 0);   //다항식 리스트 D에     노드 추가
    printf("\n D(x) =");
    printpoly(D);         //다항식 리스트 D 출력

    appendTerm(E, 5, 3);   //다항식 리스트 E에     노드 추가
    appendTerm(E, 2, 2);   //다항식 리스트 E에     노드 추가
    appendTerm(E, 1, 1);   //다항식 리스트 E에     노드 추가
    appendTerm(E, 10, 0);   //다항식 리스트 E에     노드 추가
    printf("\n E(x) =");
    printpoly(E);         //다항식 리스트 E 출력

    mulpoly(D, E, F);      //다항식 곱셈 연산 수행
    printf("\n 2번 답 : F(x) = ");
    printpoly(F);         // 다항식 리스트 F 출력

    getchar();
}