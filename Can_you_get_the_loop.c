typedef struct node_t Node;
struct node_t {
  Node* next;
};

int loop_size(Node* node) {
  Node *ptrActual = node;
  Node *ptrBefore = node;
  int flag = 1;
  int counter = 0;
  
  if(node->next == node)
    return 1;
  else{
    while(flag){
      ptrActual = ptrActual->next;
      ptrBefore = node;
      
      while(ptrActual != ptrBefore){
        if(ptrActual->next == ptrActual)
          return 1;
        else if(ptrActual->next == ptrBefore){
          while(ptrBefore != ptrActual){
            ++counter;
            ptrBefore = ptrBefore->next;
          }
          return counter + 1;
        }
        else{
          ptrBefore = ptrBefore->next;
        }
      }
    }
  }
  return 0;
}