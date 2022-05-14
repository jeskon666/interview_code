/*!
 * Task 1.
 */
void 
task1(const Row *rows, int nrows)
{
    for (int i = 0; i < nrows; i++) {
        if ((rows[i].a == 1000 || rows[i].a == 2000 || rows[i].a == 3000) &&
            (rows[i].b >= 10 && rows[i].b < 50))
            printf("%d,%d\n", rows[i].a, rows[i].b);
    }
}

/*!
 * Task 2.
 */

/*!
 * 二分查找最低下标
 */
int 
binary_search_low(const Row *rows, int begin, int end, int target)
{
    int mid, result = -1;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (rows[mid].a > target) {
            end = mid - 1;
        } else if (rows[mid].a < target) {
            begin = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

/*!
 * 二分查找最高下标
 */
int 
binary_search_high(const Row *rows, int begin, int end, int target)
{
    int mid, result = -1;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (rows[mid].a > target) {
            end = mid - 1;
        } else if (rows[mid].a < target) {
            begin = mid + 1;
        } else {
            result = mid;
            begin = mid + 1;
        }
    }
    return result;
}

void 
task2(const Row *rows, int nrows)
{
    int low = 0, high = nrows - 1;
    int new_low, new_high;
    new_low = binary_search_low(rows, low, high, 1000);
    if (new_low != -1) {
        //new_high = binary_search_high(rows, new_low, high, 1000);
        new_high = high;
        for (int i = new_low; i <= new_high; i++) {
            if (rows[i].b >= 10 && rows[i].b < 50)
                printf("%d,%d\n", rows[i].a, rows[i].b);
            else if (rows[i].b >= 50) {
                new_high = i;
                break;
            }
        }
        low = new_high + 1;
    }

    new_low = binary_search_low(rows, low, high, 3000);
    if (new_low != -1) {
        //new_high = binary_search_high(rows, new_low, high, 3000);
        new_high = high;
        for (int i = new_low; i <= new_high; i++) {
            if (rows[i].b >= 10 && rows[i].b < 50)
                printf("%d,%d\n", rows[i].a, rows[i].b);
            else if (rows[i].b >= 50) {
                new_high = i;
                break;
            }
        }
        high = new_low - 1;
    }

    new_low = binary_search_low(rows, low, high, 2000);
    if (new_low != -1) {
        //new_high = binary_search_high(rows, new_low, high, 2000);
        new_high = high;
        for (int i = new_low; i <= new_high; i++) {
            if (rows[i].b >= 10 && rows[i].b < 50)
                printf("%d,%d\n", rows[i].a, rows[i].b);
            else if (rows[i].b >= 50) {
                break;
            }
        }
    }
}

/*!
 * Task 3.
 */
void 
task3(const Row *rows, int nrows)
{
    int low = 0, high = nrows - 1;
    int low_1000, high_1000;
    int low_2000, high_2000;
    int low_3000, high_3000;
    low_1000 = binary_search_low(rows, low, high, 1000);
    if (low_1000 != -1) {
        //high_1000 = binary_search_high(rows, low_1000, high, 1000);
        low = low_1000 + 1;
    }

    low_3000 = binary_search_low(rows, low, high, 3000);
    if (low_3000 != -1) {
        //high_3000 = binary_search_high(rows, low_3000, high, 3000);
        high = low_3000 - 1;
    }

    low_2000 = binary_search_low(rows, low, high, 2000);
    /*
    if (low_2000 != -1) {
        high_2000 = binary_search_high(rows, low_2000, high, 2000);
    }*/

    for (int target_b = 10; target_b < 50; target_b++) {
        if (low_1000 != -1) {
            for (int i = low_1000; i <= high; i++) {
                if (rows[i].b == target_b) {
                    low_1000 = i;
                    printf("%d,%d\n", rows[i].a, rows[i].b);
                } else if (rows[i].b > target_b) {
                    break;
                }
            }
        }
        if (low_2000 != -1) {
            for (int i = low_2000; i <= high; i++) {
                if (rows[i].b == target_b) {
                    low_2000 = i;
                    printf("%d,%d\n", rows[i].a, rows[i].b);
                } else if (rows[i].b > target_b) {
                    break;
                }
            }
        }
        if (low_3000 != -1) {
            for (int i = low_3000; i <= high; i++) {
                if (rows[i].b == target_b) {
                    low_3000 = i;
                    printf("%d,%d\n", rows[i].a, rows[i].b);
                } else if (rows[i].b > target_b) {
                    break;
                }
            }
        }
    }
}


/*!
 * Task 4.
 * 基数排序
 */
void 
task4(const Row *rows, int nrows)
{
    int low = 0, high = nrows - 1;
    int low_1000, high_99000;
    low_1000 = binary_search_low(rows, low, high, 1000);
    if (low_1000 != -1) {
        low = low_1000 + 1;
    }
    high_99000 = binary_search_high(rows, low, high, 1000);
    int queue[40][100];
    memset(queue, -1, sizeof(queue));

    for (int i = low_1000; i < high_99000; i++) {
        if (rows[i].a % 1000 == 0) {
            if (rows[i].b >= 10 && rows[i].b < 50)
                queue[rows[i].b - 10][rows[i].a % 1000] = i;
        }
    }
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 100; j++) {
            if (queue[i][j] != -1) {
                printf("%d,%d\n", rows[queue[i][j]].a, rows[queue[i][j]].b);
            }
        }
    }
}

