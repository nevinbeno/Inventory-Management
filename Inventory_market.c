#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ITEMS 5 // total no. of pre-defined, distinct items
#define MINIMUM 20    // minimum setted for signaling

typedef struct items
{
    int item_code;
    int quantity;
    char name[20];
} items;

items ITEM_LIST[TOTAL_ITEMS] = {{22, 50, "Soap"},
                                {25, 100, "Blade"},
                                {40, 90, "Candles"},
                                {99, 200, "Books"},
                                {50, 70, "pop"}};

void store(items *ITEM_LIST,int total)
{
    FILE *data=fopen("Inventory_market_Product_analysis.txt","w");

    if(data==NULL)
    {
        printf("ERROR ! File couldn't be created..");
        return;
    }
    fprintf(data,"%-20s%-20s%-20s\n","Item Code","Name","Remaining Qty");
    for(int i=0;i<total;i++)
    {
        fprintf(data,"%-20d%-20s%-20d\n",ITEM_LIST[i].item_code,ITEM_LIST[i].name,ITEM_LIST[i].quantity);
    }
    fclose(data);
    printf("\nThe product info is updated in the text file, please go through it.");
}

void calculate(items *ITEM_LIST, int *arr1, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < TOTAL_ITEMS; j++)
        {
            if (arr1[i] == ITEM_LIST[j].item_code) // matching..
            {
                ITEM_LIST[j].quantity -= arr2[i];
                break;
            }
        }
    }
}

void alarm(items *ITEM_LIST, int total)
{
    for (int i = 0; i < total; i++)

    {
        if (ITEM_LIST[i].quantity < MINIMUM)
        {
            printf("\nALERT ! %s is running out of stock !\nRemaining stock : %d\n", ITEM_LIST[i].name, ITEM_LIST[i].quantity);
        }
    }
}

void master_mind()
{
    int num;
    printf("Enter the number of distinct items purchased (maximum %d): ",TOTAL_ITEMS);
    scanf("%d", &num);

    int *list = (int *)malloc(sizeof(int) * num);
    int *qty = (int *)malloc(sizeof(int) * num);

    if (list == NULL || qty == NULL) // if pointer == NULL
    {
        printf("\nERROR !The memory space could not be allocated. ");
        free(list);
        free(qty);
        return;
    }

    if (num <= 0 || num > TOTAL_ITEMS) // error handling
    {
        printf("\nERROR ! Please re-check the entered value.");
        free(list);
        free(qty);
        return; // the program terminates..
    }
    else
    {
        // displaying the items and code number
        printf("\nTO DETERMINE THE STOCK !\n\n");
        printf("%-20s%-20s\n", "Item code", "Item name"); // table format
        for (int i = 0; i < TOTAL_ITEMS; i++)
        {
            printf("%-20d%-20s\n", ITEM_LIST[i].item_code, ITEM_LIST[i].name);
        }

        for (int i = 0; i < num; i++) // getting data
        {
            printf("\nEnter the ITEM CODE of the product %d purchased (type and hit Enter) : ", i + 1);
            scanf("%d", &list[i]); // item
            int found = 0;
            for (int j = 0; j < TOTAL_ITEMS; j++) // validating item code..
            {
                if (list[i] == ITEM_LIST[j].item_code)
                {
                    found = 1;
                    printf("\nEnter the quantity of this item purchased (type and hit Enter)\n(Remaining stock is only  %d) : ",ITEM_LIST[j].quantity);
                    scanf("%d", &qty[i]);                              // quantity
                    if (qty[i] <= 0 || qty[i] > ITEM_LIST[j].quantity) // validating qty
                    {
                        printf("\nERROR !! Please re-check the 'quantity' you've entered..\n");
                        free(list);
                        free(qty);
                        return;
                    }
                    break; // match found, and qty is within the allowed area, hence run the remaining part..
                }
            }
            if (found == 0)
            {
                printf("\nERROR !! Please re-check the item code you've entered..\n");
                free(list);
                free(qty);
                return;
            }
        }
    }
    calculate(ITEM_LIST, list, qty, num);
    alarm(ITEM_LIST, TOTAL_ITEMS);

    store(ITEM_LIST,TOTAL_ITEMS);
    
    free(list);
    free(qty);

}
int main()
{
    int n = 0;
    do
    {
        master_mind();
        printf("\nEnter 1 to exit, or any other number to continue: ");//the program continues till the manager press '1'
        scanf("%d", &n);
    }while (n != 1);
    printf("\nThe program ends\n");
    return 0;
}//THANK YOU !