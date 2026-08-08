int maxVowels(char* s, int k) {
    int count = 0;

    // Count vowels in the first window of size k
    for (int i = 0; i < k; i++) {
        char c = s[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
            count++;
        }
    }

    int max = count;
    int x = 0;

    // Slide the window across the string
    for (int i = k; i < strlen(s); i++) {
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
            count++;
        }
        if (s[x]=='a'||s[x]=='e'||s[x]=='i'||s[x]=='o'||s[x]=='u') {
            count--;
        }
        x++;

        if (count > max) {
            max = count;
        }
    }

    return max;
}
