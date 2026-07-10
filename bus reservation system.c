#include <stdio.h>
#include <string.h>

struct Bus
{
    int busNo;
    char driver[50];
    char arrival[20];
    char departure[20];
    char from[30];
    char to[30];
    int seats[32];
};

struct Bus bus[5];

void installBus();
void reservation();
void show();
void available();

int main()
{
    int choice;

    installBus();

    while (1)
    {
        printf("\n====================================");
        printf("\n      BUS RESERVATION SYSTEM");
        printf("\n====================================");
        printf("\n1. Available Buses");
        printf("\n2. Reserve Seat");
        printf("\n3. Show Bus Details");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            available();
            break;

        case 2:
            reservation();
            break;

        case 3:
            show();
            break;

        case 4:
            printf("\nThank You!\n");
            return 0;

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void installBus()
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        printf("\nEnter Bus No: ");
        scanf("%d", &bus[i].busNo);

        printf("Driver Name: ");
        scanf("%s", bus[i].driver);

        printf("Arrival Time: ");
        scanf("%s", bus[i].arrival);

        printf("Departure Time: ");
        scanf("%s", bus[i].departure);

        printf("From: ");
        scanf("%s", bus[i].from);

        printf("To: ");
        scanf("%s", bus[i].to);

        for (j = 0; j < 32; j++)
        {
            bus[i].seats[j] = 0;
        }
    }
}

void available()
{
    int i;

    printf("\nAvailable Buses:\n");
    printf("\nBus No\tFrom\tTo\tArrival\tDeparture");

    for (i = 0; i < 2; i++)
    {
        printf("\n%d\t%s\t%s\t%s\t%s",
               bus[i].busNo,
               bus[i].from,
               bus[i].to,
               bus[i].arrival,
               bus[i].departure);
    }

    printf("\n");
}

void reservation()
{
    int busNo, seatNo, i;

    printf("\nEnter Bus Number: ");
    scanf("%d", &busNo);

    for (i = 0; i < 2; i++)
    {
        if (bus[i].busNo == busNo)
        {
            printf("Enter Seat Number (1-32): ");
            scanf("%d", &seatNo);

            if (seatNo < 1 || seatNo > 32)
            {
                printf("\nInvalid Seat Number!\n");
                return;
            }

            if (bus[i].seats[seatNo - 1] == 0)
            {
                bus[i].seats[seatNo - 1] = 1;
                printf("\nSeat Reserved Successfully!\n");
            }
            else
            {
                printf("\nSeat Already Reserved!\n");
            }

            return;
        }
    }

    printf("\nBus Not Found!\n");
}

void show()
{
    int busNo, i, j;

    printf("\nEnter Bus Number: ");
    scanf("%d", &busNo);

    for (i = 0; i < 2; i++)
    {
        if (bus[i].busNo == busNo)
        {
            printf("\nBus Number: %d", bus[i].busNo);
            printf("\nDriver Name: %s", bus[i].driver);
            printf("\nArrival Time: %s", bus[i].arrival);
            printf("\nDeparture Time: %s", bus[i].departure);
            printf("\nFrom: %s", bus[i].from);
            printf("\nTo: %s", bus[i].to);

            printf("\n\nSeat Status:\n");

            for (j = 0; j < 32; j++)
            {
                if (bus[i].seats[j] == 0)
                    printf("%d Empty\t", j + 1);
                else
                    printf("%d Reserved\t", j + 1);

                if ((j + 1) % 4 == 0)
                    printf("\n");
            }

            return;
        }
    }

    printf("\nBus Not Found!\n");
}