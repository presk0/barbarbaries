#ifndef __CHAOS__
#define __CHAOS__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_triade t_triade;
typedef struct s_reel t_reel;
t_triade *triade_ls;

t_reel *counter_next(t_reel *counter) ;
bool    generator() ;

#endif
