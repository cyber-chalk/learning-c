typedef struct _queue *queue;                                                                                                                                      
queue create(void);                                                                                                                    
void destroy(queue);                                                                                                                   
void empty(queue);                                                                                                                     
int is_empty(queue);                                                                                                                   
void enqueue(queue, int);                                                                                                              
int dequeue(queue);                                                                                                                    
void poll(queue);                                                                                                                      
                       
