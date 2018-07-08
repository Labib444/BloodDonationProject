#include "iGraphics.h"
#include "bitmap_loader.h"
#include "myVariables.h"


/*
 function iDraw() is called again and again by the system.
 */


void showLoadingPage(){
	loadImage = 1;
}


void mainMenuPageSetup(){

	if(loadImage != 0)
		iPauseTimer(t);

	switch(loadImage){
		case 0:
			iShowImage(0, 0, 1000, 800, loadingImage);
			break;
		case 1:
			iShowImage(0, 0, 1000, 800, menu);
			break;
		case 2:
			iShowImage(0, 0, 1000, 800, donateBlood); //hovering donate button right
			break;
		case 3:
			iShowImage(0, 0, 1000, 800, findDonor); // hovering find button down
			break;
		case 4:
			iShowImage(0, 0, 1000, 800, donateButton); // hovering donate button left
			break;
	}
}

void findBloodPageSetup(){

	switch(loadImage){
		case 5:
			iShowImage(0, 0, 1000, 800, blank); // hovering donate button left
			iShowImage(650, 0, 450, 280, backButton); 
			break;
		case 6:
			iShowImage(0, 0, 1000, 800, blank); // hovering donate button left
			iShowImage(650, 0, 450, 280, backButton); 
			break;
		case 7:
			iShowImage(0, 0, 1000, 800, blank); // hovering donate button left
			iShowImage(650, 0, 450, 280, backButton); 
			break;
	}
}


void iDraw()
{
	//place your drawing codes here
	iClear();
	
	if(anotherPage == 1){
		findBloodPageSetup();
	}else{
		mainMenuPageSetup();
	}
	
}

void iPassiveMouse(int mx, int my)
{	
	printf("x:%d y:%d\n",mx,my);

	if(anotherPage == 0){ // if anotherPage is 1 then the hover won't take place
		if( (mx >= 618 && mx <= 930) && (my >= 438 && my <= 700) ){
			loadImage = 2;
		}else if( (mx >= 65 && mx <= 930) && (my >= 42 && my <= 357) ){
			loadImage = 3;
		}else if( (mx >= 65 && mx <= 593) && (my >= 439 && my <= 700) ){
			loadImage = 4;
		}
		else{
			loadImage = 1;
		}
	}

	



}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if( (mx >= 618 && mx <= 930) && (my >= 438 && my <= 700) ){
			anotherPage = 1; //need to change later
			loadImage = 6;
		}
		if( (mx >= 65 && mx <= 593) && (my >= 439 && my <= 700) ){
			anotherPage = 1; //need to change later
			loadImage = 7;
		}

		if( (mx >= 65 && mx <= 930) && (my >= 42 && my <= 357) ){
			anotherPage = 1;
			loadImage = 5;
		}






		if(anotherPage == 1){
			if( (mx >= 827 && mx <= 918) && (my >= 115 && my <= 169) ){
				loadImage = 1;
				anotherPage = 0;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		
	}
}


void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	
	
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}

int main()
{
	
	t = iSetTimer(2000, showLoadingPage);


	iInitialize(1000, 800, "Demo");

	loadingImage = iLoadImage("images/loadingImage.jpeg");
	menu = iLoadImage("images/all.png");
	donateBlood = iLoadImage("images/all_pressed_donate.png");
	donateButton = iLoadImage("images/all_pressed_donate_left.png");
	
	findDonor = iLoadImage("images/all_pressed_find.png");
	blank = iLoadImage("images/blank.png");
	backButton = iLoadImage("images/backButton.png");

	iStart(); 

	return 0;
}

