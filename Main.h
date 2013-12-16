// Object identifier "DATS"
//#pragma message ("***** Do not forget to change the IDENTIFIER in Main.h! *****")
#define IDENTIFIER	0x44415453

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_LAST					0

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_LAST					0

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_LAST                    28

#include <time.h>

// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
// These values let you store data in your extension that will be saved in the CCA.
// You would use these with a dialog...

typedef struct tagEDATA_V1
{
	extHeader		eHeader;
//	short			swidth;
//	short			sheight;

} EDITDATA;
typedef EDITDATA _far *			LPEDATA;

// Object versions					v0.10
#define	KCX_CURRENT_VERSION			100

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// If you want to store anything between actions/conditions/expressions
// you should store it here. Also, some OEFLAGS require you to add
// structures to this structure.

typedef struct tagRDATA
{
	headerObject	rHo;					// Header
	tm datetime;
	time_t timestamp;
} RUNDATA;
typedef	RUNDATA	_far *			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags
// -------------
#define	OEFLAGS      			0
#define	OEPREFS      			0

/* See OEFLAGS.txt for more info on these useful things! */


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100
