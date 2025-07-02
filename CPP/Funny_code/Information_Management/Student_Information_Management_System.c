#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLASSES 6

typedef struct {
    int id;
    char name[20];
    int classNum;
    char address[50];
    char phone[20];
    char major[50];
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} Node;

Node* createList();
Node* createNode(Student data);
void showMenu();
void handleInput();
void handleSearch();
void handleDelete();
void handleUpdate();
void handleSort();
void handleStatistics();
void addStudent(Node* head, Student data);
void displayStudents(Node* head);
void searchById(Node* head, int id);
void searchByName(Node* head, char* name);
void searchByClass(Node* head, int classNum);
void deleteById(Node* head, int id);
void deleteByName(Node* head, char* name);
void updateById(Node* head, int id);
void updateByName(Node* head, char* name);
void sortAscending(Node* head);
void sortDescending(Node* head);
void countByClass(Node* head);
void countByProvince(Node* head);
void loadFromFile(Node* head, char* filename);
void saveToFile(Node* head, char* filename);

Node* studentList = NULL;

int main() {
    studentList = createList();
    loadFromFile(studentList, "student.txt");

    while (1) {
        showMenu();
        handleInput();
        system("pause");
        system("cls");
    }
}

Node* createList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

Node* createNode(Student data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void showMenu() {
    printf("*************** [Student Contact Management System] ***************\n");
    printf("*  1. Add Student Information                                     *\n");
    printf("*  2. View All Student Information                                *\n");
    printf("*  3. Search Student Information                                  *\n");
    printf("*  4. Delete Student Information                                  *\n");
    printf("*  5. Update Student Information                                  *\n");
    printf("*  6. Sort Student Information                                    *\n");
    printf("*  7. Statistics                                                  *\n");
    printf("*  0. Exit                                                        *\n");
    printf("*******************************************************************\n");
    printf("Please select an option: ");
}

void handleInput() {
    Student data;
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            printf("Exiting system...\n");
            saveToFile(studentList, "student.txt");
            exit(0);
        case 1:
            printf("Enter Student ID, Name, Class, Address, Phone, Major:\n");
            scanf("%d %s %d %s %s %s", &data.id, data.name, &data.classNum, data.address, data.phone, data.major);
            addStudent(studentList, data);
            printf("Student added successfully.\n");
            break;
        case 2:
            displayStudents(studentList);
            break;
        case 3:
            handleSearch();
            break;
        case 4:
            handleDelete();
            break;
        case 5:
            handleUpdate();
            break;
        case 6:
            handleSort();
            break;
        case 7:
            handleStatistics();
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }
    saveToFile(studentList, "student.txt");
}

void handleSearch() {
    int choice, id, classNum;
    char name[20];

    printf("Search by:\n1. ID\n2. Name\n3. Class\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            searchById(studentList, id);
            break;
        case 2:
            printf("Enter Student Name: ");
            scanf("%s", name);
            searchByName(studentList, name);
            break;
        case 3:
            printf("Enter Class Number: ");
            scanf("%d", &classNum);
            searchByClass(studentList, classNum);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

void handleDelete() {
    int choice, id;
    char name[20];

    printf("Delete by:\n1. ID\n2. Name\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Student ID to delete: ");
            scanf("%d", &id);
            deleteById(studentList, id);
            break;
        case 2:
            printf("Enter Student Name to delete: ");
            scanf("%s", name);
            deleteByName(studentList, name);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

void handleUpdate() {
    int choice, id;
    char name[20];

    printf("Update by:\n1. ID\n2. Name\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Student ID to update: ");
            scanf("%d", &id);
            updateById(studentList, id);
            break;
        case 2:
            printf("Enter Student Name to update: ");
            scanf("%s", name);
            updateByName(studentList, name);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

void handleSort() {
    int choice;

    printf("Sort by:\n1. ID Ascending\n2. ID Descending\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sortAscending(studentList);
            break;
        case 2:
            sortDescending(studentList);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

void handleStatistics() {
    int choice;

    printf("Statistics:\n1. Class Count\n2. Province Count\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            countByClass(studentList);
            break;
        case 2:
            countByProvince(studentList);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

void addStudent(Node* head, Student data) {
    Node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

void displayStudents(Node* head) {
    Node* current = head->next;
    printf("ID\tName\tClass\tAddress\tPhone\t\tMajor\n");
    while (current) {
        printf("%d\t%s\t%d\t%s\t%s\t%s\n", current->data.id, current->data.name, current->data.classNum,
               current->data.address, current->data.phone, current->data.major);
        current = current->next;
    }
}

void searchById(Node* head, int id) {
    Node* current = head->next;
    while (current) {
        if (current->data.id == id) {
            printf("ID\tName\tClass\tAddress\tPhone\t\tMajor\n");
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", current->data.id, current->data.name, current->data.classNum,
                   current->data.address, current->data.phone, current->data.major);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void searchByName(Node* head, char* name) {
    Node* current = head->next;
    while (current) {
        if (strcmp(current->data.name, name) == 0) {
            printf("ID\tName\tClass\tAddress\tPhone\t\tMajor\n");
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", current->data.id, current->data.name, current->data.classNum,
                   current->data.address, current->data.phone, current->data.major);
            return;
        }
        current = current->next;
    }
    printf("Student with name %s not found.\n", name);
}

void searchByClass(Node* head, int classNum) {
    Node* current = head->next;
    int found = 0;

    printf("ID\tName\tClass\tAddress\tPhone\t\tMajor\n");
    while (current) {
        if (current->data.classNum == classNum) {
            printf("%d\t%s\t%d\t%s\t%s\t%s\n", current->data.id, current->data.name, current->data.classNum,
                   current->data.address, current->data.phone, current->data.major);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No students found in class %d.\n", classNum);
    }
}

void deleteById(Node* head, int id) {
    Node* prev = head;
    Node* current = head->next;

    while (current && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student deleted successfully.\n");
}

void deleteByName(Node* head, char* name) {
    Node* prev = head;
    Node* current = head->next;

    while (current && strcmp(current->data.name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        printf("Student with name %s not found.\n", name);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Student deleted successfully.\n");
}

void updateById(Node* head, int id) {
    Node* current = head->next;

    while (current && current->data.id != id) {
        current = current->next;
    }

    if (!current) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    printf("Enter new ID, Name, Class, Address, Phone, Major:\n");
    scanf("%d %s %d %s %s %s", &current->data.id, current->data.name, &current->data.classNum,
          current->data.address, current->data.phone, current->data.major);
    printf("Student information updated successfully.\n");
}

void updateByName(Node* head, char* name) {
    Node* current = head->next;

    while (current && strcmp(current->data.name, name) != 0) {
        current = current->next;
    }

    if (!current) {
        printf("Student with name %s not found.\n", name);
        return;
    }

    printf("Enter new ID, Name, Class, Address, Phone, Major:\n");
    scanf("%d %s %d %s %s %s", &current->data.id, current->data.name, &current->data.classNum,
          current->data.address, current->data.phone, current->data.major);
    printf("Student information updated successfully.\n");
}

void sortAscending(Node* head) {
    Node *i, *j;
    Student temp;

    for (i = head->next; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.id > j->data.id) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Sorted in ascending order.\n");
    displayStudents(head);
}

void sortDescending(Node* head) {
    Node *i, *j;
    Student temp;

    for (i = head->next; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.id < j->data.id) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Sorted in descending order.\n");
    displayStudents(head);
}

void countByClass(Node* head) {
    int count[MAX_CLASSES + 1] = {0};
    Node* current = head->next;

    while (current) {
        if (current->data.classNum >= 1 && current->data.classNum <= MAX_CLASSES) {
            count[current->data.classNum]++;
        }
        current = current->next;
    }

    for (int i = 1; i <= MAX_CLASSES; i++) {
        printf("Class %d: %d students\n", i, count[i]);
    }
}

void countByProvince(Node* head) {
    char provinces[34][100] = {
        "Hebei", "Shanxi", "Liaoning", "Jilin", "Heilongjiang", "Jiangsu", "Zhejiang",
        "Anhui", "Fujian", "Jiangxi", "Shandong", "Henan", "Hubei", "Hunan", "Guangdong",
        "Hainan", "Sichuan", "Guizhou", "Yunnan", "Shaanxi", "Gansu", "Qinghai", "Taiwan",
        "Inner Mongolia", "Guangxi", "Tibet", "Ningxia", "Xinjiang", "Beijing", "Tianjin",
        "Shanghai", "Chongqing", "Hong Kong", "Macau"
    };

    int count[34] = {0};
    Node* current = head->next;

    while (current) {
        for (int i = 0; i < 34; i++) {
            if (strcmp(current->data.address, provinces[i]) == 0) {
                count[i]++;
                break;
            }
        }
        current = current->next;
    }

    for (int i = 0; i < 34; i++) {
        if (count[i] > 0) {
            printf("%s: %d students\n", provinces[i], count[i]);
        }
    }
}

void loadFromFile(Node* head, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file.\n");
        return;
    }

    Student data;
    while (fscanf(fp, "%d\t%s\t%d\t%s\t%s\t%s\n", &data.id, data.name, &data.classNum,
                  data.address, data.phone, data.major) != EOF) {
        addStudent(head, data);
    }

    fclose(fp);
}

void saveToFile(Node* head, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Failed to open file for writing.\n");
        return;
    }

    Node* current = head->next;
    while (current) {
        fprintf(fp, "%d\t%s\t%d\t%s\t%s\t%s\n", current->data.id, current->data.name,
                current->data.classNum, current->data.address, current->data.phone, current->data.major);
        current = current->next;
    }

    fclose(fp);
}
