#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#define MaxVertexNum 100
#define MaxCost 9999
typedef char VertexType;
typedef int  EdgeType;
typedef struct
{
    VertexType vexs[MaxVertexNum];
    EdgeType  edges[MaxVertexNum][MaxVertexNum];
    int  n, e;
} Mgraph;

void menu();
void floyd(Mgraph G, int D[MaxVertexNum][MaxVertexNum], int P[MaxVertexNum][MaxVertexNum]);
void opfloy(int n, int D[MaxVertexNum][MaxVertexNum], int P[MaxVertexNum][MaxVertexNum]);
void hamanzi(Mgraph *G);
void CreateMGraph(Mgraph *G);
void printph();
void look();

int main()
{
    Mgraph G;
    int n, D[MaxVertexNum][MaxVertexNum], P[MaxVertexNum][MaxVertexNum];
    int a;
    char b[100];
    char user[20], mana[20] = "password", *q, *p, m = 0;
    system("color f0");
L:
    printf("\t     ***************************************************\n");
    printf("\tPlease log in (enter your username): ");
    scanf("%s", user);
    p = user;
    q = mana;
    while (*p == *q)
    {
        m = 1;
        p++;
        q++;
        if (*q == '\0')
            break;
    }
    if (*p != *q)
        m = 0;

    if (m == 1)
    {
        printf("");

        CreateMGraph(&G);
        system("cls");
L1:
        menu();
        printf("Please enter your option:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            floyd(G, D, P);
            opfloy(G.n, D, P);
            system("pause");
            system("cls");
            a = 35421568;
            goto L1;
        case 2:
            hamanzi(&G);
            system("pause");
            system("cls");
            a = 35421568;
            goto L1;
        case 3:
            printph();
            system("pause");
            system("cls");
            a = 35421568;
            goto L1;
        case 4:
            look();
            system("cls");
            a = 35421568;
            goto L1;
        case 0:
            break;

        default:
            printf("Your input is incorrect. Please enter again!!!\n");
            system("pause");
            gets(b);
            a = 35421568;
            system("cls");
            goto L1;
        }
    }
    else
    {
        system("cls");
L3:
        printf("\t\t\tYou are not an administrator and cannot modify scenic spot information.");
        printf("**********************************************************************************\n");
        printf("\t\t\t--------Campus Guide System-------\n");
        printf("\t\t\t   1: Go to a specified scenic spot\n");
        printf("\t\t\t   2: Traverse all scenic spots\n");
        printf("\t\t\t   3: View the campus map\n");
        printf("\t\t\t   4: View scenic spot introductions\n");
        printf("\t\t\t   5: Return to the login interface\n");
        printf("\t\t\t   0: Exit\n");
        printf("**********************************************************************************\n");
        printf("Please enter your option:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            floyd(G, D, P);
            opfloy(G.n, D, P);
            system("pause");
            system("cls");
            a = 35421568;
            goto L3;
        case 2:
            hamanzi(&G);
            system("pause");
            system("cls");
            a = 35421568;
            goto L3;
        case 3:
            printph();
            system("pause");
            system("cls");
            a = 35421568;
            goto L3;
        case 4:
            look();
            system("cls");
            a = 35421568;
            goto L3;
        case 5:
            a = 35421568;
            system("cls");
            goto L;
        case 0:
            break;

        default:
            printf("Your input is incorrect. Please enter again!!!\n");
            system("pause");
            gets(b);
            a = 35421568;
            system("cls");
            goto L3;
        }
    }

    return 0;
}

void menu()
{
    printf("**********************************************************************************\n");
    printf("\t\t\t-------Campus Guide System-------\n");
    printf("\t\t\t   1: Go to a specified scenic spot\n");
    printf("\t\t\t   2: Traverse all scenic spots\n");
    printf("\t\t\t   3: View the campus map\n");
    printf("\t\t\t   4: View scenic spot introductions\n");
    printf("\t\t\t   0: Exit\n");
    printf("**********************************************************************************\n");
}

void floyd(Mgraph G, int D[MaxVertexNum][MaxVertexNum], int P[MaxVertexNum][MaxVertexNum])
{
    int i, j, k;
    for (i = 0; i < G.n; i++)
        for (j = 0; j < G.n; j++)
        {
            D[i][j] = G.edges[i][j];
            if ((D[i][j] < MaxCost) && (D[i][j] != 0))
                P[i][j] = j;
            else
                P[i][j] = -1;
        }
    for (i = 0; i < G.n; i++)
        D[i][i] = 0;
    for (k = 0; k < G.n; k++)
        for (i = 0; i < G.n; i++)
            for (j = 0; j < G.n; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[i][k];
                }
}

void opfloy(int n, int D[MaxVertexNum][MaxVertexNum], int P[MaxVertexNum][MaxVertexNum])
{
    int i, j, k, c, m, p, min, next;
    printf("Please enter your current location and the destination location (e.g., m,p):\n");
    scanf("%d,%d", &m, &p);
    i = m;
    j = p;
    if (j != i)
    {
        printf("\nFrom %d to %d, you should walk as follows, and the shortest distance is:\n", i, j);
        printf("%d", i);
        next = P[i][j];
        while (next != -1)
        {
            printf("->%d", next);
            next = P[next][j];
        }
        if (D[i][j] == MaxCost)
            printf("->%d", j);
        printf("\t%d", D[i][j]);
    }
}

void hamanzi(Mgraph *G)
{
    int i, j, m, wei[5], sum = 0, min = 100, end[5], zui[6];
    int q, w, t, r;

    for (i = 1; i < 5; i++)
    {
        end[i] = 0;
    }
    printf("Please enter your starting point.\n");
    scanf("%d", &m);
    for (q = 0; q < 5; q++)
    {
        end[m] = 1;
        end[q] = 1;
        for (w = 0; w < 5; w++)
        {
            end[w] = 1;
            for (t = 0; t < 5; t++)
            {
                end[t] = 1;
                for (r = 0; r < 5; r++)
                {
                    end[r] = 1;
                    sum = G->edges[m][q] + G->edges[q][w] + G->edges[w][t] + G->edges[t][r] + G->edges[r][m];
                    end[m] = 1;
                    end[q] = 1;
                    end[w] = 1;
                    end[t] = 1;
                    end[r] = 1;

                    if (min > sum && end[0] == 1)
                    {
                        if (end[1] == 1 && end[2] == 1)
                        {
                            if (end[3] == 1 && end[4] == 1)
                            {
                                min = sum;
                                zui[1] = q;
                                zui[2] = w;
                                zui[3] = t;
                                zui[4] = r;
                                zui[5] = m;
                            }
                        }
                    }
                    sum = 200;
                    end[r] = 0;
                    end[t] = 0;
                }
                end[w] = 0;
            }
            end[q] = 0;
        }
    }
    printf("The minimum distance is: %d\n", min);
    printf("You should visit the scenic spots as follows:\n");
    printf("%d", m);
    for (i = 1; i < 6; i++)
    {
        printf("->%d", zui[i]);
    }
}

void CreateMGraph(Mgraph *G)
{
    int i, j, k, w;
    printf("Please enter the number of vertices and edges (input format: number of vertices, number of edges):\n");
    scanf("%d,%d", &(G->n), &(G->e));
    printf("Please enter vertex information:\n");
    for (i = 0; i < G->n; i++)
        scanf("\n%c", &(G->vexs[i]));
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->edges[i][j] = MaxCost;
    printf("Please enter the serial numbers of the two vertices corresponding to each edge (input format: i,j,w):\n");
    for (k = 0; k < G->e; k++)
    {
        scanf("%d,%d,%d", &i, &j, &w);
        G->edges[i][j] = w;
    }
}

void printph()
{
    printf("The park map is:\n");
    printf("\t\t\t\t0* * * * * * 1\n");
    printf("\t\t\t\t**          **\n");
    printf("\t\t\t\t* *        * *\n");
    printf("\t\t\t\t*  *      *  *\n");
    printf("\t\t\t\t*   *    *   *\n");
    printf("\t\t\t\t*    *  *    *\n");
    printf("\t\t\t\t*      2     *\n");
    printf("\t\t\t\t*     *      *\n");
    printf("\t\t\t\t*    *       *\n");
    printf("\t\t\t\t*   *        *\n");
    printf("\t\t\t\t*  *         *\n");
    printf("\t\t\t\t* *          *\n");
    printf("\t\t\t\t4* * * * * * 3\n");
}

void look()
{
    int a;
    char b[100];
    system("cls");
L2:
    printf("\t\t\t   1: Energy Flame\n");
    printf("\t\t\t   2: Library\n");
    printf("\t\t\t   3: Diligent Learning Building\n");
    printf("\t\t\t   4: Big Data Center\n");
    printf("\t\t\t   5: West Playground\n");
    printf("\t\t\t   6: Siqi Building\n");
    printf("\t\t\t   7: Xuezhiyuan Restaurant\n");
    printf("\t\t\t   8: Badminton and Table Tennis Hall\n");
    printf("\t\t\t   9: Innovation and Entrepreneurship Center\n");
    printf("\t\t\t   10: Dormitory\n");
    printf("\t\t\t   0: Return to the main interface\n");
    printf("Please enter your choice.\n");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("The Energy Flame symbolizes the coal - related history of Shanxi Institute of Technology.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 2:
        cout << "The library is newly built and has a large number of books, covering all professional courses in various disciplines.";
        system("cls");
        a = 65944899;
        goto L2;
    case 3:
        printf("The Diligent Learning Building is where students take professional courses. All classrooms are equipped with multimedia facilities to facilitate students' learning.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 4:
        printf("The Big Data Center is equipped with 10 servers to support the campus network and some school - related information resources.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 5:
        printf("The West Playground is a standard 400 - meter track and field stadium, providing the best space for students to exercise.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 6:
        printf("Siqi Building is equipped with well - equipped college physics laboratories.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 7:
        printf("Xuezhiyuan Restaurant provides first - class catering services.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 8:
        printf("The Badminton and Table Tennis Hall provides a leisure and entertainment place for students.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 9:
        printf("The Innovation and Entrepreneurship Center is equipped with first - class teaching resources in the province.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 10:
        printf("The student dormitory provides a high - quality living environment.");
        system("pause");
        system("cls");
        a = 65944899;
        goto L2;
    case 0:
        break;
    default:
        printf("Your input is incorrect!!!");
        system("pause");
        gets(b);
        system("cls");
        a = 65944899;
        goto L2;
    }
}    