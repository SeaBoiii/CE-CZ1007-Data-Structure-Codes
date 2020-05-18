#include <stdio.h>
int rAge(int studRank)
{
    if (studRank == 1)
        return 10;
    else
        return 2 + rAge(studRank-1);
}

int main()
{
    int studRank;

    printf("Enter student rank: \n");
    scanf("%d", &studRank);
    printf("rAge(): %d\n", rAge(studRank));
    return 0;
}
