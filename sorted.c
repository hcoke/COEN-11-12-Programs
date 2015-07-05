#include "set.h"

SET *createSet(int maxElts){
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
	if(strcmp(sp->data[sp->count/2],elt)==1){
		for(int i=count/2;i<count;i++){
			if(strcmp(sp->data[i],elt)==0){
				return true;
			}	
		}
	}
	if(strcmp(sp->data[sp->count/2],elt)==-1){
		for(int i=0;i<count/2;i++){
			if(strcmp(sp->data[i], elt)==0){
				return true;
			}
		}
	}
	if(strcmp(sp->data[sp->count/2],elt)==0)
		return true;
	return false;
}


bool addElement(ET *sp, char *elt){
	for(int i =0; i<sp->count; i++){
		hi=count;
		low=0;
		mid= sp->count/2;
		if(strcmp(sp->data[mid],elt)==1){
			for(int i=mid;i<hi;i++){
                        	if(strcmp(sp->data[i],elt)==0){ 
                                	return true;
                        	}
                	}
			
        	}	
        	if(strcmp(sp->data[mid],elt)==-1){
                	for(int i=low;i<mid;i++){
                       		if(strcmp(sp->data[i], elt)==0){
                                	return true;
                        	}
                	}
        	}
        	if(strcmp(sp->data[mid],elt)==0)
                return true;
	}
        return false;
}


bool removeElement(SET *sp, char *elt){

}
