#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>

int main()
{
    char folder[] = "/home/tamtam/modul3/playlist";
    DIR *dir = opendir (folder);
    size_t n = 0;
    int i;
    char lagu[100][100];

    printf("Playlist :\n");
    struct dirent *ent;
    while ((ent = readdir (dir)))
    {
        if (strstr (ent->d_name, "mp3"))
        {
            printf ("%ld. %s\n", n+1, ent->d_name);
            strcpy(lagu[n], ent->d_name);
            ++n;
        }
    }
    printf("Which one you want to play? ");
    scanf("%d", &i);
    char buf[64];
    sprintf(buf, "play -q /home/tamtam/modul3/playlist/%s", lagu[i-1]);
    system(buf);
}
