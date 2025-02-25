#include <stdio.h>
#include <stdlib.h>

typedef struct vector_t {
    int size;
    int capacity; 
    int* array;
} vector_t;

vector_t* create() {
    vector_t* v = (vector_t*)malloc(sizeof(vector_t));
    v->size = 0; 
    v->capacity = 2;
    v->array = (int*)calloc(v->capacity, sizeof(int)); 
    
    return v;
}

void free_vector(vector_t* v) {
    free(v->array);
    free(v);
} 

void resize(vector_t* v) {
    v->capacity *= 2;
    v->array = (int*) realloc(v->array, v->capacity * sizeof(int)); 
}

void add(vector_t* v, int num) {
    if (v->size == v->capacity) {
        resize(v);
    }

    v->array[v->size++] = num;
}

int remove_back(vector_t* v) {
    return v->array[--v->size];
}

void print(vector_t* v) {
    printf("%d\n", v->size);
    printf("%d\n", v->capacity);
    
    for (int i = 0; i < v->size; i++) {
        if (i != v->size - 1) {
            printf("%d, ", v->array[i]);
        } else {
            printf("%d", v->array[i]);
        }
    }
    
    printf("\n");

}

int main()
{
    vector_t* vector = create(); 
    print(vector);
    
    add(vector, 10);
    add(vector, 20);
    add(vector, 30);
    
    print(vector);
    
    int a = remove_back(vector);
    printf("Removed: %d\n", a);
    print(vector);
    
    free_vector(vector);
    
    // print(vector);

    return 0;
}