void dynamic_array()
{
    //freopen("in/dynamic_array_00.txt", "r", stdin);

    int cnt_shelves;
    scanf("%d", &cnt_shelves);

    // This stores the total number of books in each shelf.
    int* books = (int*)malloc(cnt_shelves * sizeof (int));

    // This stores the total number of pages in each book of each shelf.
    // The rows represent the shelves and the columns represent the books.
    int** pages = (int **)malloc(cnt_shelves * sizeof (int *));

    for (int i = 0; i < cnt_shelves; i++)
    {
        books[i] = 0;
        //*(books + i) = 0;

        pages[i] = (int*)malloc(sizeof(int));
        //*(pages + i) = (int*)malloc(sizeof(int));
    }

    int cnt_queries;
    scanf("%d", &cnt_queries);

    while (cnt_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        // Insert a book with y pages at the end of the x(th) shelf
        if (type_of_query == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            books[x] += 1;
            //*(books + x) = *(books + x) + 1;

            pages[x] = (int*)realloc(pages[x], books[x] * sizeof(int));
            //*(pages + x) = (int*)realloc(*(pages + x), *(books + x) * sizeof(int));

            pages[x][books[x] - 1] = y;
            //*(*(pages + x) + *(books + x) - 1) = y;

        }
        else if (type_of_query == 2)  // Print the number of pages in the y(th) book on the x(th) shelf
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(pages + x) + y));
        }
        else // Print the number of books on the x(th) shelf.
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(books + x));
        }
    }

    if (books)
        free(books);

    for (int i = 0; i < cnt_shelves; i++)
    {
        if (*(pages + i))
            free(*(pages + i));
    }

    if (pages)
        free(pages);
}
