/*
	Alfredo Vargas
	CECS 282 
	Project 3: Maze
	*/

using namespace std;
#include <iostream>;

/*
	movement of the object
	value is a plot point*/
void moveLeft(int &posX, int spaces)
{
	posX = posX - spaces;
}

void moveRight(int &posX, int spaces)
{
	posX = posX + spaces;
}

void moveUp(int &posY, int spaces)
{
	posY = posY - spaces;
}

void moveDown(int &posY, int spaces)
{
	posY = posY + spaces;
}

/*
	displays the maze
	*/
void display(int (*m)[14][17])
{
	int maze[14][17];
	for (int j = 0; j < 14; j++)
		for (int k = 0; k < 17; k++)
			maze[j][k] = (*m)[j][k];
	for (int i = 0; i < 14; i++) {
		for (int p = 0; p < 17; p++) {
			//replace int value for the object
			//0 = space
			//1 = start
			//5 = wall
			//2 = end
			//3 = moving piece
			switch (maze[i][p]) {
			case 0:
				cout << " ";
				break;
			case 1: 
				cout << "O";
				break;
			case 3: 
				cout << "#";
				break;
			case 5:
				cout << "X";
				break;
			case 2:
				cout << "O";
				break;
			default:
				cout << maze[i][p];
				break;
			}
		}
		cout << endl;
	}
}

int main()
{
	bool exitP;
	do {
		exitP = false;
		//default maze
		/*
		1 = start
		0 = empty
		5 = obstacle/wall
		2 = end;
		*/
		int mazeStart[14][17] = {
			{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
			{1, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 5},
			{5, 5, 5, 5, 0, 5, 0, 5, 0, 5, 0, 5, 5, 5, 5, 0, 5},
			{0, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 5, 0, 5},
			{0, 5, 5, 5, 5, 5, 0, 5, 0, 0, 0, 5, 0, 5, 5, 0, 5},
			{0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 5, 5, 0, 5, 5, 0, 5},
			{5, 5, 5, 5, 5, 5, 5, 5, 0, 5, 0, 0, 0, 0, 0, 0, 5},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 0, 5},
			{0, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 5, 0, 0, 0, 0, 5},
			{0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5},
			{5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 5},
			{0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 5},
			{2, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
			{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
		};
		//create a pointer to the maze array
		int(*mazeStuff)[14][17] = &mazeStart;
		//display the starting maze Mapw
		display(mazeStuff);
		//start poistion of the moving object
		int posX = 0;
		int posY = 0;
		bool flag;
		int prev;
		int choice;
		int spaces;
		//previous poition of the object, used for placement correction
		int prevPosX, prevPosY;
		do {
			flag = false;
			prevPosX = posX;
			prevPosY = posY;
			bool flagMenu;
			do {
				flagMenu = false;
				cout << "\nMove: \n";
				cout << "[1] Left \n[2] Right \n[3] Up \n[4] Down \n[5] Restart \n[0] Exit \n";
				cin >> choice;
				if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
				{
					cout << "Spaces: ";
					cin >> spaces;
				}
				switch (choice) {
				case 1:
					moveLeft(posX, spaces);
					break;
				case 2:
					moveRight(posX, spaces);
					break;
				case 3:
					moveUp(posY, spaces);
					break;
				case 4:
					moveDown(posY, spaces);
					break;
				case 5:
					cout << "\nResarting.... \n";
					flag = true;
					exitP = false;
					break;
				case 0:
					cout << "Exit.\n";
					flag = true;
					exitP = true;
					break;
				default:
					cout << "Invalid Entry. Re-enter.\n";
					flagMenu = true;
					break;
				}
			} while (flagMenu);
				//holds the previous object
				prev = (*mazeStuff)[posY + 1][posX];
				// + 1 for the buffer, since the frame of maze map
				(*mazeStuff)[posY + 1][posX] = 3;
				//check to see if moved postion is a valid spot (not a wall/barrier)
				switch (prev) {
				case 5:
					cout << "Collided with wall!!!! Moved back to previous place.\n";
					(*mazeStuff)[posY + 1][posX] = prev;
					posX = prevPosX;
					posY = prevPosY;
					(*mazeStuff)[prevPosY + 1][prevPosX] = 3;
					system("pause");
					break;
				case 2:
					cout << "Reached the end of the MAZE!!!\n";
					system("pause");
					flag = true;
					break;
				default:
					(*mazeStuff)[prevPosY + 1][prevPosX] = 0;
					break;
				}
				//make last move its orginal value
				//(*mazeStuff)[prevPosY + 1][prevPosX] = 0;
				if(choice != 0 && choice != 5)
					display(mazeStuff);
				system("pause");
			}while (!flag);
	} while (!exitP);
	return 0;
}