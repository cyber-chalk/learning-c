typedef struct _stack *stack;

stack create(void);
void destroy(stack);
void empty(stack);
int is_empty(stack);
void push(stack, int);
int pop(stack);
