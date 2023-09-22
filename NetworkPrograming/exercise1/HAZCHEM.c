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

void protection (char code, int coloured){
	switch (code){
	case 112:
	case 80:
	case 114:
	case 82:
	case 119:
	case 87:
	case 120: 
	case 88:
		printf("Protection:\tfull protective clothing must be worn\n");
		break;
	case 115:
	case 83:
	case 116:
	case 84:
	case 121:
	case 89:
	case 122:
	case 90:
		printf("Protection:\tbreathing apparatus%s\n", coloured?", protective gloves":". ");
		break;
	default:
		printf("Protection:\tunknown\n");
 }
}

void containment (char code){
	switch (code) {
	case 112:
	case 80:
	case 114:
	case 82:
	case 115:
	case 83:
	case 116:
	case 84:
		printf("Containment:\tmay be diluted and washed down the drain\n");
		break;
	case 119:
	case 87:
	case 120:
	case 88:
	case 121:
	case 89:
	case 122:
	case 90:
		printf("Containment:\tcontained, need to avoid spillages from entering drains or water courses\n");
		break;
	default:
		printf("Containment:\tunknown\n");	
	}
}

void evacuation (char code){
	if (code == 101||code == 69) printf("Evacuation:\tconsider evacuation\n");
	else printf("Evacuation:\tnone\n");
}

void hazchem(char[] *code, int coloured){
	printf("***Emergency action advice***");
	material(code[0]-48);
	reactivity(code[1]);
	protection(code[1], coloured);
	containment(code[1]);
	evacuation(code[2]);
	printf("*****************************");
}

void main(){
	char[3] code;
	char[3] coloured;
	printf("\nEnter HAZCHEM code: ");
	scanf("%s", code);
	printf("\nIs the S reverse coloured? ");
	scanf("%s", coloured);
}