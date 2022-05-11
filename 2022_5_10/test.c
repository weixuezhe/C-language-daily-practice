
#include <stdio.h>
#include <string.h>
#include <assert.h>


//¸´¿Ìstrlen()º¯Êý --> ×Ö·û´®³¤¶È
//unsigned int my_strlen(const char* src) {
//	int count = 0;
//	while(*src) {
//		count++;
//		src++;
//	}
//	return count;
//}
//int main() {
//	char a[] = "abcdefg";
//	int c = my_strlen(a);
//	printf("%d", c);
//	return 0;
//}



//¸´¿Ìstrcpy()º¯Êý --> ×Ö·û´®¿½±´
//char* my_strcpy(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*src != '\0') {
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//	return ret;
//}
//×îÓÅ½â
//char* my_strcpy(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest++ = *src++) {
//		;
//	}
//	return ret;
//}
//int main() {
//	char a[] = "abcdefg";
//	char b[] = "abc";
//	my_strcpy(a, b);
//	printf("%s", a);
//	return 0;
//}



//¸´¿Ìstrcatº¯Êý --> ×Ö·û´®×·¼Ó
//char* my_strcat(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	while (*dest) {
//		dest++;
//	}
//	while (*dest++ = *src++) {
//		;
//	}
//	return ret;
//}
//int main() {
//	char a[30] = "Hello";
//	char b[] = "World";
//	my_strcat(a, b);
//	printf("%s", a);
//	return 0;
//}



//¸´¿Ìstrcmpº¯Êý --> ×Ö·û´®±È½Ï
//int my_strcmp(char* arr1, char* arr2) {
//	assert(arr1 && arr2);
//	while (*arr1 == *arr2) {
//		if (*arr1 == '\0') {
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
//	if (*arr1 > *arr2) {
//		return 1;
//	}
//	else {
//		return -1;
//	}
//}
//int main() {
//	char a[] = "abcde";
//	char b[] = "abcdf";
//	int c = my_strcmp(a, b);
//	if (c > 0) {
//		printf("a>b");
//	}
//	else if (c < 0) {
//		printf("a<b");
//	}
//	else {
//		printf("a==b");
//	}
//}



//¸´¿Ìstrstrº¯Êý --> ×Ö·û´®²éÕÒ
char* my_strstr(const char* p1, const char* p2) {
	assert(*p1 && *p2);
	if (!*p2) {
		return p1;
	}
	char* s1 = p1;
	char* s2 = p2;
	char* sur = p1;
	while (*sur) {
		s1 = sur;
		s2 = p2;
		while (*s1 && *s2  && *s1 == *s2) {
			s1++;
			s2++;
		}
		if (!(*s2)) {
			return sur;
		}
		sur++;
	}
	return NULL;
}
int main() {
	char* a = "abbbcdef";
	char* b = "bbc";
	char* c = my_strstr(a, b);
	if (c == NULL) {
		printf("ÕÒ²»µ½×Ö·û´®");
	}
	else {
		printf("%s\n", c);
	}
}