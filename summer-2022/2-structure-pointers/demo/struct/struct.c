#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char *title;
    char *author;
} Book;

int main() {

    Book book;

    book.title = malloc(50 * sizeof(char));
    book.author = malloc(50 * sizeof(char));

}