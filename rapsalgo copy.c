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

typedef struct s_triade {
    char id;          // A B C D E or F
    bool cell[3];     // true or false
    struct s_triade *next;
    struct s_triade *prev;
} t_triade;

typedef struct s_reel {
	t_triade	*triade;
	struct s_reel	*next;
} t_reel;

t_triade triade_ls;

t_triade	*append_reel(t_triade *last_reel, char new_id, bool cells[3]) {
	// create chained list with A B C D E F
	t_triade	*new;
	new = malloc (sizeof(t_triade));
	if (!new)
		exit(MALLOC_ERR_NO);
	new->id = new_id;
	new->cell[0] = cells[0];
	new->cell[1] = cells[1];
	new->cell[2] = cells[2];
	if (last_reel)
		last_reel->next = new;
	new->prev = last_reel;
	new->next = NULL;
	return new;
}

t_triade *set_list() {
	// create chained list with A B C D E F
	t_triade	*head;
	t_triade	*last;
	head = append_reel(NULL, 'A', (bool[]){true, false, false});
	last = append_reel(head, 'B', (bool[]){true, true, false });
	last = append_reel(last, 'C', (bool[]){true, false, true });
	last = append_reel(last, 'D', (bool[]){false, true, true });
	last = append_reel(last, 'E', (bool[]){false, false, true});
	last = append_reel(last, 'F', (bool[]){false, true, false});
	last->next = head;
	head->prev = last;
	return head;
}

t_reel	*set_reel() {
	t_reel	*new_reel;
	new_reel = malloc(sizeof(t_reel));
	if (!new_reel)
		exit(MALLOC_ERR_NO);
	new_reel->next = NULL;
	new_reel->triade = triade_ls;
}

t_triade	*counter_next(t_reel *counter) {
	bool	retenue = false;
	if (!counter)
		return set_reel();
	do {
		if (counter->triade->id == 'F')
			retenue = true;
		counter->triade = counter->triade->next;
		counter = counter->next;
	}
}

int main () {
	triade_ls = set_list();
	t_triade *counter = NULL;
	counter = counter_next(counter);
}