#include <stdio.h>
#include <stdlib.h>
/*
Write a function to create a dynamic array of integers. 
The function should take the size of the array 
as an argument and return a pointer to the dynamically allocated memory.
*/
int * dyn_array;
int dyn_size;
int amount_elements;

int * createArray(int size)
{
    //Set amount of elements to 0
    amount_elements = 0;
    //Set new size of array
    dyn_size = size;
    //Dynamically allocate memory by using size and int
    dyn_array = (int*)calloc(size, sizeof(int));

    //Check if array has been allocated succesfully
    if(dyn_array == NULL)
    {
        printf("Array could not be allocated.\n");
    }
    else
    {
        printf("New Array allocatd successfully.\n");
    }
    return dyn_array;
}
/*
Write a function to insert an element at a specified position in the array. 
Ensure that the array size is dynamically adjusted to accommodate the new element.
*/
void insert(int element, int position)
{
    //Check if the amount of the elements is bigger than current size of the array
    if(amount_elements >= dyn_size)
    {
        //Save the current pointer and size to the array
        int * curr_array = dyn_array;
        int  curr_size = dyn_size;
        //Create an array with a size of ten more elements than the last one
        int * new_array = createArray(curr_size + 10);
        //Copy the elements of the old array to the new array
        for (int i = 0; i< curr_size; i++)
        {
            new_array[i] = curr_array[i];
        }
        //Free the memory of the last array
        free(curr_array);
        printf("New array has been created and elements have been moved\n");
    }
    //set the element at the specified position
    dyn_array[position] = element;
    amount_elements++;
    printf("New elements have been added\n");
}

/*
Write a function to delete an element from a specified position in the array. 
Ensure that the array size is adjusted accordingly.
*/
void delete(int position)
{
    if (amount_elements <= 0)
    {
        printf("It is not possible to delete any elements. Array is empty.\n");
        return;
    }
    //Set number of element to 0
    dyn_array[position] = 0;
    //removed one element from counter
    amount_elements--;
    printf("Removed array at position %d successfully\n", position);
}
/*
Write a function to display the elements of the dynamic array.
*/
void display()
{
    //Loop through all elements - 1 and print them  
    for (int i = 0; i < dyn_size-1; i++)
    {
        printf("%d,", dyn_array[i]);
    }
    //print last element without seperator and line break
    printf("%d\n",dyn_array[dyn_size-1]);
}

int main()
{

    /*
    Create a menu-driven program that allows the user to perform 
    these operations interactively until they choose to exit.
    */
    int menu = 0;
    int exit = 9;
    //The menu displays your options and reads input 
    //from user then reacts on input based from user.
    while(menu != exit)
    {
        printf("Press 1 to create an array with specific size\n");
        printf("Press 2 to insert an element at a position\n");
        printf("Press 3 to delete an element at a position\n");
        printf("Press 4 to display the array\n");
        printf("Press 9 to exit the menu and close the program\n");
        printf("Your input: ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            int createSize = 0;
            printf("Give the size of the array to create:\n");
            scanf("%d", &createSize);
            createArray(createSize);
            break;
        case 2:
            int element, position = 0;
            printf("Give the element to add:\n");
            scanf("%d", &element);
            printf("Give the position to be inserted\n");
            scanf("%d", &position);
            insert(element, position);
            break;
        case 3:
            int deletePos = 0;
            printf("Give the position of the element to delete:\n");
            scanf("%d", &deletePos);
            delete(deletePos);
            break;
        case 4:
            display();
            break;
        case 9:
            return 0;
        default:
            break;
        }
    }
}