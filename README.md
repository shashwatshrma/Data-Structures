********** DATA STRUCTURES PROJECT **********

This project implements and works with various data structures.
The following programs are included in this project:

- linked_list.c
	+ This program implements the basic operations of a linked list:
	- Searching: Implemented using the search function, returns the index of the element (zero indexed). Returns -1 if the element is not present
	- Insertion: Inserts the element passed to the insert function according to the following criteria:
		+ 1 inserts the element at the start of the linked list
		+ -1 inserts the element at the end of the list
		+ otherwise inserts at the specified position.
		+ returns -1 if the position is out of bounds.
	- Deletion: Deletes the element passed to the insert function according to the following criteria:
		+ 1 inserts the element at the start of the linked list
		+ -1 inserts the element at the end of the list
		+ otherwise inserts at the specified position.
		+ returns -1 if the position is out of bounds.
	
- double_ linked_list.c
	+ This program implements the same operations as linked_list.c on a double linked list.

- circular_ linked_list.c
	+ This program implements the same operations as linked_list.c on a circular linked list.

- stack_using_queue.c
	+ This program implements the functionalities of a stack using the queue data structure
	+ Push operation is handled by simply enqueuing the element in the queue
	+ Pop operation dequeues and enqueues the element size-1 times such that the last inserted element is at the front and then that element is dequeued and returned.
	
-  queue_using_stack.c
	+ This program implements the functionalities of a queue using the stack data structure
	+ Enqueue operation is handled by pushing the elements in a stack
	+ When dequeuing the elements, since the first element in is at the bottom of the stack, we first move all the elements of the stack into another stack and pop the element at the top of the second element (which is the first element entered by the user). We store this popped element and move all the elements back to the first stack to maintain the order of the elements. Thus, we achieve a FIFO data structure using the stack data structure i.e a stack.
