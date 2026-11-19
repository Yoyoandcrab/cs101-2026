#include <stdio.h>
#include <string.h>

typedef struct Books
{
    int Id;
    int Price;
    char Title[100];
} book_t;

int total_price(book_t books[], int n)
{
    int total = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += books[i].Price;
    }

    return total;
}

void list_books(book_t books[], int n)
{
    int i;

    printf("\n========== Book List ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("ID: %d\n", books[i].Id);
        printf("Price: %d\n", books[i].Price);
        printf("Title: %s\n", books[i].Title);
        printf("------------------------------\n");
    }
}

int main()
{
    book_t books[6] =
    {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int n = 6;
    int total;
    FILE *fp;

    fp = fopen("Book.bin", "wb");

    if (fp == NULL)
    {
        printf("File open failed!\n");
        return 1;
    }

    fwrite(books, sizeof(book_t), n, fp);

    fclose(fp);

    total = total_price(books, n);

    printf("Total Price: %d\n", total);

    list_books(books, n);

    return 0;
}
