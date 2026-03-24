// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }

    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];

        int pos = binarySearch(arr, i + 1, len - 1, target);

        if (pos != -1) {
            int j = pos;
            while (j < len && arr[j] == target) {
                ++count;
                ++j;
            }
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum < value) {
            ++left;
        } else if (sum > value) {
            --right;
        } else {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int leftVal = arr[left], leftCount = 0;
            while (arr[left] == leftVal && left < right) {
                ++left;
                ++leftCount;
            }

            int rightVal = arr[right], rightCount = 0;
            while (arr[right] == rightVal && left <= right) {
                --right;
                ++rightCount;
            }

            count += leftCount * rightCount;
        }
    }

    return count;
}
