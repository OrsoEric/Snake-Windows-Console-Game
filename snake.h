/**********************************************************************************
**	ENVIROMENT VARIABILE
**********************************************************************************/

#ifndef SNAKE_H_
	#define SNAKE_H_

/**********************************************************************************
**	GLOBAL INCLUDES
**********************************************************************************/

#ifndef ANIMA_H_
	#include "anima.h"
#endif

/**********************************************************************************
**	DEFINES
**********************************************************************************/

/**********************************************************************************
**	MACROS
**********************************************************************************/

/**********************************************************************************
**	NAMESPACE
**********************************************************************************/

//Assign class to a namespace
namespace User
{

/**********************************************************************************
**	TYPEDEFS
**********************************************************************************/

//Coordinate structure
typedef struct _Coord
{
	int r;
	int c;
} Coord;

/**********************************************************************************
**	PROTOTYPE: STRUCTURES
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: GLOBAL VARIABILES
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: CLASS
**********************************************************************************/

/****************************************************************************
**	Class
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

class Snake
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		//Default constructor
		Snake( void );
		//Initialized constructor
		Snake( unsigned int rows, unsigned int cols );

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

		//Default destructor
		~Snake( void );

		///--------------------------------------------------------------------------
		///	OPERATORS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	SETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	GETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	TESTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PUBLIC METHODS
		///--------------------------------------------------------------------------

		//Play a game of snake. Blocking until game ends or quit.
		unsigned int play( void );
		//Wait prompt
		bool prompt( void );

		///--------------------------------------------------------------------------
		///	PUBLIC STATIC METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------

		//Initialize class
		bool init( void );
		//Construct the snake game with a given board size
		bool born( unsigned int rows, unsigned int cols );
		//Draw the initial snake board
		bool draw_board( void );
		//Calculate head char based on speed
		char calc_head( void );
		//Spawn food for the snake
		bool spawn_food( void );
		//compute frame delay from speed grade
		bool set_speed_grade( void );

		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

		///Constants
		//offsets where the game board begins
		static const unsigned int gl_off_r = 4;
		static const unsigned int gl_off_c = 1;
		//queue of all snake coordinates
		std::queue<Coord> gl_snake;
		//Size of the board (not counting borders
		unsigned int gl_rows, gl_cols;
		//Coordinates of head and tail of the snake
		Coord gl_snake_head;
		//Speed of the snake head
		Coord gl_snake_head_speed;
		Coord gl_snake_old_head_speed;	//needed to calculate body segment
		//speed is 1 to 9
		unsigned int gl_speed_grade;
		//Frame delay
		unsigned int gl_frame_delay;
		//game score
		unsigned int gl_score;
		//Game engine
		User::Anima gl_anima;

};	//End Class: Snake

/**********************************************************************************
**	NAMESPACE
**********************************************************************************/

} //End Namespace

#else
    #warning "Multiple inclusion of hader file"
#endif
