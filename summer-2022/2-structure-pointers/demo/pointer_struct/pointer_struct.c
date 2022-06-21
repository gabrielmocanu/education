#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char *title;
    char *author;
} Book;

int main() {

    Book *book_pointer;
    book_pointer = malloc(sizeof(Book));

    book_pointer->title = malloc(50 * sizeof(char));
    book_pointer->author = malloc(50 * sizeof(char));
}