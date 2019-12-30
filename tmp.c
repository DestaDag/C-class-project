#include "gamelib.h"

static Cave_t* add(Cave_t* head) {
  Cave_t* current_node = head;
  Cave_t* new_node;
 while ( current_node != NULL && current_node->next != NULL) {
   current_node = current_node->next;
  }

  new_node = (Cave_t *) malloc(sizeof(Cave_t));
  new_node->data = num;
  new_node->next= NULL;
  if (current_node != NULL)
    current_node->next = new_node;
  else
     head = new_node;
return head;
}