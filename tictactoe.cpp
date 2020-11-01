#include<iostream.h>

#include<conio.h>

#include<process.h>

#include<iomanip.h>

#include<dos.h>

#include<stdlib.h>

#include<string.h>

#include<stdio.h>

#include<fstream.h>




void tictac();

int display(char [][3],int=0);

int check_tictac(char [][3],int=0);



void main()

{

	clrscr();

	randomize();



	char arr[3][3],ch;

	int m,n,a,b,i,j,k, dec_val, win_val=0, val=0,x=31,y=9;

	int ohoriz_count=0,overt_count=0,odiag1_count=0,odiag2_count=0;

	int xhoriz_count=0,xvert_count=0,xdiag1_count=0,xdiag2_count=0;

	for (i=0;i<3;i++)

	{

	     for (j=0;j<3;j++)

		 arr[i][j]='*';

	}

	display(arr);



	gotoxy(31,9);

	while(1)

	{

		if(win_val==1)

			break;

		ch=getch();

		if(ch=='w')

			y-=4;

		if(ch=='s')

			y+=4;

		if(ch=='d')

			x+=8;

		if(ch=='a')

			x-=8;

		if(ch==27)

			goto end;

		if(ch==13)

		{

			n=(x-31)/8;

			m=(y-9)/4;

			if(arr[m][n]=='X' || arr[m][n]=='O')

			{

				continue;

			}

			arr[m][n]='X';

		}

		if(x<31)

			x=31;

		if(x>47)

			x=47;

		if(y<9)

			y=9;

		if(y>17)

			y=17;

		gotoxy(x,y);

		if(ch!=13)

			continue;



		arr[m][n]='X';

		win_val=display(arr);

		gotoxy(x,y);

		if (win_val==1)

			break;



		ohoriz_count=overt_count=odiag1_count=odiag2_count=0;

		xhoriz_count=xvert_count=xdiag1_count=xdiag2_count=0;

		a=1;

		b=1;



		//giving computer the BRAINS!!

		for(i=0;i<3;i++)

		{

			ohoriz_count=overt_count=0;

			for(j=0;j<3;j++)

			{

				if(arr[i][j]=='O')

					ohoriz_count++;

				if(arr[j][i]=='O')

					overt_count++;

				if((i+j)==2 && arr[i][j]=='O')

					odiag2_count++;

				if(i==j && arr[i][j]=='O')

					odiag1_count++;

			}

			for(int l=0;l<3;l++)

			{

				if(ohoriz_count==2)

				{

					if(arr[i][l]=='*')

					{

						a=i; b=l;

						ohoriz_count=0;

						goto label;

					}

				}

				if(overt_count==2)

				{

					if(arr[l][i]=='*')

					{

						a=l;  b=i;

						overt_count=0;

						goto label;

					}

				}

				if(odiag1_count==2)

				{

					if(arr[l][l]=='*')

					{

						a=b=l;

						odiag1_count=0;

						goto label;

					}

				}

				if(odiag2_count==2)

				{

					if(arr[l][2-l]=='*')

					{

						a=l;  b=2-l;

						odiag2_count=0;

						goto label;

					}

				}

			}

		}





		for(i=0;i<3;i++)

		{

			xhoriz_count=xvert_count=0;

			for(int j=0;j<3;j++)

			{

				if(arr[i][j]=='X')

					xhoriz_count++;

				if(arr[j][i]=='X')

					xvert_count++;

				if(i==j && arr[i][j]=='X')

					xdiag1_count++;

				if((i+j==2) && arr[i][j]=='X')

					xdiag2_count++;

			}

			for(int l=0;l<3;l++)

			{

				if(xhoriz_count==2)

				{

					if(arr[i][l]=='*')

					{

						a=i; b=l;

						xhoriz_count=0;

						goto label;

					}

				}

				if(xvert_count==2)

				{

					if(arr[l][i]=='*')

					{

						a=l; b=i;

						xvert_count=0;

						goto label;

					}

				}

				if(xdiag1_count==2)

				{

					if(arr[l][l]=='*')

					{

						a=b=l;

						xdiag1_count=0;

						goto label;

					}

				}

				if(xdiag2_count==2)

				{

					if(arr[l][2-l]=='*')

					{

						a=l; b=2-l;

						xdiag2_count=0;

						goto label;

					}

				}

			}

		}



		label:;

		for (j=0;j<1;j++)  //for checking whether place already filled for computer's play

		{

			 if (arr[a][b]=='X' || arr[a][b]=='O')

			 {

				 a=random(3);

				 b=random(3);

				 --j;

			 }

		}

		delay(1000);

		arr[a][b]='O';

		win_val=display(arr);

		gotoxy(x,y);

		if (win_val==1)

			break;



		val=0;

		for (j=0;j<3;j++) //for checking the no. of places filled

		{

			for(k=0;k<3;k++)

			{

				if(arr[j][k]!='*')

					++val;

			}

		}

		if(val==8)

		{

			m=random(3);

			n=random(3);

			for (j=0;j<1;j++) //for putting the last value automatically if the game is

			{                                                          //  surely a draw

				if (arr[m][n]=='X' || arr[m][n]=='O')

				{

					m=random(3);

					n=random(3);

					--j;

				}

			}

			arr[m][n]='X';

			delay(500);

			display(arr);

			cout<<setw(49)<<"THE GAME IS A DRAW!!";

			delay(2000);

			cout<<"\n\n"<<setw(48)<<"Press Any Key...";

			getch();

			break;

		}

	}

	end:;

}

//**************************************************************************************

int display(char arr[3][3],int win_val)

{



	clrscr();

	cout<<"\n\n\n\n\n\n\n\n";

	for (int i=0;i<3;i++)

	{

	   cout<<"\t\t\t\t\b\b";

	   for (int j=0;j<3;j++)

	      cout<<arr[i][j]<<"       ";



	   cout<<"\n\n\n\n";

	}

	win_val=check_tictac(arr,win_val);

	return win_val;

}

//**************************************************************************************

int check_tictac(char arr[][3],int win_val)   //this function is for checking of winning or losing

{





	if((arr[0][2]=='X' && arr[1][2]=='X' && arr[2][2]=='X') || (arr[0][1]=='X' && arr[1][1]=='X' && arr[2][1]=='X') || (arr[0][0]=='X' && arr[1][0]=='X' && arr[2][0]=='X') || (arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X') || (arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X') || (arr[2][0]=='X' && arr[2][1]=='X' && arr[2][2]=='X') || (arr[1][0]=='X' && arr[1][1]=='X' && arr[1][2]=='X') || (arr[0][0]=='X' && arr[0][1]=='X' && arr[0][2]=='X'))

	{

	    cout<<"\t\t\t\t  YOU WIN!!";

	    delay(1000);

	    cout<<"\n\n"<<setw(46)<<"Press Enter...";

	    getch();

	    ++win_val;

	    return win_val;

	}







	else if ((arr[0][0]=='O' && arr[0][1]=='O' && arr[0][2]=='O') || (arr[1][0]=='O' && arr[1][1]=='O' && arr[1][2]=='O') || (arr[2][0]=='O' && arr[2][1]=='O' && arr[2][2]=='O') || (arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O') || (arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O') || (arr[0][0]=='O' && arr[1][0]=='O' && arr[2][0]=='O') || (arr[0][1]=='O' && arr[1][1]=='O' && arr[2][1]=='O') || (arr[0][2]=='O' && arr[1][2]=='O' && arr[2][2]=='O'))

	{

	    cout<<"\t\t\t\t\b\b\b  COMPUTER WINS!!";

	    delay(1000);

	    cout<<"\n\n"<<setw(46)<<"Press Enter...";

	    getch();

	    ++win_val;

	    return win_val;

	}





	else

	   return win_val;



}