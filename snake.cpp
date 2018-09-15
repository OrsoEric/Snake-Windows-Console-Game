/****************************************************************************
**	OrangeBot Project
*****************************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************************
**
*****************************************************************************
**	Author: 			Orso Eric
**	Creation Date:
**	Last Edit Date:
**	Revision:			1
**	Version:			0.1 ALFA
****************************************************************************/

/****************************************************************************
**	HYSTORY VERSION
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	KNOWN BUG
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	INCLUDES
****************************************************************************/

///Standard C Libraries
#include <cstdio>
//#include <cstdlib>

///Standard C++ libraries
#include <iostream>
//#include <array>
#include <vector>
#include <queue>
//#include <string>
//#include <fstream>
#include <chrono>
#include <thread>

///OS Libraries
//#define _WIN32_WINNT 0x0500	//Enable GetConsoleWindow
#include <windows.h>

///User Libraries

#include "debug.h"
//Class to animate the windows console
#include "anima.h"
//Game class
#include "snake.h"
//My utility class
#include "my_utils.h"

/****************************************************************************
**	NAMESPACES
****************************************************************************/

namespace User
{

/****************************************************************************
**	GLOBAL VARIABILES
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	CONSTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Constructor
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

Snake::Snake( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Initialize class to safe state
	this -> init();

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end constructor:

/****************************************************************************
**	Initialized constructor
**	Snake | unsigned int, unsigned int
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

Snake::Snake( unsigned int rows, unsigned int cols )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Initialize class to safe state
	this -> init();
	//Create the snake game
	this -> born( rows, cols );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end constructor:

/****************************************************************************
*****************************************************************************
**	DESTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Destructor
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

Snake::~Snake( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end destructor:

/****************************************************************************
*****************************************************************************
**	OPERATORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	SETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	GETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	TESTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	PUBLIC METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Method
**	play | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

unsigned int Snake::play( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counter
	unsigned int t;
	//continue flag
	bool f_continue;
	//snake eat flag
	bool f_eat;
	//Temp position
	Coord pos;
	//Game engine: Link game engine
	Anima &anima = this -> gl_anima;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Game ongoing
	f_continue = true;
	//Snake has not eaten
	f_eat = false;

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//while: Game ongoing
	while (f_continue == true)
	{
		///----------------------------------------------------------------
		///	UPDATE INPUT BUFFER
		///----------------------------------------------------------------
		//	update_input will update the virtual key input buffer
		//	for every virtual key, anima.in( key ) will be
		//		true: key pressed, key down
		//		false: key released, key up
		//	additionally, anima.get_last_vk() will hold the last key that has been pressed
		//	0 if no event has been detected in this update.

		//Update inputs (non blocking call)
		anima.update_input();

		///----------------------------------------------------------------
		///	PROCESS INPUT
		///----------------------------------------------------------------
		//	Based on which keys are down, move the player
		//	the abstraction layer provided by Anima allows to detect simultaneous key presses

		///Process keys
		//if: Quit
		if ((anima.in( VK_Q ) == true) || (anima.get_last_vk() == VK_Q))
		{
			//End condition
			f_continue = false;
			return this -> gl_score;
		}
		//if: most recent key is
		else if (anima.get_last_vk() == VK_UP)
		{
			//Snake is not allowed to turn on its head 180°
			if (this -> gl_snake_head_speed.r != +1)
			{
				//Update head speed
				this -> gl_snake_head_speed.r = -1;
				this -> gl_snake_head_speed.c = 0;
			}
		}
		//if: most recent key is
		else if (anima.get_last_vk() == VK_DOWN)
		{
			//Snake is not allowed to turn on its head 180°
			if (this -> gl_snake_head_speed.r != -1)
			{
				//Update head speed
				this -> gl_snake_head_speed.r = +1;
				this -> gl_snake_head_speed.c = 0;
			}
		}
		//if: most recent key is
		else if (anima.get_last_vk() == VK_LEFT)
		{
			//Snake is not allowed to turn on its head 180°
			if (this -> gl_snake_head_speed.c != +1)
			{
				//Update head speed
				this -> gl_snake_head_speed.r = 0;
				this -> gl_snake_head_speed.c = -1;
			}
		}
		//if: most recent key is
		else if (anima.get_last_vk() == VK_RIGHT)
		{
			//Snake is not allowed to turn on its head 180°
			if (this -> gl_snake_head_speed.c != -1)
			{
				//Update head speed
				this -> gl_snake_head_speed.r = 0;
				this -> gl_snake_head_speed.c = +1;
			}
		}

		///User change speed of the game
		//this also increase value of food pellets
		//For: all numbers
		for (t = VK_0; t <= VK_9;t++)
		{
			//if number key was pressed
			if ((anima.in( t ) == true) || (anima.get_last_vk() == t))
			{
				//update speed grade
				this -> gl_speed_grade = t -VK_0;
				//compute frame delay
				this -> set_speed_grade();
			}
		}

		///----------------------------------------------------------------
		///	GAME LOGIC
		///----------------------------------------------------------------
		//	PROBLEM:
		//	How do I clear the tail?
		//	I need a way to calculate which of the adjacent snake body
		//	char is the right one
		//	SOLUTION:
		//	This is a smart solution.
		//	I use /\-| as snake body parts based on head speed and previous head speed
		//	this constrain provides a free memory for all snake body parts
		//	and constrain the tail position to just two slots
		//	I keep a mamory of the previous tail and this constrain the tail to
		//	 a single position. That I clear!
		//	No.
		//	It was cool but I couldn't be bothered to program it.
		//	I slapped a queue of coordinates and called it a day

		//Update snake position
        this -> gl_snake_head.r += this -> gl_snake_head_speed.r;
        this -> gl_snake_head.c += this -> gl_snake_head_speed.c;

        ///Detect collision
        //if: the head overlaps with food
        if (anima.out( this -> gl_off_r +this -> gl_snake_head.r, this -> gl_off_c +this -> gl_snake_head.c ) == '*')
        {
			///YUMMY!!!
			//Inhibit tail shrinking
            f_eat = true;

            DPRINT("eat r:%d c: %d speed: %d\n", this -> gl_snake_head.r, this -> gl_snake_head.c, this -> gl_speed_grade);
        }
        //if: the head overlaps with anything
        else if (anima.out( this -> gl_off_r +this -> gl_snake_head.r, this -> gl_off_c +this -> gl_snake_head.c ) != ' ')
        {
			///GAME OVER
			//End condition
			f_continue = false;
			DPRINT("collision r:%d c: %d with: <%c>\n", this -> gl_snake_head.r, this -> gl_snake_head.c, anima.out( this -> gl_off_r +this -> gl_snake_head.r, this -> gl_off_c +this -> gl_snake_head.c ));
			return this -> gl_score;
        }

		///----------------------------------------------------------------
		///	PROCESS OUTPUT
		///----------------------------------------------------------------
		//	execute game logic and write in the ascii output buffer

		//The head is an O.
		anima.out( this -> gl_off_r +this -> gl_snake_head.r, this -> gl_off_c +this -> gl_snake_head.c ) = 'O';
		//look the most recent event of the queue. That's the position of the old head
		pos = this -> gl_snake.back();
		//Replace the previous head with the right body segment turn
		anima.out( this -> gl_off_r +pos.r, this -> gl_off_c +pos.c ) = this -> calc_head();
		//push the current head position in the queue
		this -> gl_snake.push( this -> gl_snake_head );
		//if: the snake has not eaten
		if (f_eat == false)
		{
			//pop the position of the tail
			pos = this -> gl_snake.front();
			this -> gl_snake.pop();
			//delete the tail
			anima.out( this -> gl_off_r +pos.r, this -> gl_off_c +pos.c ) = ' ';
		}
		//if: the snake has eaten
		else
		{
			//clear eat flag
			f_eat = false;
			//Spawn a new food pellet
			this -> spawn_food();
			//Update score
			this -> gl_score += this -> gl_speed_grade +1;

			sprintf(&anima.out(this -> gl_off_r+ this ->gl_rows +1,0),"Score: %d", this -> gl_score );
		}
		//Update staus memory variabiles (for body segment calculation)
		this -> gl_snake_old_head_speed = this -> gl_snake_head_speed;

		///----------------------------------------------------------------
		///	UPDATE OUTPUT
		///----------------------------------------------------------------
		//	This function will synchronize the buffer with the console
		//	cout only prints character in sequence, and there is no standard way to do this
		//	the best one can do is to use the OS APIs to access the
		//	console buffer directly.
		//	Anima provides a thin wrapper to hide the system calls and make it simpler

        //Update the output console
        anima.update_output();

		///----------------------------------------------------------------
		///	WAIT NEXT FRAME
		///----------------------------------------------------------------
		//	This can be done with standard library calls with C++11
		//	This can be done better by waking up at the right moment
		//	rather than wait a fixed amount of time

		std::this_thread::sleep_for( std::chrono::milliseconds(this -> gl_frame_delay) );
	}	//end while: Game ongoing

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method: play | void

/****************************************************************************
**	Public Method
**	prompt | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**
****************************************************************************/

bool Snake::prompt( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	bool f_continue;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	sprintf(&this ->gl_anima.out(this -> gl_off_r+ this ->gl_rows +2,0),"GAME OVER! Press Q to quit" );
	this -> gl_anima.update_output();

	f_continue = true;
	//while: Game ongoing
	while (f_continue == true)
	{
		this -> gl_anima.update_input();

		//if: Quit
		if ((this -> gl_anima.in( VK_Q ) == true) || (this -> gl_anima.get_last_vk() == VK_Q))
		{
			//End condition
			f_continue = false;
		}
		std::this_thread::sleep_for( std::chrono::milliseconds(this -> gl_frame_delay) );
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG( "delay: %d\n", this -> gl_frame_delay);

	return false;	//OK
}	//end method: prompt | void

/****************************************************************************
*****************************************************************************
**	PUBLIC STATIC METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	PRIVATE METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Private Method
**	init | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

bool Snake::init( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//temp coordinate
	Coord tmp;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Init coord structure to safe value
	tmp.r = 0;
	tmp.c = 0;
	//Initialize snake status variabiles
	this -> gl_snake_old_head_speed	= tmp;
	this -> gl_snake_head_speed		= tmp;
	this -> gl_snake_head			= tmp;
	//start slow
	this -> gl_speed_grade = 5;
	this -> set_speed_grade();
	//initialize score
	this -> gl_score = 0;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method: init | void

/****************************************************************************
**	Private Method
**	born | unsigned int, unsigned int
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

bool Snake::born( unsigned int rows, unsigned int cols )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER_ARG("rows: %d, cols: %d\n", rows, cols);

	if (this -> gl_anima.is_invalid() == true)
	{
		DRETURN_ARG("ERR: Anima engine fails!\n");
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Save dimensions
	this -> gl_rows = rows;
	this -> gl_cols = cols;

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Draw the initial board
	this -> draw_board();
	//Start Snake on corner
	this -> gl_snake_head.r = 0;
	this -> gl_snake_head.c = 0;
	//init speed
	this -> gl_snake_head_speed.r = +1;
	this -> gl_snake_head_speed.c = +0;
	//push the current head position in the queue
	this -> gl_snake.push( this -> gl_snake_head );
	//Draw snake
	this -> gl_anima.out( this -> gl_off_r +this -> gl_snake_head.r, this -> gl_off_c +this -> gl_snake_head.c ) = 'O';
	//Sawn the first food pellet
	this -> spawn_food();

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method: born | unsigned int, unsigned int


/****************************************************************************
**	Private Method
**	draw_board | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

bool Snake::draw_board( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counter
	unsigned int t;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	Board begins at index:
	//	this -> gl_off_r
	//	this -> gl_off_c
	//
	sprintf(&this -> gl_anima.out(0,0),"Use arrow keys to move snake.");
	sprintf(&this -> gl_anima.out(1,0),"Use 0...9 keys to change speed.");
	sprintf(&this -> gl_anima.out(2,0),"Press Q to quit");
	///Draw vertical bars
	//for: each row
	for (t = this -> gl_off_r -1; t < this -> gl_rows +this -> gl_off_r;t++)
	{
		this -> gl_anima.out( t, this -> gl_off_c -1 ) = '|';
		this -> gl_anima.out( t, this -> gl_off_c +this -> gl_cols ) = '|';
	}
	///Draw horizontal bars
	//for: each col
	for (t = this -> gl_off_c -1; t < this -> gl_off_c +this -> gl_cols;t++)
	{
		this -> gl_anima.out( this -> gl_off_r -1, t ) = '-';
		this -> gl_anima.out( this -> gl_off_r +this -> gl_rows, t ) = '-';
	}
	///Draw corners
	this -> gl_anima.out( this -> gl_off_r -1, this -> gl_off_c -1 ) = '/';
	this -> gl_anima.out( this -> gl_off_r -1, this -> gl_off_c +this -> gl_cols ) = '\\';
	this -> gl_anima.out( this -> gl_off_r +this -> gl_rows, this -> gl_off_c -1 ) = '\\';
	this -> gl_anima.out( this -> gl_off_r +this -> gl_rows, this -> gl_off_c +this -> gl_cols ) = '/';

	//refresh console
	this -> gl_anima.update_output();



	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return false;	//OK
}	//end method: draw_board | void

/****************************************************************************
**	Private Method
**	calc_head | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Calculate head char based on speed
**	This is part of a smart algorithm to clear the tail.
**	i use \/-| as snake body char
**	This constrain the head position to just two possibilities
**	By knowing the old position it collapses to just one
**
**	speed		|	old speed	|	head
**	r	|	c	|	r	|	c	|	head
**	------------------------------------
**	1	|	0	|	1	|	0	|	'|'		uu, ud, du, dd
**	0	|	1	|	0	|	1	|	'-'		ll, lr, rl, rr
**	+1	|	0	|	0	|	+1	|	'\'		dr
**	+1	|	0	|	0	|	-1	|	'/'		dl
**	-1	|	0	|	0	|	+1	|	'/'		ur
**	-1	|	0	|	0	|	-1	|	'\'		ul
**	0	|	+1	|	+1	|	0	|	'/'		rd
**	0	|	+1	|	-1	|	0	|	'\'		ru
**	0	|	-1	|	+1	|	0	|	'\'		ld
**	0	|	-1	|	-1	|	0	|	'/'		lu
**
****************************************************************************/

char Snake::calc_head( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//snake head char
	char head;
	//reference to snake speed
	Coord &speed = this -> gl_snake_head_speed;
	Coord &old_speed = this -> gl_snake_old_head_speed;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	head = 'O';

	//if: snake is traveling horizontally
	if ((speed.r == 0) && (old_speed.r == 0))
	{
		head = '-';
	}
	//if: snake is traveling vertically
	else if ((speed.c == 0) && (old_speed.c == 0))
	{
		head = '|';
	}
	//if: snake made a turn
	else if ((speed.r == 0) && (old_speed.c == 0))
	{
		//this is a cheap way to do a xor
		if ((speed.c +old_speed.r) == 0)
		{
			head = '/';
		}
		else
		{
			head = '\\';
		}
	}
	//if: snake made a turn
	else if ((speed.c == 0) && (old_speed.r == 0))
	{
		//this is a cheap way to do a xor
		if ((speed.r +old_speed.c) == 0)
		{
			head = '/';
		}
		else
		{
			head = '\\';
		}
	}
	else
	{
		head = '?';
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN();

	return head;	//OK
}	//end method:	calc_head | void

/****************************************************************************
**	Private Method
**	spawn_food | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Spawn food for the snake
****************************************************************************/

bool Snake::spawn_food( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	Coord food;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Initialize food to a non valid position
	food = this -> gl_snake_head;

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//While the board is not empty
	while (this -> gl_anima.out( this -> gl_off_r +food.r, this -> gl_off_c +food.c) != ' ')
	{
		//Randomize food position
		food.r = User::My_utils::get_rand<int>(0, this -> gl_rows -1);
		food.c = User::My_utils::get_rand<int>(0, this -> gl_cols -1);
		DPRINT("food.r: %d, food.c: %d\n", food.r, food.c );
	}
	//Spawn food
	this -> gl_anima.out( this -> gl_off_r +food.r, this -> gl_off_c +food.c) = '*';

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG("food.r: %d, food.c: %d\n", food.r, food.c );

	return false;	//OK
}	//end method:

/****************************************************************************
**	Private Method
**	set_speed_grade | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	compute frame delay from speed grade
**	value of pellets increase with speed grade
**	Speed grade |	Frame Delay [mS]
**	------------------------------
**	0			|	500
**	...			|	...
**	9			|	50
****************************************************************************/

bool Snake::set_speed_grade( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//link speed grade
	unsigned int &speed_grade = this -> gl_speed_grade;
	//link frame delay
	unsigned int &frame_delay = this -> gl_frame_delay;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//Trace Enter main
	DENTER();

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//compute frame delay
	frame_delay = 500 -(speed_grade *50);

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	//Trace Return from main
	DRETURN_ARG( "delay: %d\n", frame_delay);

	return false;	//OK
}	//end method: set_speed_grade | void

/****************************************************************************
**	NAMESPACES
****************************************************************************/

} //End Namespace
