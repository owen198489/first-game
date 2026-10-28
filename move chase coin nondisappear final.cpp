#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdio> 
#include <cstdlib>
#include <cctype>
using namespace std;

void gotoxy(int x ,int y)
{
	COORD pos = { (SHORT)x , (SHORT) y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void generateItem( int& ix, int& iy, int a, int b){
	ix = rand() % (a - 2) + 1;
	iy = rand() % (b - 2) + 1;
}


int main()
{
	char z;
	const int a = 80;
	const int b = 25;
	const int MAX_MON = 15;
	int mon_x[MAX_MON];
	int mon_y[MAX_MON];
	int mon_count = 0;
	int x = a / 2;
	int y = b / 2;
	int item_x = 0;
	int item_y = 0;
	bool hasItem = false;
	int score = 0;
	
	srand(time(0));
	

	
	cout<<"请填入怪物数量(1-15):";
	cin >> mon_count;
	if(mon_count <1) mon_count = 1;
	if(mon_count > MAX_MON) mon_count = MAX_MON;
	
	for(int i = 0; i < mon_count; i++)  {
	 do {
        mon_x[i] = rand() % (a - 2) + 1;
        mon_y[i] = rand() % (b - 2) + 1;
   		 } while ( (mon_x[i] == x && mon_y[i] == y)||
            	  (abs(mon_x[i] - x) < 3 && abs(mon_y[i] - y) < 3) );
	  }
	
	
	gotoxy(x,y);
	cout<<'*';

		for(int i = 0; i< mon_count; i++){
			gotoxy(mon_x[i], mon_y[i]);	
			cout<<'X';
		}
	
		int frame = 0;
		int mon_slow = 0; 
	
	while (true)                         												//START______________________
	{
		
		if(!hasItem)
		{
			generateItem(item_x, item_y, a, b);
			hasItem = true; 
		}
		
	
		
		if(hasItem) 
		{
			gotoxy(item_x,item_y);
			cout<<'$';
		}
		gotoxy(a-1,0);
		printf("Score: %d", score);
		
		gotoxy(x,y);
		cout<<' ';
		
		z = _getch();
		z = tolower(z);
		
	
		if(z == 'a' && x > 0)
		{
			x--;	
		}	
		else if(z == 's' && y < b-1)
		{
			y++;
		}
		else if(z == 'd' && x < a-1)
		{
			x++;
		}		
		else if(z == 'w' && y > 0)
		{
			y--;
		}
		else if(z == 'q'  )
			break;
			
		
	
		if(hasItem && x == item_x && y == item_y)
		{
			score += 5;
			hasItem = false;
			gotoxy(item_x,item_y);
			cout<<' ';
		}	

 
       
          
           
  			  	if (mon_slow % 2 == 0) {
       		    for (int i = 0; i < mon_count; i++) {
            	gotoxy(mon_x[i], mon_y[i]);
            	cout << ' ';

            	if (mon_x[i] < x && mon_x[i] < a - 1) mon_x[i]++;
           	 	else if (mon_x[i] > x && mon_x[i] > 0) mon_x[i]--;
            	if (mon_y[i] < y && mon_y[i] < b - 1) mon_y[i]++;
            	else if (mon_y[i] > y && mon_y[i] > 0) mon_y[i]--;
}
	    }
      	
		for(int i = 0; i < mon_count; i++)
		{
			for(int j = 0; j < mon_count; j++)
			{
				if(i != j && mon_x[i] == mon_x[j] && mon_y[i] == mon_y[j]) 
				{
					mon_x[i] += (rand() % 3) - 1;
               	 	mon_y[i] += (rand() % 3) - 1;
               	 	if (mon_x[i] < 1) mon_x[i] = 1;
                    if (mon_x[i] > a - 2) mon_x[i] = a - 2;
                    if (mon_y[i] < 1) mon_y[i] = 1;
                    if (mon_y[i] > b - 2) mon_y[i] = b - 2;
				}
			}
		}	
    
			 for (int i = 0; i < mon_count; i++) {
			 	gotoxy(mon_x[i],mon_y[i]);
			 	cout<<'X';
			 }
       
        gotoxy(x, y);
        cout << '*';

        for (int i = 0; i < mon_count; i++) {
            if (frame > 3 && mon_x[i] == x && mon_y[i] == y) {
                gotoxy(a / 2 - 5, b / 2);
                printf("GAME OVER!");
                gotoxy(a / 2 - 5, b / 2 + 1);
                printf("FINAL SCORE: %d", score);
                gotoxy(0, b + 1);
                _getch();
               return 0;
            }
        }
				
				
				frame++;
				mon_slow++;
			}
	

		gotoxy(0,b+1);
		return 0; 
} 
