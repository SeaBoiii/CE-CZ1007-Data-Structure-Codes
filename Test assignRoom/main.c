#include <stdio.h>
#define MAX 5
#define TAKEN 1
#define EMPTY 0
typedef struct
{
   int roomID;
   int status;
   char customerName[20];
} Room;
void listOccupiedRooms(Room hotel[]);
void assignRoom(Room hotel[]);
int main()
{
   Room hotel[MAX];
   int choice, i;

   for (i=0; i<MAX; i++)
      hotel[i].status = EMPTY;

   printf("A HOTEL ROOM RESERVATION PROGRAM: \n");
   printf("1: listOccupiedRooms() \n");
   printf("2: assignRoom() \n");
   printf("3: quit\n");
   do {
      printf("Enter your choice:\n");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            printf("listOccupiedRooms(): \n");
            listOccupiedRooms(hotel);
            break;
         case 2:
            assignRoom(hotel);
            break;
         default:
            break;
      }
   } while (choice<3);
   return 0;
}
void listOccupiedRooms(Room hotel[])
{
   int i,j, emptylist=0;
   Room temp;
   for (i=0; i<MAX; i++)
   {
       for (j=0; j<MAX; j++)
       {
           if (hotel[i].roomID < hotel[j].roomID)
           {
               temp = hotel[j];
               hotel[j] = hotel[i];
               hotel[i] = temp;
           }
       }
   }

   for (i=0; i<MAX; i++) {
      if (hotel[i].status == TAKEN){
         printf("roomID: ");
         printf("%d\n", hotel[i].roomID);
         printf("customerName: ");
         printf("%s\n", hotel[i].customerName);
         emptylist=1;
      }
   }
   if (emptylist == 0)
      printf("The hotel is empty\n");
}
void assignRoom(Room hotel[])
{
    int i=0,k;
    while (hotel[i].status == TAKEN)
    {
        i++;
    }
    if (i == 5)
    {
        printf("The hotel is full\n");
        return;
    }
    //printf("%d\n",i);
    do
    {
        printf("Enter a roomID between 1 and 5:\n");
        scanf("%d", &hotel[i].roomID);
        for (k=0; k<i; k++)
        {
            if (hotel[k].roomID == hotel[i].roomID)
            {
            printf("Occupied! Enter another roomID\n");
            hotel[i].roomID = 0;
            break;
            }
        }
    } while (hotel[i].roomID > 5 || hotel[i].roomID < 1);
    printf("Enter customerName:\n");
    scanf("\n");
    gets(hotel[i].customerName);
    hotel[i].status = TAKEN;
    printf("The room has been assigned successfully\n");
}
