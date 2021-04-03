//passed all tests
Node* mergeLists(Node* first_node, Node* second_node) {
	Node *new_node = new Node;
	if (first_node == NULL or second_node == NULL) {
		if (first_node == NULL and second_node == NULL)
			return NULL;
	  if (first_node == NULL and second_node != NULL)
		  return second_node;
	  if (first_node != NULL and second_node == NULL)
		  return first_node;
	} 
  else {
		if (first_node->value > second_node->value) {
			new_node->value = second_node->value;
			new_node->next = mergeLists(first_node, second_node->next); 
		}
		if (first_node->value < second_node->value) {
			new_node->value = first_node->value;
			new_node->next = mergeLists(first_node->next, second_node); 
		}
		if (first_node->value == second_node->value) {
			new_node->value = first_node->value;
			new_node->next = mergeLists(first_node->next, second_node->next);
		}
	}
	return new_node;
}
