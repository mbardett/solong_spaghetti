# solong_spaghetti

An improved version of the SoLong project, necessary to enroll in the selection process for joining SpaghettiStudio, a club made and run by 42 students to develop videogames;
My version of SoLong had very simple textures I decided to redraw all of them(they are still very simple but definetly better than before).
And since I wanted to implement a GUI I also drawed some additional textures for the Icons, Inventory and a Text Box;
Basically the game takes a valid map, defines a new matrix with all the GUI elements before loading the window and then prints the entire new matrix.
I then implemented the mouse (left)click, so that if it is pressed one the same coordinates of the Save Icon then the save function is called: 
if a "saves" doesn't exist it is created and then all the data from the level are stored in there, currently allowing a limited number of saves.
Now it is possible to load a saved file and the program will skip the required checks for the .ber file.
There are still many improvements I want to add and hopefully I'll manage to spare some time to do it in the future.
