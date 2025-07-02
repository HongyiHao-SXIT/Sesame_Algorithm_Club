#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define cls system("cls")
#define endl puts("")
#define title(x) printf("============%s============\n", x)

typedef struct _Student {
    char name[20], idx[20];
    int grade, numQue;
    struct _Student* next;
} Stu;

typedef struct _Problems {
    int idx, state;
    char q[50], op[4][25], ans;
    struct _Problems* next;
} Pro;

char convert(char c) {
    if ('a' <= c && c <= 'z') c += 'A' - 'a';
    return c;
}

Pro* getRandomProblem(Pro* proHead, int countProblems) {
    srand((unsigned int)time(NULL));
    while (1) {
        int selectedProblem = rand() % countProblems + 1;
        for (Pro* point = proHead->next; point != NULL; point = point->next) {
            if (point->idx == selectedProblem) {
                if (point->state) {
                    break;
                } else {
                    point->state = 1;
                    return point;
                }
            }
        }
    }
}

void clearState(Pro* proHead, int countProblems) {
    for (Pro* point = proHead->next; point != NULL; point = point->next) {
        point->state = 0;
    }
}

int readProblems(Pro* proHead) {
    FILE *fpReadProblems = fopen("test.txt", "r");
    if (fpReadProblems == NULL) {
        printf("Unable to open question file!\n");
        return 0;
    }

    char cnt[20];
    int countProblems = 0;
    fscanf(fpReadProblems, "%s", cnt);
    for (int i = 12; i < strlen(cnt); i++) {
        char c = cnt[i];
        if ('0' <= c && c <= '9') {
            countProblems = countProblems * 10 + c - '0';
        } else {
            break;
        }
    }

    for (int i = 0; i < countProblems; i++) {
        Pro* readSavedProblems = (Pro*)malloc(sizeof(Pro));
        if (readSavedProblems == NULL) {
            printf("Memory allocation failed!\n");
            fclose(fpReadProblems);
            return 0;
        }
        fscanf(fpReadProblems, "%s", readSavedProblems->q);
        for (int j = 0; j < 4; j++) {
            fscanf(fpReadProblems, "%s", readSavedProblems->op[j]);
        }
        char ans[10];
        fscanf(fpReadProblems, "%s", ans);
        readSavedProblems->ans = ans[6];
        readSavedProblems->idx = countProblems - i;
        readSavedProblems->state = 0;

        readSavedProblems->next = proHead->next;
        proHead->next = readSavedProblems;
    }

    fclose(fpReadProblems);
    return countProblems;
}

int readStudents(Stu* stuHead) {
    FILE *fpReadStudents = fopen("stu.txt", "r");
    if (fpReadStudents == NULL) {
        printf("Unable to open student file!\n");
        return 0;
    }

    char cnt[40];
    fscanf(fpReadStudents, "%s", cnt);
    int countStudents = 0;

    for (int i = 6; i < strlen(cnt); i++) {
        char c = cnt[i];
        if ('0' <= c && c <= '9') {
            countStudents = countStudents * 10 + c - '0';
        } else {
            break;
        }
    }

    fscanf(fpReadStudents, "%*s%*s%*s%*s");
    for (int i = 0; i < countStudents; i++) {
        Stu* readSavedStudents = (Stu*)malloc(sizeof(Stu));
        if (readSavedStudents == NULL) {
            printf("Memory allocation failed!\n");
            fclose(fpReadStudents);
            return 0;
        }
        fscanf(fpReadStudents, "%s%s%d%d", readSavedStudents->name, readSavedStudents->idx, &readSavedStudents->grade, &readSavedStudents->numQue);
        readSavedStudents->next = stuHead->next;
        stuHead->next = readSavedStudents;
    }
    fclose(fpReadStudents);
    return countStudents;
}

void saveProblems(Pro* proHead, int countProblems) {
    FILE *fpWriteProblems = fopen("test.txt", "w");
    if (fpWriteProblems == NULL) {
        printf("Unable to open question file for writing!\n");
        return;
    }

    fprintf(fpWriteProblems, "Current number of questions: %d\n\n", countProblems);
    for (Pro* writeProblems = proHead->next; writeProblems != NULL; writeProblems = writeProblems->next) {
        fprintf(fpWriteProblems, "%s\n", writeProblems->q);
        for (int i = 0; i < 4; i++) {
            fprintf(fpWriteProblems, "%s\n", writeProblems->op[i]);
        }
        fprintf(fpWriteProblems, "Answer: %c\n\n", writeProblems->ans);
    }

    while (proHead->next != NULL) {
        Pro* temp = proHead->next;
        proHead->next = temp->next;
        free(temp);
    }

    fclose(fpWriteProblems);
}

void saveStudents(Stu* stuHead, int countStudents) {
    FILE *fpSaveStudents = fopen("stu.txt", "w");
    if (fpSaveStudents == NULL) {
        printf("Unable to open student file for writing!\n");
        return;
    }

    fprintf(fpSaveStudents, "Total number of students who have answered questions: %d\n\n", countStudents);
    fprintf(fpSaveStudents, "Name\tStudent ID\tGrade\tNumber of Questions\n");
    for (Stu* point = stuHead->next; point != NULL; point = point->next) {
        fprintf(fpSaveStudents, "%s\t%s\t%d\t%d\n", point->name, point->idx, point->grade, point->numQue);
    }

    while (stuHead->next != NULL) {
        Stu* temp = stuHead->next;
        stuHead->next = temp->next;
        free(temp);
    }

    fclose(fpSaveStudents);
}

void outputProblems(Pro* proHead, int countProblems) {
    cls;
    title(" Question Bank ");
    endl;
    for (Pro* outProblems = proHead->next; outProblems != NULL; outProblems = outProblems->next) {
        printf("%03d. %s\n", outProblems->idx, outProblems->q);
        for (int i = 0; i < 4; i++) {
            printf("%s\n", outProblems->op[i]);
        }
        printf("Answer: %c\n\n", outProblems->ans);
    }

    endl;
    printf("Current number of questions: %d\n\n", countProblems);
    endl;
    title(" Question Bank ");
}

void outputStudents(Stu* stuHead, int countStudents) {
    cls;
    title(" Student Grade Table ");
    endl;
    puts("Name\tStudent ID\tGrade\tNumber of Questions");
    for (Stu* point = stuHead->next; point != NULL; point = point->next) {
        printf("%s\t%s\t%d\t%d\n", point->name, point->idx, point->grade, point->numQue);
    }
    endl;
    printf("Number of students who have completed the exam: %d\n", countStudents);
    endl;
    title("===========");
}

void deleteProblem(Pro* proHead, int toBeDeleted) {
    Pro* last = proHead;
    for (Pro* point = proHead->next; point != NULL; last = point, point = point->next) {
        if (point->idx == toBeDeleted) {
            last->next = point->next;
            free(point);
            break;
        }
    }
}

int editProblem(Pro* proHead, int countProblems, int problemToBeEdited) {
    cls;
    title(" Edit Question ");
    endl;
    puts("\t0 > Exit");
    puts("\t1 > Delete");
    puts("\t2 > Modify");
    endl;
    title("==========");

    int choose;
    scanf("%d", &choose);
    if (choose == 0) {
        return countProblems;
    } else if (choose == 1) {
        countProblems--;
        deleteProblem(proHead, problemToBeEdited);
        return countProblems;
    }

    Pro* point;
    for (point = proHead->next; point != NULL; point = point->next) {
        if (point->idx == problemToBeEdited) {
            break;
        }
    }

    if (point == NULL) {
        printf("Question not found!\n");
        return countProblems;
    }

    cls;
    title(" Edit Question ");
    printf("Question: %s\nModify to: (Enter 'next' to keep unchanged)\n", point->q);
    char q2[50];
    scanf("%s", q2);
    if (strcmp(q2, "next") != 0) {
        strcpy(point->q, q2);
    }

    for (int i = 0; i < 4; i++) {
        cls;
        title(" Edit Question ");
        printf("%c Option: %s\nModify to: (Enter 'next' to keep unchanged)\n", 'A' + i, point->op[i]);
        char op[25];
        scanf("%s", op);
        if (strcmp(op, "next") != 0) {
            sprintf(point->op[i], "%c.%s", 'A' + i, op);
        }
    }

    cls;
    printf("Original answer: %c\nModify to: (Enter 'next' to keep unchanged)\n", point->ans);
    char anss[10];
    scanf("%s", anss);
    if (strcmp(anss, "next") != 0) {
        anss[0] = convert(anss[0]);
        point->ans = anss[0];
    }
    return countProblems;
}

int addProblem(Pro* proHead, int countProblems) {
    cls;
    title(" Add Question ");
    Pro* addNewProblems = (Pro*)malloc(sizeof(Pro));
    if (addNewProblems == NULL) {
        printf("Memory allocation failed!\n");
        return countProblems;
    }
    printf("Question: ");
    scanf("%s", addNewProblems->q);
    for (int i = 0; i < 4; i++) {
        printf("%c Option: ", 'A' + i);
        scanf("%s", addNewProblems->op[i]);
        char index[30] = "";
        sprintf(index, "%c.%s", 'A' + i, addNewProblems->op[i]);
        strcpy(addNewProblems->op[i], index);
    }
    char ans;
    printf("Answer: ");
    getchar();
    scanf("%c", &ans);
    ans = convert(ans);
    addNewProblems->ans = ans;
    addNewProblems->idx = countProblems + 1;
    addNewProblems->state = 0;

    addNewProblems->next = proHead->next;
    proHead->next = addNewProblems;
    countProblems++;
    return countProblems;
}

int manageProblems(Pro* proHead, int countProblems) {
    cls;
    title(" Manage Question Bank ");
    endl;
    puts("\t0 > Exit");
    puts("\t1 > Edit Question");
    puts("\t2 > Add Question");
    endl;
    title("==========");

    int chooseManageProblems;
    scanf("%d", &chooseManageProblems);
    switch (chooseManageProblems) {
        case 0:
            return countProblems;
        case 1:
            outputProblems(proHead, countProblems);
            printf("Please select the question number to edit: ");
            int problemToBeEdited;
            scanf("%d", &problemToBeEdited);
            countProblems = editProblem(proHead, countProblems, problemToBeEdited);
            break;
        case 2:
            countProblems = addProblem(proHead, countProblems);
            break;
    }

    return countProblems;
}

int startTeacher(Stu* stuHead, Pro* proHead, int countStudents, int countProblems) {
    while (1) {
        cls;
        title(" Teacher Login ");
        endl;
        char account[20], password[20];
        const char acc[20] = "admin", pswd[20] = "admin";
        printf("\tAccount: ");
        scanf("%s", account);
        printf("\tPassword: ");
        scanf("%s", password);
        if (strcmp(account, acc) == 0 && strcmp(password, pswd) == 0) {
            break;
        }
        cls;
        title(" Teacher Login ");
        printf("\n\tIncorrect account or password\n\n");
        title("==========");
        Sleep(1500);
    }

    while (1) {
        cls;
        title(" Teacher Management ");
        endl;
        puts("\t0 > Exit");
        puts("\t1 > Display All Questions");
        puts("\t2 > Manage Question Bank");
        puts("\t3 > View Student Grades");
        endl;
        title("==========");

        int choooseTeacherManage;
        scanf("%d", &choooseTeacherManage);
        switch (choooseTeacherManage) {
            case 0:
                return countProblems;
            case 1:
                outputProblems(proHead, countProblems);
                printf("Enter any character to exit: ");
                char c2quit[20];
                scanf("%s", c2quit);
                break;
            case 2:
                countProblems = manageProblems(proHead, countProblems);
                break;
            case 3:
                outputStudents(stuHead, countStudents);
                printf("Enter any character to exit: ");
                char c3quit[20];
                scanf("%s", c3quit);
                break;
        }
        saveProblems(proHead, countProblems);
        countProblems = readProblems(proHead);
    }
}

void startStudent(Stu* stuHead, Pro* proHead, int countStudents, int countProblems) {
    Stu* addNewStudent = (Stu*)malloc(sizeof(Stu));
    if (addNewStudent == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    cls;
    title(" Student Login ");
    endl;
    printf("\tName: ");
    scanf("%s", addNewStudent->name);
    printf("\tStudent ID: ");
    scanf("%s", addNewStudent->idx);

    clearState(proHead, countProblems);

    cls;
    title(" Student Exam ");
    endl;
    printf("\tNumber of questions to draw: ");
    int countSelectedProblems, countRightProblems = 0;
    scanf("%d", &countSelectedProblems);

    for (int i = 0; i < countSelectedProblems; i++) {
        cls;
        title(" Student Exam ");
        endl;

        Pro* selectedProblem = getRandomProblem(proHead, countProblems);

        printf("Question %d: %s\n", i + 1, selectedProblem->q);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", selectedProblem->op[j]);
        }

        printf("\nChoose: ");

        getchar();
        char choose;
        scanf("%c", &choose);
        choose = convert(choose);
        if (choose == selectedProblem->ans) {
            countRightProblems++;
        }
    }
    addNewStudent->grade = (double)(countRightProblems * 100) / countSelectedProblems;
    addNewStudent->numQue = countSelectedProblems;
    cls;
    title(" Exam Results ");
    endl;
    printf("\tCorrect: %d/%d\n", countRightProblems, countSelectedProblems);
    printf("\tScore: %d\n", addNewStudent->grade);
    puts("\tUpdating data, please wait");
    endl;
    title("==========");

    addNewStudent->next = stuHead->next;
    stuHead->next = addNewStudent;
    countStudents++;
    saveStudents(stuHead, countStudents);
    countStudents = readStudents(stuHead);

    printf("Enter any character to exit: ");
    char c4quit[20];
    scanf("%s", c4quit);
}

int main() {
    while (1) {
        cls;
        title(" Multiple-Choice Standardized Exam System ");
        endl;
        puts("\t\t0 > Save and Exit");
        puts("\t\t1 > Teacher Login");
        puts("\t\t2 > Student Login");
        endl;
        title("==========================");

        Stu *stuHead = (Stu *)malloc(sizeof(Stu));
        Pro *proHead = (Pro *)malloc(sizeof(Pro));
        if (stuHead == NULL || proHead == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        stuHead->next = NULL;
        proHead->next = NULL;

        int countProblems = readProblems(proHead);
        int countStudents = readStudents(stuHead);
        int chooseTorS;

        scanf("%d", &chooseTorS);
        switch (chooseTorS) {
            case 0:
                cls;
                title(" Multiple-Choice Standardized Exam System ");
                endl;
                puts("\t\t      Exited");
                endl;
                title("==========================");
                saveProblems(proHead, countProblems);
                saveStudents(stuHead, countStudents);
                free(stuHead);
                free(proHead);
                return 0;
            case 1:
                countProblems = startTeacher(stuHead, proHead, countStudents, countProblems);
                break;
            case 2:
                startStudent(stuHead, proHead, countStudents, countProblems);
                break;
        }
        saveProblems(proHead, countProblems);
        saveStudents(stuHead, countStudents);
        free(stuHead);
        free(proHead);
    }

    return 0;
}