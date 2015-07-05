#include "set.h"

SET * createSet(int maxElts){
	SET * new_set;
	new_set = (SET*) malloc(sizeof(SET));
	new_set->count = 0;
	new_set->length = maxElts;
	new_set->data=malloc(maxElts * sizeof(char*));
	return new_set;
}


void destroySet(SET *sp){
	for(int i = 0;i<sp->count; i++){
		free(sp->data[i]);
	}
	free(sp);
}


int numElements(SET *sp){
	return sp->count;

}


bool hasElement(SET *sp, char *elt){
	for(int i=0; i<sp->count; i++){
		if(strcmp(elt, sp->data[i])==0){
			return true;
		}
	}
	return false;
}

int findElement(SET *sp, char *elt){
	for(int i=0; i<sp->count; i++){
                if(strcmp(elt, sp->data[i])==0){
                        return i;
                }
        }
	return -1;
}

bool addElement(SET *sp, char *elt){
	assert(elt!=NULL && sp!=NULL);
	if(hasElement(sp,elt)==true)
		return false;
	elt=strdup(elt);
        assert(elt!=NULL);
	sp->data[sp->count++]=elt;
	return false;
}


bool removeElement(SET *sp, char *elt){
	assert(sp!=NULL && elt!=NULL);
	int find;
	if((find = findElement(sp,elt))==-1){
		return false;
	}
	free(sp->data[find]);
	sp->data[find]=sp->data[sp->count--];
	return false;
}
