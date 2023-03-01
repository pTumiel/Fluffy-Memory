#include <stdio.h>
#include <stdbool.h>


int main(){

	char x='x';
	char charxy=x+'x';
	printf("%c",charxy);	
	while (true){
	printf("%c\r",x);
	x=x+'x';
	}
}
