/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Hanuman Sai Chanukya Srinivas Chilamkuri

Hours to complete assignment: ~10

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

In this assignment, I have to write a code for plotting a Triangle 
Fractal. I have to complete this code by calling the recurive 
function. This program should take two command line arguments for 
the length of triangle and depth of recursion. I used some mathematics to
write this code and then used a function to recursively draw the triangles
to the screen.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

I used frames to get an animated output with random colors.

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

In previous code, I didn't used frames for animation. And also I changed 
a lot to get animated output. To get the sub-triangles in correct position, 
I used linked list for three of the sub-triangles. Then it easily drew all 
the other child triangles to the three main base triangles.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 Use the following command to get output exactly as shown in my folder
 <./TFractal 100 6>
 
 In this code, I accomplished
 
 1. recursive implementation of triangle fractal
 2. I included the makefile
 3. My code is passing cpplint
 4. I added color to my tree
 5. My code is showing output with animation
