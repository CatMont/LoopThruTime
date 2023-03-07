/****************************************************************************
 *                                                                          *
 *     Name : Catherine Monteith                                            *
 *                                                                          *
 * 	   CMPSC : 472                 								            *
 *                                                                          *
 * 		                                           							*
 *     Desc : Loops through seconds, minutes and hours on a day of a clock  *
 *        	  Increases speed with '+', decreases speed with  '-'           *
			  restarts with 'r', and ends with 'esc', Starts with 'entr' 
 ****************************************************************************/

#include <stdio.h>
#include <windows.h>


int main(int argc, char *argv[])
{
    int hours, mins, secs, incflag, decflag, sleepTime; 

	hours = 0; 
	mins = 0; 
	secs =0; 
	incflag = 0; 
	decflag = 0; 
	sleepTime = 100; 
	

	while(_getch(_kbhit()) != 13) {
		int n = 0; 
	}

	while(hours < 23){ 
		if(mins % 59 == 0 && secs > 0){
			hours++;
			mins = 0; 
		}
		while(mins < 59){
			if(secs % 60 == 0 && secs > 0)
			{
				mins++;
				secs = 0;
			} 
			while(secs < 60)
			{
				_gotoxy(20, 3);
               	printf("[ %d : %d : %d ]", hours, mins, secs);
				Sleep(sleepTime); 
				secs++; 

	
				while(_kbhit())
				{
					int y; 
					y = _getch(_kbhit()); 
					if(y == 27)
						{
						return(0);
						}
					else if(y == 114)//takes input r to reset clock
					{
						hours = 0; 
						mins = 0; 
						secs = 0; 

					}
					else if(y == 43)
					{
						if (incflag <= 20)
						{
							sleepTime = sleepTime + 100; 
							incflag = incflag + 1; 
						}

					}
					else if(y == 45)
					{
						if (decflag <= 20)
						{
							if (sleepTime >= 100)
							{
								sleepTime = sleepTime - 100; 
								decflag = decflag + 1; 
							}
						}
					}

					else{
						_gotoxy(50, 1); 
						printf("%c", y);
						
					}
				}
			}
		}
	}
}


