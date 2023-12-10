#include "chaos_bool.h"

typedef struct s_triade {
    char id;          // A B C D E or F
    bool cell[3];     // true or false
    struct s_triade *next;
    struct s_triade *prev;
} t_triade;

typedef struct s_reel {
    t_triade		*triade;
    int			i_triade;
    struct s_reel	*next;
} t_reel;

t_triade *triade_ls;

t_reel *counter_next(t_reel *counter) {
    t_reel *initial_counter = counter;
    bool retenue = false;
    if (!counter)
        return set_reel();
    do {
        if (counter->triade->id == 'F')
            retenue = true;
        else
            retenue = false;
        counter->triade = counter->triade->next;
        if (retenue) {
            if (!counter->next) {
                counter->next = set_reel();
                retenue = false;
            }
            else
                counter = counter->next;
        }
    } while (retenue);
    return initial_counter;
}

bool    generator() {
    // put your main code here, to run repeatedly:
    static t_reel *counter;
    static int    i;
    static bool    last;
    static bool    ante;
    bool          output;
	if (!counter)
		counter = set_reel();
	do {
		output = counter->triade->cell[i];
		if (++i == 3) {
			i = 0;
			counter = counter_next(counter);
		}
	} while (output == last && output == ante);
	ante = last;
	last = output;
	return output;
}

int main() {
    // put your main code here, to run repeatedly:
	bool last = true, ante = false, current;
	triade_ls = set_list();
	t_reel *counter = NULL;
	for (int i =0; i< 1000; i++) {
		if ((current = generator()) == ante && ante == last)
			printf("bug");
		current ? printf("A ") : printf("B ");
		ante = last;
		last = current;
	}
}
