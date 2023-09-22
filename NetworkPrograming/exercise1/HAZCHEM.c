#include <stdio.h>

void material (int code){
	switch (code){
	case 1: 
		printf("Material:\tjets\n");
		break;
	case 2: 
		printf("Material:\tfog\n");
		break;
	case 3:
		printf("Material:\tfoam\n");
		break;
	case 4:
		printf("Material:\tdry agent\n");
		break;
	default:
		printf("Material:\tunknown\n");
	}
}

void reactivity (char code){

}

void protection (char code){

}

void containment (char code){

}

void evacuation (char code){

}

void hazchem(char[] *code){

}