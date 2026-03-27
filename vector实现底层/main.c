#include <stdio.h>
#include "vector.h"

int main() {
    Vector* vec = vector_create();

    // 尾部插入 10, 20, 30, 40, 50
    for (int i = 1; i <= 5; i++) {
        vector_push_back(vec, i * 10);
    }

    printf("元素个数: %zu, 容量: %zu\n", vector_size(vec), vector_capacity(vec));

    // 打印所有元素
    for (size_t i = 0; i < vector_size(vec); i++) {
        int val;
        vector_at(vec, i, &val);
        printf("%d ", val);
    }
    printf("\n");

    // 在索引2处插入99（0-based）
    vector_insert(vec, 2, 99);
    // 删除索引3的元素
    vector_erase(vec, 3);

    printf("插入/删除后: ");
    for (size_t i = 0; i < vector_size(vec); i++) {
        int val;
        vector_at(vec, i, &val);
        printf("%d ", val);
    }
    printf("\n");

    vector_destroy(vec);
    return 0;
}