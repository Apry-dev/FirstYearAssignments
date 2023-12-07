/*Bank pin program
Version Numb: 1
Description: A program to enter and check a pin(It does this by comparing two variables against each other and if they're the same it allows the user to continue), Change the pin,
Display wrong attempts, Exit the program
Date Created: 01/11/2022
Due Date: 20/11/2022
Author Andrew Carty
Student number: C22488994*/
#include <stdio.h>

int main()
{
    int opt, PinEntered, PinOriginal, PinNew, PinVerified, w, r, exit;
    opt = 0;
    PinNew, PinVerified = 0;
    PinEntered = 0;
    PinOriginal = 1234;
    w = 0;
    r = 0;
    exit = 0;
    while (exit==0){
        printf("Please select the option you want to use\n[1] Enter/Verify Pin\n[2] Change Pin\n[3] Display Wrong Attempts\n[4] Exit program\nEnter input here:");
        scanf("%d", &opt);

        while (getchar() != '\n') { //eliminating white space (if the character entered is not the enter button, continue)
            continue;
        }

        
        //switch statement based on input
        switch(opt)
        {
            case 1://Pin checker
            {
            printf("You have selected %d\nEnter pin here:", opt);  
                scanf("%d", &PinEntered);
                if (PinEntered == PinOriginal)
                {
                    printf("This is the correct pin\n"); // if the pin is right it adds one to right attempts
                        r++;
                }
                else //if the pin is wrong. Adds 1 to wrong attempts
                {
                    printf("This is the incorrect pin. Please try again\n\n");
                     w++;
                }
            break;
            }


            case 2: //Password Changer
            {
            printf("You have selected to change your password. Password must be 4 characters long and only contain numbers Please enter new password: \n" );
                scanf("%d", &PinNew);
            printf("Please re-enter your password to verify\n");
                scanf("%d", &PinVerified);
            if (PinNew == PinVerified) //Makes sure the pin you changed is correct by checking against the verified pin
            {
                
                printf("Password Successfully Change\n\n"); //changes the original pin to the new pin 
                PinOriginal = PinNew;
                
            }
            else //Wrong Pin
            {
                printf("Could not verify password please try again\n");
            }
            break;
            }


            case 3: //displays wrong attempts
            {
                printf("you have selected option 3  to view wrong attempts\n" );
                printf("the number of wrong attempts is  %d\n\n", w);
                printf("The number of wrong attempts is %d\n",r);
            break;
            }

            case 4:
            {
                printf("you have selected option 4 to exit the program\n\n" ); // makes exit equal to one therefore breaking the while loop the whole program is in thus ending the program
                exit = 1;
            break;
            }

            default:
            {
                printf("not valid input\n");
            break;
            }
            
        }
    }
 return 0;
} //end main
