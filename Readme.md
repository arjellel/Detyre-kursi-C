This C program implements a simple management system for doctors in a clinic. It allows an administrator to manage doctor records by adding, deleting, modifying, and viewing doctor details. The system provides a menu-driven interface for administrators, and a placeholder for a menu for doctors (though it is not implemented yet).

Features of the Program
Administrator Menu:

Add a new doctor (shtoni_mjek).
Delete a doctor by ID (fshini_mjek).
Modify existing doctor details (ndryshoni_te_dhenat_mjek).
Display all doctors (printo_mjeket).
Search for a doctor by specialization (mjek_sipas_specializimit).
Placeholder for patient-related operations (not yet implemented).
Doctor Data Management:

The program stores doctor data in an array of structures (struct Mjek).
Each doctor has an ID, a name, and a specialization.
Sample doctor data is preloaded for testing.
User Input Handling:

Uses functions to take input for doctor details (inputM_all).
Uses dynamic input handling for strings.
Uses a loop to allow multiple operations until the user exits.
Search and Modify Operations:

Searching by ID when deleting or modifying a doctor's data.
Searching by specialization when looking up doctors.
Potential Issues in the Code
Comparison of Strings:
The function mjek_sipas_specializimit uses if(mjek.specializimi == input), which does not work for string comparison in C. Instead, strcmp(mjek.specializimi, input) == 0 should be used.
Array Bound Checking:
The program assumes a fixed size of 100 doctors but does not check for out-of-bounds access in some cases.
Memory Management:
The program does not dynamically allocate memory, so the number of doctors is limited to a predefined array size.
