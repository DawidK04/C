void arr_free(int *a) {
    free(a);
}

size_t arr_length(const int *a) {
    return a[0];
}

void arr_print(const int *a) {
    size_t len = arr_length(a);
    printf("[")
    for (size_t i = 0; i < len; ++i) {
        printf("%d", a[i + 1]);
        if (i < len - 1) {
            printf(", ")
        }
    }
    printf("]\n");
}

void arr_clear(int *a) {
    size_t len = arr_length(a);
    for (size_t i = 1; i <= len; ++i) {
        a[i] = 0;
    }
}

void arr_set(int *a, size_t index, int value) {
    size_t len = arr_length(a);
    if (index < len) {
        a[index + 1] = value;
    }
}

int arr_get(const int *a, size_t index) {
    size_t len = arr_length(a);
    if (index < len) {
        return a[index + 1];
    }
    return 0;
}

void arr_rand(int *a) {
    srand(time(NULL));
    for(int i = 1; i <= a[0]; i++) {
        a[i] = rand();
    }
}

int arr_dot(const int *a, const int *b) {
    int zm = 0;
    if(a[0] == b[0]) {
        for (int i = 1; i <= a[0]; i++) {
            zm += a[i] * b[i];
        }
    }
    return zm;
}

bool arr_add(int *dest, const int *arr) {
    if (dest[0] == arr[0]) {
        for(int i = 1, i <= dest[0], i++) {
            dest[i] += arr[i];
        }
    }
    return true;
}

int* arr_add_new(const int *a, const int *b) {
    if (int size_t a[0] > b[0]) {
        size = a[0];
    }else{
        size = b[0];
    }
    int* new_arr = arr_new(size);
    for (int i = 1; i <= size; i++) {
        new_arr[i] = arr_get(a, i) + arr_get(b, i); 
    }
    return new_arr;
}