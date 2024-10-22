#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
	int i,end;
    int n = strlen(s);
    int lastIndex[256]; 
    for (i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLength = 0;
    int start = 0; 

    for (end = 0; end < n; end++) {
        char currentChar = s[end];

        if (lastIndex[(int)currentChar] >= start) {
            start = lastIndex[(int)currentChar] + 1;
        }

        lastIndex[(int)currentChar] = end;

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {
	int i;
    char s1[] = "abcabcbb";
    printf("Length of longest substring without repeating characters in '%s': %d\n", s1, lengthOfLongestSubstring(s1));

    char s2[] = "bbbbb";
    printf("Length of longest substring without repeating characters in '%s': %d\n", s2, lengthOfLongestSubstring(s2));

    char s3[] = "pwwkew";
    printf("Length of longest substring without repeating characters in '%s': %d\n", s3, lengthOfLongestSubstring(s3));

    return 0;
}
