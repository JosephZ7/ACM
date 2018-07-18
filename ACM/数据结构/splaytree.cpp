#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>


using namespace std;
int size1;
typedef struct tree_node tree;

struct tree_node
{
    tree * left, * right;
    int pri, num;
};

tree * splay(int i, tree * t)
{
    tree N, *l, *r, *y;
    if (t == NULL) return t;
    N.left = N.right = NULL;
    l = r = &N;
    while (1)
    {
        if (i < t -> pri)
        {
            if (t -> left == NULL)break;
            if (i < t -> left -> pri)
            {
                y = t -> left;
                t -> left = y -> right;
                y -> right = t;
                t = y;
                if (t -> left == NULL) break;
            }
            r -> left = t;
            r = t;
            t = t -> left;
        }
        else if (i > t -> pri)
        {
            if (t -> right == NULL) break;
            if (i > t -> right -> pri)
            {
                y = t -> right;
                t -> right = y -> left;
                y -> left = t;
                t = y;
                if (t -> right == NULL) break;
            }
            l -> right = t;
            l = t;
            t = t -> right;
        }
        else
        {
            break;
        }
    }
    l -> right = t -> left;
    r -> left = t -> right;
    t -> left = N.right;
    t -> right = N.left;
    return t;
}

tree * insert1(int i, int num, tree * t)
{
    tree * newNode;
    newNode = (tree * )malloc(sizeof(tree));
    if (newNode == NULL)
    {
        cout <<"Ran out of space" << endl;
        exit(1);
    }
    newNode -> pri = i;
    newNode -> num = num;
    if (t == NULL)
    {
        newNode -> left = newNode -> right = NULL;
        size1 = 1;
        return newNode;
    }
    t = splay(i, t);
    if (i < t -> pri)
    {
        newNode -> left = t -> left;
        newNode -> right = t;
        t -> left = NULL;
        size1 ++;
        return newNode;
    }
    else if (i > t -> pri)
    {
        newNode -> right = t -> right;
        newNode -> left = t;
        t -> right = NULL;
        size1 ++;
        return newNode;
    }
    else
    {
        free(newNode);
        return t;
    }
}

tree * deleteSplayTree(int i, tree * t)
{
    tree * x;
    if (t == NULL)return NULL;
    t = splay(i, t);
    if (i == t -> pri)
    {
        if (t -> left == NULL) x = t -> right;
        else
        {
            x = splay(i, t -> left);
            x -> right = t -> right;
        }
        size1 --;
        free(t);
        return x;
    }
    return t;
}

int maxPri, minPri;

void PrintMax(tree *p)
{
    while (p -> right) p = p -> right;
    printf("%d\n", p -> num);
    maxPri = p -> pri;
}

void PrintMin(tree *p)
{
    while (p -> left) p = p -> left;
    printf("%d\n", p -> num);
    minPri = p -> pri;
}



int main()
{
    tree *root;
    int i;
    root = NULL;
    size1 = 0;
    int n, num, pri;
    while (scanf("%d", &n), n)
    {
        switch(n)
        {
            case 1:
                scanf("%d%d",&num, &pri);
                root = insert1(pri, num, root);
                break;
            case 2:
                if (root == NULL)
                {
                    printf("0\n");
                    break;
                }
                PrintMax(root);
                root = deleteSplayTree(maxPri, root);
                break;
            case 3:
                if (root == NULL)
                {
                    printf("0\n");
                    break;
                }
                PrintMin(root);
                root = deleteSplayTree(minPri, root);
                break;
        }
    }
    return 0;
}
