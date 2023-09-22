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
	switch (code) {
	case 112:
	case 80:
	case 115:
	case 83:
	case 119:
	case 87:
	case 121:
	case 89:
	case 122:
	case 90:
		printf("Reactivity:\tcan be violently reactive\n");
		break;
	default:
		printf("Reactivity:\tunknown\n");	

	}
}

void protection (char code){

}

void containment (char code){

}

void evacuation (char code){

}

void hazchem(char[] *code){

}