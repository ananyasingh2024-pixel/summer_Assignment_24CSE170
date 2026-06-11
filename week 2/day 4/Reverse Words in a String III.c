char* reverseWords(char* s) {
    int start = 0, end = 0;

    while (s[end] != '\0') {
        while (s[end] != ' ' && s[end] != '\0')
            end++;

        int left = start;
        int right = end - 1;

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }

        if (s[end] == '\0')
            break;

        end++;
        start = end;
    }

    return s;
}
