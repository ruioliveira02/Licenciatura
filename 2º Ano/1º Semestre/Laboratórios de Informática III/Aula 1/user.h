#ifndef _USER_H_
#define _USER_H_

#include "types.h"
#include "date.h"


int convertDate(char*, void*);



REGISTERSTRUCT(User, 1,
    VAR(Date, profileDate, validateDate));
    
#endif