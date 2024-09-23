#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	char s[20];
	gets_s(s);
	char* str = s;
	for (int i = 0; i < strlen(s); i++) {
		printf("%c\n", str[i]);
	}
	for (int i = 0; i < strlen(s); i++) {
		//toupper(str[i]);
		printf("%c\n", str[i] - 32);
	}
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0) str[i] -= 32;
		else if (str[i] == ' ') str[i + 1] -= 32;
		printf("%c", str[i]);
	}
	return 0;
}