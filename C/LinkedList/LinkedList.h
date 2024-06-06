#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>

typedef struct LLNode
{
    int Value;
    struct LLNode * Next;
} LLNode;

typedef struct LList
{
    LLNode * Head, * Tail;
    int Size;
} LList;

void CreateLList(LList * List)
{
    List->Head = NULL;
}

void Add(LList * List, int Value)
{
    LLNode * N = (LLNode *) malloc(sizeof(LLNode));
    N->Next = List->Head;
    N->Value = Value;
    List->Head = N;
    ++List->Size;
}

int Get(LList * List, int index)
{
    if ((unsigned) index >= List->Size)
    {
        return 0;
    }

    LLNode * N = List->Head;
    while(--index)
    {
        N = N->Next;
    }
    return N->Value;
}

void Set(LList * List, int index, int Value)
{
    if ((unsigned) index >= List->Size)
    {
        return;
    }

    LLNode * N = List->Head;
    while(--index)
    {
        N = N->Next;
    }
    N->Value = Value;
}

void Remove(LList * List, int index)
{
    if ((unsigned) index >= List->Size)
    {
        return;
    }

    LLNode * N = List->Head, * P = NULL;
    while(--index)
    {
        P = N;
        N = N->Next;
    }
    N = N->Next;
    free(P->Next);
    P->Next = N;
    --List->Size;
}

void DeleteLList(LList * List)
{
    for(int i = 0; i < List->Size; ++i)
    {
        Remove(List, 0);
    }
}

#endif