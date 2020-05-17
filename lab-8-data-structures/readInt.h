#include <iostream>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>


int read_int(const char* prompt, int min, int max) {
	while (true) {
		printf("%s", prompt);
		char str[16];
		fgets(str, sizeof(str), stdin);
		if (strchr(str, '\n') == NULL) {
			int c;
			bool f = true;
			while ((c = fgetc(stdin)) != '\n' && EOF) {
				if (!isspace(c)) {
					f = false;
				}
			}
			if (f == false) {
				printf("The entered string is too large\n");
				continue;
			}
		}
		char* endptr = NULL;
		errno = 0;
		long n = strtol(str, &endptr, 10);
		if (errno == ERANGE) {
			printf("The entered number is too large");
			continue;
		}
		if (str == endptr) {
			printf("The entered string isn't contains now\n");
			continue;
		}
		bool flag = true;
		for (const char* p = endptr; *p != 0; ++p) {
			if (!isspace(*p)) {
				flag = false;
			}
		}
		if (!flag) {
			printf("The entered string contains invalid chars\n");
			continue;
		}
		if (n < min || n > max) {
			printf("Valid range is[%d;%d]\n", min, max);
			continue;
		}
		return (int)n;
	}
}