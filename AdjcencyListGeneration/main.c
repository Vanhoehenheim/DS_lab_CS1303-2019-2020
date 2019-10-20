//Program to compute adjacency list from a file
#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int vertex;
    struct lnode *next;
} lnode;

void createNode(lnode *node, int data)
{

    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = (lnode *)malloc(sizeof(lnode));
    node->next->vertex = data;
    node->next->next = NULL;
}

void printList(lnode *node)
{
    while (node != NULL)
    {
        printf("%d ", node->vertex);
        node = node->next;
    }
    return;
}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int v, i, e, a, b;
    fscanf(fp, "%d,%d", &v, &e);
    lnode **vertices;
    vertices = (lnode **)malloc(v * sizeof(lnode *));
    for (i = 0; i < v; i++)
    {
        vertices[i] = (lnode *)malloc(sizeof(lnode));
        vertices[i]->vertex = i + 1;
        vertices[i]->next = NULL;
    }
    for (i = 0; i < e; i++)
    {
        fscanf(fp, "%d,%d", &a, &b);
        createNode(vertices[a - 1], b);
        createNode(vertices[b - 1], a);
    }
    fclose(fp);
    for (i = 0; i < v; i++)
    {
        printList(vertices[i]);
        printf("\n");
    }
    return 0;
}
