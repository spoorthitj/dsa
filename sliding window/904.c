
int totalFruit(int* fruits, int fruitsSize) {
    // Assuming fruit values are <= 100000 (LeetCode constraint)
    int maxFruitType = 100001;
    int* freq = (int*)calloc(maxFruitType, sizeof(int));

    int left = 0, maxlen = 0, distinct = 0;

    for (int right = 0; right < fruitsSize; right++) {
        if (freq[fruits[right]] == 0) {
            distinct++;
        }
        freq[fruits[right]]++;

        while (distinct > 2) {
            freq[fruits[left]]--;
            if (freq[fruits[left]] == 0) {
                distinct--;
            }
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxlen) {
            maxlen = windowLen;
        }
    }

    free(freq);
    return maxlen;
}

