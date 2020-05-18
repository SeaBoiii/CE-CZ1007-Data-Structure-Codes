#include <stdio.h>
#define SIZE 20
typedef struct {
    char title[80];
    char lastname[81];
    char firstname[81];
    char publisher[81];
    int day, month, year;
} Booktype;

void readBook(Booktype *book)
{
    printf("Enter the title of the book: \n");
    scanf("\n");
    gets(book->title);

    printf("Enter the author's first name: \n");
    scanf("\n");
    gets(book->firstname);

    printf("Enter the author's last name: \n");
    scanf("\n");
    gets(book[0].lastname);

    printf("Enter date as (dd-mm-yy): \n");
    scanf("\n");
    scanf("%d-%d-%d", &book[0].day, &book[0].month, &book[0].year);

    printf("Enter the publisher name: \n");
    scanf("\n");
    gets(book[0].publisher);
}

void printBook(Booktype book)
{
    printf("Title: %s\n", book.title);
    printf("Author: %s %s\n", book.firstname, book.lastname);
    printf("Date: %d-%d-%d\n", book.day, book.month, book.year);
    printf("Publisher: %s\n", book.publisher);
}

int main()
{
    Booktype book[SIZE];
    char repeat = 'y';
    int size=0;

    do {
        readBook(&book[size]);
        printf("The book information:\n");
        printBook(book[size]);
        printf("Continue ('y' or 'n'): \n");
        scanf("%c", &repeat);
        size++;
    } while (repeat == 'y');
    return 0;
}
