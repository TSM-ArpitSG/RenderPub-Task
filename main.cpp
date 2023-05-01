// Import necessary libraries
#include <iostream> 	// Provides input/output stream functionality
#include <stack> 		// Provides the stack data structure

using namespace std;	 // Use the standard namespace

int main() {

float x = 10.0; 		// Initialize variable x with value 10.0

stack<float> undoStack, redoStack; 	// Initialize two stacks for undo and redo operations

string input; 			// Initialize a string variable for user input

while (true) {			 // Begin infinite loop until user exits

    getline(cin, input); 	// Read input from user

    if (input.empty() || input == "\x1B") {  	// Exit on empty input or Escape key press

        break; 			// Exit loop and end program
    }

    else if (input == "x") {  	// If user inputs "x", print current value of x

        cout << x << endl; 	// Output value of x to console
    }

    else if (input == "z") { 	// If user inputs "z", undo previous operation

        if (!undoStack.empty()) {	 // Check if undo stack is not empty

            redoStack.push(x); 		// Push current value of x to redo stack

            x = undoStack.top();		// Set x to previous value from undo stack

            undoStack.pop(); 		// Remove previous value from undo stack
        }
    }

    else if (input == "y") {  		// If user inputs "y", redo previous undo operation

        if (!redoStack.empty()) { 	// Check if redo stack is not empty

            undoStack.push(x); 		// Push current value of x to undo stack

            x = redoStack.top();		// Set x to previous value from redo stack

            redoStack.pop(); 		// Remove previous value from redo stack
        }
    }
    else {  	// If user inputs an arithmetic operation, perform it on x and push to undo stack

        float value = stof(input.substr(1)); 	// Convert the numeric value in the input string to a float

        undoStack.push(x); 			// Push current value of x to undo stack

        switch (input[0]) { 	// Check the operation specified by the first character in the input string

            case '+':
                x += value; 	// Add the input value to x
                break;

            case '-':
                x -= value; 		// Subtract the input value from x
                break;

            case '*':
                x *= value; 		// Multiply x by the input value
                break;

            case '/':
                x /= value; 		// Divide x by the input value
                break;

            default: 	      // If the first character is not a valid operation, output an error message
                cout << "Invalid input." << endl;
                break;
        }

        while (!redoStack.empty()) {  		// Clear redo stack after new operation

            redoStack.pop(); 		// Pop values from the redo stack until it is empty
        }
    }
}
return 0; 	// End program
}

// code Written by @Arpit Singh - 19BCG10069
