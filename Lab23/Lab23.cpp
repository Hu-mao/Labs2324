#include <stdio.h>
#include <stdlib.h>

// 1. Опис структури даних (двоспрямований список, дійсний тип) з використанням пойменованого типу
typedef struct Node {
    double data;
    struct Node* prev;
    struct Node* next;
} Node;

// Допоміжна функція для виведення поточного стану списку
void printList(Node* head) {
    if (head == NULL) {
        printf("Список порожній.\n");
        return;
    }
    printf("Елементи списку: ");
    Node* current = head;
    while (current != NULL) {
        printf("%.2f <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функція додавання елемента в кінець двоспрямованого списку
void appendNode(Node** head, Node** tail, double value) {
    // Виділення пам'яті під новий вузол
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Примітка 1: аналіз переповнення (нестача оперативної пам'яті)
    if (newNode == NULL) {
        printf("Помилка: переповнення пам'яті! Неможливо додати елемент %.2f.\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // Якщо список порожній, новий елемент стає і головою, і хвостом
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        *tail = newNode;
    }
    else {
        // Додаємо в кінець та оновлюємо зв'язки
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Функція видалення елемента з початку двоспрямованого списку
int removeFirstNode(Node** head, Node** tail) {
    // Примітка 1: аналіз відсутності елементів у структурі
    if (*head == NULL) {
        return 0; // Ознака того, що список уже порожній
    }

    Node* temp = *head;
    double removedValue = temp->data;

    if (*head == *tail) {
        // У списку був лише один елемент
        *head = NULL;
        *tail = NULL;
    }
    else {
        // Зсуваємо голову на наступний елемент
        *head = (*head)->next;
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Видалено елемент: %.2f\n", removedValue);
    return 1; // Успішне видалення
}

int main() {
    // 2. Опис вказівних змінних описаного в п.1 типу (для зв'язаного представлення)
    Node* head = NULL;
    Node* tail = NULL;

    // 3. Опис змінної індексованого типу з 10 елементів дійсного типу та її ініціювання
    double sourceArray[10] = { 1.5, -2.3, 4.0, 7.85, 0.12, -9.4, 3.14, 6.6, 8.9, -1.1 };

    int N, M;

    // 4. Введення N (від 0 до 9) та створення N елементів структури з масиву
    do {
        printf("Введіть кількість елементів для додавання N (від 0 до 9): ");
        scanf("%d", &N);
        if (N < 0 || N > 9) {
            printf("Некоректне значення! N має бути в діапазоні від 0 до 9.\n");
        }
    } while (N < 0 || N > 9);

    printf("\n--- Ініціювання та створення %d елементів ---\n", N);
    for (int i = 0; i < N; i++) {
        appendNode(&head, &tail, sourceArray[i]);
    }
    printList(head);

    // 5. Введення M (від 0 до 15) та видалення M елементів (тільки для лінійних структур)
    do {
        printf("\nВведіть кількість елементів для видалення M (від 0 до 15): ");
        scanf("%d", &M);
        if (M < 0 || M > 15) {
            printf("Некоректне значення! M має бути в діапазоні від 0 до 15.\n");
        }
    } while (M < 0 || M > 15);

    printf("\n--- Видалення %d елементів ---\n", M);
    for (int i = 0; i < M; i++) {
        if (!removeFirstNode(&head, &tail)) {
            printf("Попередження (крок %d з %d): структура даних порожня, видаляти більше нічого!\n", i + 1, M);
            break; // Припиняємо цикл, оскільки елементи закінчилися
        }
    }

    printf("\n--- Кінцевий стан структури ---\n");
    printList(head);

    // Очищення залишків пам'яті перед завершенням програми
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}