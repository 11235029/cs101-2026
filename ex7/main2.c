#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Books
{
   int id;
   int price;
   char title[100];
} book_t;
// 計算所有書籍的總價
void total_price()
{
   FILE *fp;
   book_t book;
   int total = 0;
   fp = fopen("Book.bin", "rb");
   if (fp == NULL)
   {
       printf("Book.bin 開啟失敗！\n");
       return;
   }
   while (fread(&book, sizeof(book_t), 1, fp) == 1)
   {
       total += book.price;
   }
   printf("所有書籍的總價：%d\n", total);
   fclose(fp);
}
// 輸出所有書籍資料
void list_books()
{
   FILE *fp;
   book_t book;
   fp = fopen("Book.bin", "rb");
   if (fp == NULL)
   {
       printf("Book.bin 開啟失敗！\n");
       return;
   }
   printf("\n========== Book List ==========\n");
   printf("%-5s %-8s %s\n", "ID", "Price", "Title");
   while (fread(&book, sizeof(book_t), 1, fp) == 1)
   {
       printf("%-5d %-8d %s\n",
book.id, book.price, book.title);
   }
   fclose(fp);
}
int main()
{
   FILE *fp;
   book_t books[6] =
   {
       {1, 1000, "All the Light We Cannot See"},
       {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
       {3, 1000, "The Ballad of Songbirds and Snakes"},
       {4, 550, "Killers of the Flower Moon"},
       {5, 870, "Elon Musk"},
       {6, 1344, "Milk and Honey 12-Month 2024"}
   };
   int i;
   // 建立 Book.bin 並寫入書籍資料
   fp = fopen("Book.bin", "wb");
   if (fp == NULL)
   {
       printf("Book.bin 建立失敗！\n");
       return 0;
   }
   for (i = 0; i < 6; i++)
   {
       fwrite(&books[i], sizeof(book_t), 1, fp);
   }
   fclose(fp);
   // 計算總價
   total_price();
   // 列出書籍資料
   list_books();
   return 0;
}
