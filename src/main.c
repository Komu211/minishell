#include "wrapper.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Comprehensive test for gc_malloc
void test_gc_malloc()
{
    printf("\n--- Testing gc_malloc ---\n");

    // Test standard allocation
    char *ptr1 = (char *)gc_malloc(10);
    if (ptr1 == NULL) {
        printf(RED "gc_malloc failed: Unable to allocate memory\n" RESET);
        return;
    }
    strcpy(ptr1, "test");
    printf(GREEN "gc_malloc passed: Allocated memory and copied string: %s\n" RESET, ptr1);
    gc_free(ptr1);

    // Test zero-size allocation
    char *ptr2 = (char *)gc_malloc(0);
    if (ptr2 != NULL) {
        printf(GREEN "gc_malloc passed: Zero-size allocation returned non-NULL\n" RESET);
        gc_free(ptr2);
    } else {
        printf(RED "gc_malloc failed: Zero-size allocation returned NULL\n" RESET);
    }

    // Test large allocation
    char *ptr3 = (char *)gc_malloc(1024 * 1024 * 10);  // 10MB
    if (ptr3 == NULL) {
        printf(RED "gc_malloc failed: Large memory allocation\n" RESET);
    } else {
        printf(GREEN "gc_malloc passed: Large memory allocation successful\n" RESET);
        gc_free(ptr3);
    }
}

// Comprehensive test for gc_calloc
void test_gc_calloc()
{
    printf("\n--- Testing gc_calloc ---\n");

    // Test standard zero initialization
    int *ptr1 = (int *)gc_calloc(5, sizeof(int));
    if (ptr1 == NULL) {
        printf(RED "gc_calloc failed: Unable to allocate memory\n" RESET);
        return;
    }

    // Check if all elements are zero
    int all_zero = 1;
    for (int i = 0; i < 5; i++) {
        if (ptr1[i] != 0) {
            all_zero = 0;
            break;
        }
    }

    if (all_zero) {
        printf(GREEN "gc_calloc passed: All elements initialized to zero\n" RESET);
    } else {
        printf(RED "gc_calloc failed: Not all elements are zero\n" RESET);
    }
    gc_free(ptr1);

    // Test zero-count allocation
    int *ptr2 = (int *)gc_calloc(0, sizeof(int));
    if (ptr2 != NULL) {
        printf(GREEN "gc_calloc passed: Zero-count allocation returned non-NULL\n" RESET);
        gc_free(ptr2);
    } else {
        printf(RED "gc_calloc failed: Zero-count allocation returned NULL\n" RESET);
    }

    // Test large allocation
    size_t *ptr3 = (size_t *)gc_calloc(1024 * 10, sizeof(size_t));  // Large array
    if (ptr3 == NULL) {
        printf(RED "gc_calloc failed: Large memory allocation\n" RESET);
    } else {
        int large_all_zero = 1;
        for (size_t i = 0; i < 1024 * 10; i++) {
            if (ptr3[i] != 0) {
                large_all_zero = 0;
                break;
            }
        }

        if (large_all_zero) {
            printf(GREEN "gc_calloc passed: Large allocation initialized to zero\n" RESET);
        } else {
            printf(RED "gc_calloc failed: Large allocation not fully zeroed\n" RESET);
        }
        gc_free(ptr3);
    }
}

// Comprehensive test for gc_realloc
void test_gc_realloc()
{
    printf("\n--- Testing gc_realloc ---\n");

    // Test standard reallocation
    char *ptr1 = (char *)gc_malloc(10);
    if (ptr1 == NULL) {
        printf(RED "gc_realloc failed: Initial allocation\n" RESET);
        return;
    }

    strcpy(ptr1, "test");
    char *ptr2 = (char *)gc_realloc(ptr1, 20);
    if (ptr2 == NULL) {
        printf(RED "gc_realloc failed: Unable to reallocate memory\n" RESET);
        gc_free(ptr1);
        return;
    }

    strcat(ptr2, " realloc");
    if (strcmp(ptr2, "test realloc") == 0) {
        printf(GREEN "gc_realloc passed: Memory content preserved\n" RESET);
    } else {
        printf(RED "gc_realloc failed: Memory content altered unexpectedly\n" RESET);
    }
    gc_free(ptr2);

    // Test realloc to zero size
    char *ptr3 = (char *)gc_malloc(10);
    char *ptr4 = (char *)gc_realloc(ptr3, 0);
    if (ptr4 == NULL) {
        printf(GREEN "gc_realloc passed: Realloc to zero size returned NULL\n" RESET);
    } else {
        printf(RED "gc_realloc failed: Realloc to zero size did not return NULL\n" RESET);
    }

    // Test reallocation of NULL pointer (should behave like malloc)
    char *ptr5 = (char *)gc_realloc(NULL, 15);
    if (ptr5 != NULL) {
        printf(GREEN "gc_realloc passed: Realloc with NULL pointer works\n" RESET);
        gc_free(ptr5);
    } else {
        printf(RED "gc_realloc failed: Realloc with NULL pointer returned NULL\n" RESET);
    }
}

// Comprehensive test for gc_free
void test_gc_free()
{
    printf("\n--- Testing gc_free ---\n");

    // Test standard free
    char *ptr1 = (char *)gc_malloc(10);
    if (ptr1 == NULL) {
        printf(RED "gc_free failed: Initial allocation\n" RESET);
        return;
    }
    gc_free(ptr1);
    printf(GREEN "gc_free passed: Standard memory free\n" RESET);

    // Test free of NULL pointer
    gc_free(NULL);
    printf(GREEN "gc_free passed: NULL pointer free\n" RESET);

    // Potential double-free test (behavior depends on implementation)
    char *ptr2 = (char *)gc_malloc(10);
    if (ptr2 != NULL) {
        gc_free(ptr2);
        // Uncomment with caution - this might crash if implementation doesn't handle double-free
        gc_free(ptr2);
    }
}

int main()
{
    test_gc_malloc();
    test_gc_calloc();
    test_gc_realloc();
    test_gc_free();

    printf("\n--- All Tests Completed ---\n");
    return 0;
}
