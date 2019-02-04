#include "stack.h"
#include <cstdio>
typedef struct _node
{
  struct _node* next;
  void* data;
}Node;

struct StackImplementation
{
    Node* head;
    Node* tail;
};


Stack create_stack()
{
    Stack stack = (Stack)smalloc(sizeof(struct StackImplementation));
    stack->head = 0;
    stack->tail = 0;
    return stack;
}


void delete_stack(Stack stack)
{
  int length = get_count(stack);

  for (int i = 0; i < length; i++)
  {
    Node* removeNode = stack->head;
    stack->head = removeNode->next;
    sfree(removeNode);
  }
  sfree(stack);
}

void push_stack(Stack stack, void *data)
{
    Node* newNode = (Node*)smalloc(sizeof(struct _node));
    newNode->data = data;
    //n->next = 0;
    if (stack->head == 0)
    {
      stack->head = newNode;
      stack->tail = newNode;
      stack->tail->next = 0;
    }
    else
    {
        newNode->next = stack->head;
        stack->head = newNode;
    }
}


int get_count(Stack stack)
{
    Node* current = stack->head;
    int count = 0;
    while (current != 0)
    {
        count++;
        current = current->next;
    }
    return count;
}


void* pop_stack(Stack stack)
{
    if (stack->head == 0)
    {
      return 0;
    }
    Node* removeNode = stack->head;
    stack->head = removeNode->next;

    if (stack->head == 0)
    {
      stack->tail = 0;
    }

    void* data = removeNode->data;
    sfree(removeNode);
    return data;
}


void* peek_stack(Stack stack)
{
    if (stack->head == 0)
    {
      return 0;
    }
    else
    {
      return stack->head->data;
    }
}
