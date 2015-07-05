#include "set.h"

#define EMPTY 0
#define FILLED 1
#define DELETED 2


SET *createSet(int maxElts){
        SET * new_set;
        new_set =malloc(sizeof(SET));
        new_set->count = 0;
        new_set->length = maxElts;
        new_set->data=malloc(maxElts * sizeof(char*));
        new_set->flags=malloc(maxElts * sizeof(char));
        int i;
        for(i=0; i<new_set->length; i++){
                new_set->flags[i]=EMPTY;
        }
        return new_set;
}

void destroySet(SET *sp){
        assert(sp!=NULL);
        int i;
        for(i = 0;i<sp->count; i++){
            if(sp->flags[i]==FILLED)
                free(sp->data[i]);
        }
        free(sp->data);
        free(sp);
}

int numElements(SET *sp){
        assert(sp!=NULL);
        return sp->count;
}

bool hasElement(SET *sp, char *elt){
        bool found;
        unsigned pos = findElement(sp, elt, &found);
        if(found)
                return true;
        return false;
}

unsigned hashString(char *s){
        unsigned hash = 0;
        while (*s != '\0')
                hash = 31 * hash + *s ++;
        return hash;
}

unsigned findElement(SET *sp, char *elt, bool *found){
        int available = -1;
    int loc;
        unsigned start = hashString(elt)%sp->length;
        int i;
        for(i=0; i<sp->length; i++){
                loc = (start+i)%sp->length;
                if(sp->flags[loc]== EMPTY){
            *found=false;
                        if(available==-1){
                    return loc;
                        }
                        return available;
                }

                if(sp->flags[loc]== DELETED && available == -1){
                        available = loc;
                }

                if(sp->flags[loc]== FILLED){
                        if(strcmp(sp->data[loc], elt)==0){
                                *found = true;
                                return loc;
                        }
                }
        }
        *found = false;
    return available;
}

bool addElement(SET * sp, char *elt){
        assert(sp!=NULL & elt!=NULL);
        unsigned pos;
        bool found;
        if(hasElement(sp,elt)==true)
               return false;
        if(sp->count==sp->length)
            return false;
        pos = findElement(sp, elt, &found);
        elt=strdup(elt);
        sp->data[pos]=elt;
        sp->flags[pos]=FILLED;
        sp->count++;
        return true;
}
bool removeElement(SET *sp, char *elt){
        bool found;
        assert(sp!=NULL & elt!=NULL);
        unsigned pos;
        pos = findElement(sp, elt, &found);
        if(found){
                free(sp->data[pos]);
                sp->flags[pos]=DELETED;
                sp->count--;
                return true;
        }
        return false;
}

