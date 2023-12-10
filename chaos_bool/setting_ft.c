#include "chaos_bool.h"

t_triade *append_reel(t_triade *last_reel, char new_id, const bool *cells) {
    // create a chained list with A B C D E F
    t_triade *new_triade = (t_triade *)malloc(sizeof(t_triade));
    new_triade->id = new_id;
    new_triade->cell[0] = cells[0];
    new_triade->cell[1] = cells[1];
    new_triade->cell[2] = cells[2];
    if (last_reel) {
        last_reel->next = new_triade;
        new_triade->prev = last_reel;
    } else {
        new_triade->prev = NULL;
    }
    new_triade->next = NULL;
    return new_triade;
}

t_triade *set_list() {
    // create a chained list with A B C D E F
    static const bool cell_A[] = {true, false, false};
    static const bool cell_B[] = {true, true, false};
    static const bool cell_C[] = {true, false, true};
    static const bool cell_D[] = {false, true, true};
    static const bool cell_E[] = {false, false, true};
    static const bool cell_F[] = {false, true, false};

    t_triade *head = append_reel(NULL, 'A', cell_A);
    t_triade *last = append_reel(head, 'B', cell_B);
    last = append_reel(last, 'C', cell_C);
    last = append_reel(last, 'D', cell_D);
    last = append_reel(last, 'E', cell_E);
    last = append_reel(last, 'F', cell_F);
    last->next = head;
    head->prev = last;
    return head;
}


t_reel *set_reel() {
    t_reel *new_reel = (t_reel *)malloc(sizeof(t_reel));
    new_reel->next = NULL;
    new_reel->triade = triade_ls;
    return new_reel;
}

