// Copyright [2023] Muhammad Faizan
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1 and set its single component to zero... the
   right way */
vector_t *vector_new() {
    /* Declare what this function will return */
    /* First, we need to allocate memory on the heap for the struct */
    vector_t* new_vector = (vector_t*) malloc(sizeof(struct vector_t));
    /* Check our return value to make sure we got memory */
    if (new_vector == NULL) {
        allocation_failed("Failed to allocate memory for vector struct");
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    new_vector->size = 1;
    new_vector->data = (int *)calloc(new_vector->size, sizeof(int));
     /* Check the data attribute of our vector to make sure we got memory */
    if (new_vector->data == NULL) {
      free(new_vector);   // Freeing the vector struct memory before exit as it won't be used
      allocation_failed("Failed to allocate memory for vector data");
    }

    /* Complete the initialization by setting the single component to zero */
    new_vector->data[0] = 0;
    /* and return... */
    return new_vector;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {
     /* If we are passed a NULL pointer for our vector, complain about it and exit. */
      /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (v == NULL || loc >= v->size) {
        return 0;
    }
    return v->data[loc];
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    if (v == NULL) {
        return;
    }
    free(v->data);    // freeing up the memory allocated for data
    free(v);    // freeing up the memory allocated for the vector
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
     /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */
    if (v == NULL) {
        allocation_failed("Passed a NULL vector to vector_set");
    }
    // if loc >= allocated location v->size, we will realloc the size
    if (loc >= v->size) {
       size_t  new_size = loc * 2;   // Allocate double the current size for efficiency
       // allocating space for the new mem size
       int *new_data = (int*)realloc(v->data, new_size * sizeof(int));
       // check for memory allocation
       if (new_data == NULL) {
           allocation_failed("Failed to reallocate memory in vector_set");
       }
       // set new memory to zero
       memset(new_data + v->size, 0, (new_size - v->size) * sizeof(int));
       v->data  = new_data;
       v->size  = new_size;
    }
    // else we will simply set the data at the desired location
    v->data[loc] = value;
}
