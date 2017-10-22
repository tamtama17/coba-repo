#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int flag;

void *bacatos1()
{
     FILE *baca, *salin1;
     baca = fopen ("baca.txt", "r");
     salin1 = fopen ("salin1.txt", "w");

     char buffer[50];
     while (fgets (buffer, 50, baca))
         fprintf (salin1, "%s", buffer);

     fclose (baca);
     fclose (salin1);
     flag=1;
}

void *s1tos2()
{
     while(flag != 1){

     }

     FILE *salin1, *salin2;
     salin1 = fopen ("salin1.txt", "r");
     salin2 = fopen ("salin2.txt", "w");

     char buffer[50];
     while (fgets (buffer, 50, salin1))
         fprintf (salin2, "%s", buffer);

     fclose(salin1);
     fclose(salin2);
}

int main()
{
     pthread_t thread1, thread2;//inisialisasi awal
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, bacatos1, NULL);
     if(iret1)//jika eror
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, s1tos2, NULL);
     if(iret2)//jika gagal
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}
