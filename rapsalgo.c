/*
 * As a rapsodie concept, less recccurent pattern.
 * Made from two sound (or "object")
 * The first rule is : don't play 3 time the same note.


with two objects (a and b), on 3 times we can play:

A :		abb

B :		aab

C :		aba
_
A (or D) :	baa 
_
B (or E) : 	bba
_
C (or F) : 	bab

(we cannot have aaa or bbb)

Notice :
abb cannot be followed by any other b (because abbb contains 3 b)
so A cannot be followed by 	_ _ _
				A B C
Whit the same concept _
		      A cannot be followed by A B C

	B cannot be followed by _
				B and _
				      B cannot be followed by B

	C cannot be followed by B and _    _
				      C by B

The infinite possibilities are parsed like digits
A B C D E F
AA AB AC (AD AE AF) => A cannot be followed by D E F
BA BB ...
	...
...    FD (FE) FF
AAA AAB ...
	...
	*/
#include <stdbool.h>
#include <stdlib.h>
#define MALLOC_ERR_NO 11
typedef struct	s_node {
	char	id;
	bool	cell[3]; // true or false
	struct s_node	*next;
} t_node;

t_node *set_list() {
	// create chained list with A B C D E F
	t_node	*head;
	t_node	*last;
	t_node	*new;
	head = malloc (sizeof(t_node));
	head->cell[0] = true;
	head->cell[1] = false;
	head->cell[2] = false;
	head->id = 'A';
	last = malloc (sizeof(t_node));
	if (!last)
		exit(MALLOC_ERR_NO);
	last->cell[0] = true;
	last->cell[1] = true;
	last->cell[2] = false;
	head->id = 'B';
	head->next = last;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	new->cell[0] = true;
	new->cell[1] = false;
	new->cell[2] = true;
	head->id = 'C';
	last->next = new;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	new->cell[0] = false;
	new->cell[1] = true;
	new->cell[2] = true;
	head->id = 'D';
	last->next = new;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	new->cell[0] = false;
	new->cell[1] = false;
	new->cell[2] = true;
	head->id = 'E';
	last->next = new;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	new->cell[0] = false;
	new->cell[1] = true;
	new->cell[2] = false;
	head->id = 'F';
	last->next = new;
	new-> next = head;
	return head;
}
