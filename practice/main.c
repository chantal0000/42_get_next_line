#include <stdio.h>

int main()
{
        FILE *ptr;
        char content[1000];

        ptr = fopen("test1.txt", "r");
        if (ptr != NULL)
        {
            while(fgets(content, 1000, ptr))
            {
                printf("%s", content);
            }
        }
        else
            printf("unsuccessful");
        fclose(ptr);
        return (0);
}
