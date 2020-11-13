#include<iostream.h>
#include<conio.h>
int choice,i,j;
char arr[3][3] = {'1','2','3','4','5','6','7','8','9'};
char t = 'X';
int row=0,col=0;
int draw=0;

void layout()
{       clrscr();
	cout<<"\t\t\t * Tic Tac Teo *"<<endl<<endl;
	cout<<"Player1 Symbol = X"<<endl<<"Player 2 Symbol = O"<<endl<<endl;
	cout<<"\t\t"<<"       |       |       "<<endl;
	cout<<"\t\t"<<"   "<<arr[0][0]<<"   |   "<<arr[0][1]<<"   |   "<<arr[0][2]<<"   "<<endl;
	cout<<"\t\t"<<"_______|_______|_______"<<endl;
	cout<<"\t\t"<<"       |       |       "<<endl;
	cout<<"\t\t"<<"   "<<arr[1][0]<<"   |   "<<arr[1][1]<<"   |   "<<arr[1][2]<<"   "<<endl;
	cout<<"\t\t"<<"_______|_______|_______"<<endl;
	cout<<"\t\t"<<"       |       |       "<<endl;
	cout<<"\t\t"<<"   "<<arr[2][0]<<"   |   "<<arr[2][1]<<"   |   "<<arr[2][2]<<"   "<<endl;
	cout<<"\t\t"<<"       |       |       ";
}
void turn()
{
	if(t == 'X')
	{
		cout<<endl<<endl<<"Player1 [X] Turn."<<endl;
		cout<<"Enter Place Nmber For Insert Symbol : ";
	}
	if(t == 'O')
	{
		cout<<endl<<endl<<"Player2 [O]Turn."<<endl;
		cout<<"Enter Place Nmber For Insert Symbol : ";
	}
	cin>>choice;
	cout<<endl;
	switch(choice)
	{
		case 1:
			row=0;col=0;
			break;
		case 2:
			row=0;col=1;
			break;
		case 3:
			row=0;col=2;
			break;
		case 4:
			row=1;col=0;
			break;
		case 5:
			row=1;col=1;
			break;
		case 6:
			row=1;col=2;
			break;
		case 7:
			row=2;col=0;
			break;
		case 8:
			row=2;col=1;
			break;
		case 9:
			row=2;col=2;
			break;
		default:
			cout<<"Invalid Choice."<<endl;
			break;
	}
	if(t == 'X' && arr[row][col]!='X' && arr[row][col]!='O')
	{
		arr[row][col]='X';
		t='O';
	}
	else if(t == 'O' && arr[row][col]!='X' && arr[row][col]!='O')
	{
		arr[row][col]='O';
		t='X';
	}
	else
	{
		cout<<"Enter A Valid Number."  <<"Try Again!!";
		turn();
	}
	layout();
}
int over()
{

	//Check Which Player Win The Game
	for(i=0;i<=2;i++)
	{
		if(((arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2])) ||((arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i])))
		{
			return 0;
		}
	}
	if(((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2])) || ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0])))
	return 0;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if((arr[i][j] != 'X') && (arr[i][j] != 'O'))
			{
				return 1;
			}
		}
	}
	//All Box Fill But Nobody Wins
	draw = 1;
	return 0;


}
void main()
{

	clrscr();
	while(over())
	{
		layout();
		turn();
	}
	if((t=='X') && (draw == 0))
	{
		cout<<endl<<"Player2 [O] Wins!!"<<endl;
	}
	else if((t=='O') && (draw == 0))
	{
		cout<<endl<<"Player1[X] Wins!!"<<endl;
	}
	else
	{
		cout<<"Game Draw.";
	}

	getch();
}