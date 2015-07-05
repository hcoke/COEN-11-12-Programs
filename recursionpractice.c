#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

intmax_t f(intmax_t n);

int main(){
	for(int i =0; i<50;i++){
	printf("%ld\n", f(i));
	}
return 0;
}



intmax_t f(intmax_t n){
	if(n == 0){
		return 1;
	}

	else{		
	return (f(n-1))*(f(n-1))+1;	
	}
}
