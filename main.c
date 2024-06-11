#include <stdio.h>
#include <stdlib.h>
#include <dialog.h>
#include <unistd.h>


// Renaming structure to avoid the
// repetitive use of struct keyword
typedef struct ToDo todo;

// Declaration of structure
struct ToDo {
    // char array as data part
    char buffer[101];

    // Pointer part to access addresses
    todo* next;

    // Count variable for counting
    // the number of nodes
    int count;
};

// Declare start pointer as null in
// the beginning
todo* start = NULL;

void interface();
void seetodo();
void createtodo();
void deletetodo();
void adjustcount();


// Driver Code
int main()
{
    interface();
	
    char* choice;
    init_dialog(stdin, stdout);
    
    while (1) {


            char *modes[] =
    {
        "1", "To see your ToDo list",
        "2", "To create new ToDo",
        "3", "To delete your ToDo",
        "4", "Exit",

    };
    dlg_clr_result();
    init_dialog(stdin, stdout);
    dialog_menu("TO DO APP", "Choose an option.", 0, 0, 0, 4, modes);
    end_dialog();

        choice=dialog_vars.input_result;
        switch (*choice) {

        // Calling functions defined
        // below as per the user input
        case '1':
	seetodo();
            break;
            
        case '2':
	createtodo();
            break;
            
        case '3':
	//deletetodo();
            break;
            
        case '4':
        system("clear");
            exit(1);
	    
            break;
            
        default:
            printf("\nInvalid Choice :-(\n");

        }
    }
    system("clear");
    return 0;
}

// Code for Splash screen
void interface()
{
    init_dialog(stdin, stdout);
     dialog_msgbox(
                 "TO DO APP",
                 "By                                            SYITB251 Harsh Soni                                               SYITB268 Manav Gupta                                               SYITB269 Arya Raina                                               SYITB247 Rajat Shinde ",
                 10, 50,1);
    end_dialog();
}



// Function to insert a node todo
void createtodo()
{
    // Choose choice from user
    

    // Pointers to node
    todo *add, *temp;

    // Infinite loop which will
    // break if "n" is pressed
    while (1) {

        fflush(stdin);
        dlg_clr_result();
        init_dialog(stdin, stdout);
    int status=dialog_yesno(
                 "TO DO APP",
                 "Want to add new ToDo ?",
                 0, 0);
                 
    end_dialog();
	char c[10];
	//c=dialog_vars.input_result;
        // Input from user


        if (status)
            break;
        else {

            // If start node is NULL
            if (start == NULL) {

                // Dynamically allocating
                // memory to the newly
                // created node
                add = (todo*)calloc(1, sizeof(todo));

                // Using add pointer to
                // create linked list
                start = add;
                
                dlg_clr_result();
                init_dialog(stdin, stdout);
		   dialog_inputbox("TO DO APP", "Type it...",0,0,0,0);
	 	end_dialog();
                // Input from user
                fflush(stdin);
                //add->buffer=dialog_vars.input_result;
		strcpy(add->buffer,dialog_vars.input_result);
                // As first input so
                // count is 1
                add->count = 1;

                // As first node so
                // start's next is NULL
                start->next = NULL;
            }
            else {
                temp = (todo*)calloc(1, sizeof(todo));
                dlg_clr_result();
                init_dialog(stdin, stdout);
		   dialog_inputbox("TO DO APP", "Type it...",0,0,0,0);
	 	end_dialog();
                fflush(stdin);
                //temp->buffer=dialog_vars.input_result;
		strcpy(temp->buffer,dialog_vars.input_result);
                // Insertion is at last
                // so pointer part is NULL
                temp->next = NULL;

                // add is now pointing
                // newly created node
                add->next = temp;
                add = add->next;
            }

            // Using the concept of
            // insertion at the end,
            // adding a todo

            // Calling function to adjust
            // the count variable
            adjustcount();
        }
    }
}



// Function to adjust the numbering
// of the nodes
void adjustcount()
{
    // For traversal, using
    // a node pointer
    todo* temp;
    int i = 1;
    temp = start;

    // Running loop until last node
    // and numbering it one by one
    while (temp != NULL) {
        temp->count = i;
        i++;
        temp = temp->next;
    }
}

void seetodo()
{
    // Clearing the console


    // Pointer to the node for traversal
    todo* temp;

    // temp is made to point the
    // start of linked list
    temp = start;

    // Condition for empty linked list
    if (start == NULL)
        printf("\n\nEmpty ToDo \n\n");

    // Traverse until last node
            char arr[4][20];
    int i=0;
    while (temp != NULL) {

        // Print number of the node
        //arr[i]=temp->count;
        strcpy(arr[i][20],temp->count);
        //printf("%d.)", temp->count);
	i++;
        // Print data of the node
        //arr[i]=temp->buffer;
	strcpy(arr[i][20],temp->count);
        // Clear output console
        fflush(stdin);

        // Going to next node
        temp = temp->next;
        i++;
    }
     init_dialog(stdin, stdout);
     dialog_checklist("TO DO APP", "Your Tasks are", 0, 0,0, i, arr,0);
     end_dialog();
    system("clear");
}

