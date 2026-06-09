int lengthOfLongestSubstring(char* s) {
    int last[128];
    for (int i = 0; i < 128; i++) {
        last[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int i =0;s[i] !='\0';i++)
    {
        if (last[(int)s[i]] >= start)
        {
            start = last[(int)s[i]] + 1;
        }
        last[(int)s[i]] = i;

        int len = i - start + 1;
        if (len > maxLen) {
            maxLen = len;
        }
    }
    return maxLen;
}
