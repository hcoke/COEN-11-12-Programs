/*description: This file contains the public function and type
*              declarations for a set abstract data type for strings.  A
*              set is an unordered collection of distinct elements.
*
*              Note that this file uses the bool type, but does not define
*              it.  You should include <stdbool.h> beforehand.
*/

# ifndef SET_H
# define SET_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <assert.h>

typedef struct set{
        int count;
        int length;
        char **data;
        char *flags;
}SET;

SET *createSet(int maxElts);

void destroySet(SET *sp);

int numElements(SET *sp);

unsigned hashString(char *s);

unsigned findElement(SET *sp, char *ELT, bool *found);

bool hasElement(SET *sp, char *elt);

bool addElement(SET *sp, char *elt);

bool removeElement(SET *sp, char *elt);

# endif /* SET_H */
~                    
