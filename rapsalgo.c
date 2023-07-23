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
	A cannot be followed by D E orF
Whit the same concept 
	B cannot be followed by E and E cannot be followed by B

	C cannot be followed by B and F by E

The infinite possibilities are parsed like digits
A B C D E F
AA AB AC (AD AE AF) => A cannot be followed by D E F
BA BB ...
	...
...    FD (FE) FF
AAA AAB ...
	...

counter is a list's list
	*/
#include <stdbool.h>
#include <stdlib.h>
#define MALLOC_ERR_NO 11


typedef struct	s_node {
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

t_node *reel;

typedef struct	s_triade {
	char	id; // A B C D E or F
	bool	cell[3]; // true or false
} t_triade;

t_node *set_list() {
	// create chained list with A B C D E F
	t_node	*head;
	t_node	*last;
	t_node	*new;
	head = malloc (sizeof(t_node));
	((t_triade*)head->data)->cell[0] = true;
	((t_triade*)head->data)->cell[1] = false;
	((t_triade*)head->data)->cell[2] = false;
	((t_triade*)head->data)->id = 'A';
	last = malloc (sizeof(t_node));
	if (!last)
		exit(MALLOC_ERR_NO);
	((t_triade*)last->data)->cell[0] = true;
	((t_triade*)last->data)->cell[1] = true;
	((t_triade*)last->data)->cell[2] = false;
	((t_triade*)last->data)->id = 'B';
	head->next = last;
	last->prev = head;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	((t_triade*)new->data)->cell[0] = true;
	((t_triade*)new->data)->cell[1] = false;
	((t_triade*)new->data)->cell[2] = true;
	((t_triade*)new->data)->id = 'C';
	last->next = new;
	new->prev = last;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	((t_triade*)new->data)->cell[0] = false;
	((t_triade*)new->data)->cell[1] = true;
	((t_triade*)new->data)->cell[2] = true;
	((t_triade*)new->data)->id = 'D';
	last->next = new;
	new->prev = last;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	((t_triade*)new->data)->cell[0] = false;
	((t_triade*)new->data)->cell[1] = false;
	((t_triade*)new->data)->cell[2] = true;
	((t_triade*)new->data)->id = 'E';
	last->next = new;
	new->prev = last;
	last = new;
	new = malloc (sizeof(t_node));
	if (!new)
		exit(MALLOC_ERR_NO);
	((t_triade*)new->data)->cell[0] = false;
	((t_triade*)new->data)->cell[1] = true;
	((t_triade*)new->data)->cell[2] = false;
	((t_triade*)new->data)->id = 'F';
	last->next = new;
	new-> next = head;
	new->prev = last;
	head->prev = new ;
	return head;
}

t_node	*counter_next(t_node *counter) {
	bool	retenue = false;
	do {
		if (counter) {
			if (((t_triade *)((t_node *)counter->data)->data)->id == 'F')
				retenue = true;
			else retenue = false;
			((t_node *)counter->data)->data = ((t_node *)((t_node *)counter->data)->data)->next;
			if (retenue && !counter->next) {
				counter->next = malloc(sizeof(t_node));
				if (!counter->next)
					exit(MALLOC_ERR_NO);
				counter->next->next = NULL;
				((t_node *)(counter->data))->data = (t_node *)reel;
				retenue = false;
			} else if (retenue && counter->next)
			counter = counter->next;
		}
	} while (retenue) ;
}

int main () {
	reel = set_list();
}