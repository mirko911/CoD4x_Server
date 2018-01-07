/*
===========================================================================
    Copyright (C) 2010-2013  Ninja and TheKelm
    Copyright (C) 1999-2005 Id Software, Inc.

    This file is part of CoD4X18-Server source code.

    CoD4X18-Server source code is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CoD4X18-Server source code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
===========================================================================
*/

#ifndef __Q_SHARED_H__
#define __Q_SHARED_H__

//#define _LAGDEBUG

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "q_shared_types.h"


//#include "game/def.h"

#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif

#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif

#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL __attribute__ ((visibility ("hidden")))

#ifdef __linux

#define __optimize2 __attribute__ ((optimize("-O2")))
#define __optimize3 __attribute__ ((optimize("-O3"))) __attribute__ ((noinline))

#else

#define __optimize2
#define __optimize3

#endif

#define REGPARM(X)   __attribute__ ((regparm(X)))

#ifndef QDECL
#define QDECL
#endif

#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif

#ifndef __regparm1
#define __regparm1 __attribute__((regparm(1)))
#endif

#ifndef __regparm2
#define __regparm2 __attribute__((regparm(2)))
#endif

#ifndef __regparm3
#define __regparm3 __attribute__((regparm(3)))
#endif

#ifndef LOWORD
#define LOWORD(a) ((WORD)(a))
#endif

#ifndef HIWORD
#define HIWORD(a) ((WORD)(((DWORD)(a) >> 16) & 0xFFFF))
#endif

#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)

//#define DEVRELEASE


#ifndef STDCALL
#define STDCALL __attribute__((stdcall))
#endif

#define HOMEPATH_NAME_UNIX ".callofduty4"
#define HOMEPATH_NAME_WIN		"CallofDuty4"
#define HOMEPATH_NAME_MACOSX		HOMEPATH_NAME_WIN

#define	MAX_STRING_TOKENS	1024	// max tokens resulting from Cmd_TokenizeString
#define	MAX_STRING_CHARS	1024

#ifndef Q_vsnprintf
int Q_vsnprintf(char *s0, size_t size, const char *fmt, va_list args);
#endif

#define Q_COLOR_ESCAPE	'^'
#define Q_IsColorString(p)	( p && *(p) == Q_COLOR_ESCAPE && *((p)+1) && *((p)+1) != Q_COLOR_ESCAPE )

#define COLOR_BLACK		'0'
#define COLOR_RED		'1'
#define COLOR_GREEN		'2'
#define COLOR_YELLOW	'3'
#define COLOR_BLUE		'4'
#define COLOR_CYAN		'5'
#define COLOR_MAGENTA	'6'
#define COLOR_WHITE		'7'
#define ColorIndex(c)	( ( (c) - '0' ) & 7 )

#define S_COLOR_BLACK	"^0"
#define S_COLOR_RED		"^1"
#define S_COLOR_GREEN	"^2"
#define S_COLOR_YELLOW	"^3"
#define S_COLOR_BLUE	"^4"
#define S_COLOR_CYAN	"^5"
#define S_COLOR_MAGENTA	"^6"
#define S_COLOR_WHITE	"^7"

#define MAX_OSPATH 256
#define	MAX_INFO_STRING		1024
#define	MAX_INFO_KEY		1024
#define	MAX_INFO_VALUE		1024
#define	MAX_TOKEN_CHARS		1024

#define	MAX_STRING_CHARS	1024	// max length of a string passed to Cmd_TokenizeString
#define	MAX_NAME_LENGTH		16	// max length of a client name
#define	MAX_QPATH		64	// max length of a quake game pathname

#define	BIG_INFO_STRING		8192  // used for system info key only
#define	BIG_INFO_KEY		8192
#define	BIG_INFO_VALUE		8192

#define TRUNCATE_LENGTH	64

#define LIBRARY_ADDRESS_BY_HANDLE(dlhandle)((NULL == dlhandle) ? NULL :(void*)*(size_t const*)(dlhandle))

#define Com_Memset memset
#define Com_Memcpy memcpy


#define NET_WANT_READ -0x7000
#define NET_WANT_WRITE -0x7001
#define NET_CONNRESET -0x7002
#define NET_ERROR -0x7003

short   ShortSwap (short l);
short	ShortNoSwap (short l);
int    LongSwap (int l);
int	LongNoSwap (int l);

int Q_isprint( int c );
int Q_islower( int c );
int Q_isupper( int c );
int Q_isalpha( int c );
qboolean Q_isanumber( const char *s );
qboolean Q_isintegral( float f );
qboolean Q_isprintstring( char* s );

#ifdef _MSC_VER
int Q_vsnprintf(char *str, size_t size, const char *format, va_list ap);
#endif

void Q_strncpyz( char *dest, const char *src, int destsize );
int Q_stricmpn (const char *s1, const char *s2, int n);
int Q_strncmp (const char *s1, const char *s2, int n);
int Q_stricmp (const char *s1, const char *s2);
char *Q_strlwr( char *s1 );
char *Q_strupr( char *s1 );
void Q_bstrcpy(char* dest, const char* src);
void Q_strcat( char *dest, int size, const char *src );
void Q_strlcat( char *dest, size_t size, const char *src, int cpylimit);
void Q_strnrepl( char *dest, size_t size, const char *src, const char* find, const char* replacement);
const char *Q_stristr( const char *s, const char *find);
int  Q_strichr( const char *s, char find);
int Q_PrintStrlen( const char *string );
char *Q_CleanStr( char *string );
int Q_CountChar(const char *string, char tocount);
int QDECL Com_sprintf(char *dest, int size, const char *fmt, ...);
void Q_strchrrepl(char *string, char torepl, char repl);
char* Q_BitConv(int val);
int Q_strLF2CRLF(const char* input, char* output, int outputlimit );
/* char	* QDECL va( char *format, ... ); */
char* QDECL va_replacement(char *dest, int size, const char *fmt, ...);
#define mvabuf char va_buffer[MAX_STRING_CHARS]
#define va(fmt,... ) va_replacement(va_buffer, sizeof(va_buffer), fmt, __VA_ARGS__)

void Com_TruncateLongString( char *buffer, const char *s );


qboolean Info_Validate( const char *s );
char *Info_ValueForKey( const char *s, const char *key );
int BigInfo_DecodedValueForKey( const char *s, const char *key, char* outbuf, int outlen );
void Info_SetValueForKey( char *s, const char *key, const char *value );
void BigInfo_SetValueForKey( char *s, const char *key, const char *value );
void BigInfo_SetEncodedValueForKey( char *s, const char *key, const char *value, int len );
void Info_Print( const char *s );

int SV_Cmd_Argc( void );
int	Cmd_Argc( void );
char	*SV_Cmd_Argv( int arg );
void	SV_Cmd_ArgvBuffer( int arg, char *buffer, int bufferLength );
char	*Cmd_Argv( int arg );
char	*Cmd_Args( char* buff, int bufsize );
char	*Cmd_Argsv( int arg, char* buff, int bufsize );

char	*SV_ExpandNewlines( char *in );




#include "q_math.h"


/*****************************************************
*** Parsing files ***
*****************************************************/
void Com_ParseReset();
char* Com_ParseGetToken(char* line);
int Com_ParseTokenLength(char* token);

qboolean isNumeric(const char* string, int size);

/*
=====================================================================
 Functions to operate onto a stack in lifo mode
=====================================================================
*/

void stack_init(void *array[], size_t size);
qboolean stack_push(void *array[], int size, void* pointer);
void* stack_pop(void *array[], int size);

/*
=====================================================================
  Writing XML STRINGS
=====================================================================
*/

void XML_Init( xml_t *base, char *s, int size, char* encoding);
void XML_Escape( char* buffer, size_t size, const char* string);
qboolean QDECL XML_OpenTag( xml_t *base, char* root, int count,... );
void XML_CloseTag(xml_t *base);
void XML_AppendToBuffer( xml_t *base, const char* s );

char *Com_SkipCharset( char *s, char *sep );
char *Com_SkipTokens( char *s, int numTokens, char *sep );

void COM_DefaultExtension( char *path, int maxSize, const char *extension );

qboolean I_IsEqualUnitWSpace(char *cmp1, char *cmp2);
unsigned char I_CleanChar(unsigned char in);


qboolean isFloat(const char* string, int size);
qboolean isInteger(const char* string, int size);
qboolean isVector(const char* string, int size, int dim);
qboolean strToVect(const char* string, float *vect, int dim);


/*
=====================================================================================

SCRIPT PARSING

=====================================================================================
*/

// this just controls the comment printing, it doesn't actually load a file
void Com_BeginParseSession( const char *filename );
void Com_EndParseSession( void );

int Com_GetCurrentParseLine( void );

// Will never return NULL, just empty strings.
// An empty string will only be returned at end of file.
// ParseOnLine will return empty if there isn't another token on this line

// this funny typedef just means a moving pointer into a const char * buffer
const char *Com_Parse( const char *( *data_p ) );
const char *Com_ParseOnLine( const char *( *data_p ) );
const char *Com_ParseRestOfLine( const char *( *data_p ) );

void Com_UngetToken( void );
/*
#ifdef __cplusplus
void Com_MatchToken( const char *( *buf_p ), const char *match, qboolean warning = qfalse );
#else
void Com_MatchToken( const char *( *buf_p ), const char *match, qboolean warning );
#endif
*/
void Com_ScriptError( const char *msg, ... );
void Com_ScriptWarning( const char *msg, ... );

void Com_SkipBracedSection( const char *( *program ) );
void Com_SkipRestOfLine( const char *( *data ) );

float Com_ParseFloat( const char *( *buf_p ) );
int Com_ParseInt( const char *( *buf_p ) );

void Com_Parse1DMatrix( const char *( *buf_p ), int x, float *m );
void Com_Parse2DMatrix( const char *( *buf_p ), int y, int x, float *m );
void Com_Parse3DMatrix( const char *( *buf_p ), int z, int y, int x, float *m );

//=====================================================================================

void QDECL Com_Error( int a, const char *error, ...);

#ifndef M_PI
#define M_PI        3.14159265358979323846f // matches value in gcc v2 math.h
#endif

// angle indexes
#define PITCH               0       // up / down
#define YAW                 1       // left / right
#define ROLL                2       // fall over

// plane types are used to speed some tests
// 0-2 are axial planes
#define PLANE_X         0
#define PLANE_Y         1
#define PLANE_Z         2
#define PLANE_NON_AXIAL 3


/*
=================
PlaneTypeForNormal
=================
*/

#define PlaneTypeForNormal( x ) ( x[0] == 1.0 ? PLANE_X : ( x[1] == 1.0 ? PLANE_Y : ( x[2] == 1.0 ? PLANE_Z : PLANE_NON_AXIAL ) ) )

//=============================================

float Com_Clamp( float min, float max, float value );

char    *COM_SkipPath( char *pathname );
void    COM_StripExtension( const char *in, char *out );
void    COM_StripExtension2( const char *in, char *out, int destsize );
void    COM_StripFilename( char *in, char *out );
void    COM_DefaultExtension( char *path, int maxSize, const char *extension );

void    COM_BeginParseSession( const char *name );
void    COM_RestoreParseSession( char **data_p );
void    COM_SetCurrentParseLine( int line );
int     COM_GetCurrentParseLine( void );
char    *COM_Parse( char **data_p );
char    *COM_ParseExt( char **data_p, qboolean allowLineBreak );
int     COM_Compress( char *data_p );
void    COM_ParseError( char *format, ... );
void    COM_ParseWarning( char *format, ... );
//int		COM_ParseInfos( char *buf, int max, char infos[][MAX_INFO_STRING] );

qboolean COM_BitCheck( const int array[], int bitNum );
void COM_BitSet( int array[], int bitNum );
void COM_BitClear( int array[], int bitNum );


#define MAX_TOKENLENGTH     1024

#ifndef TT_STRING
//token types
#define TT_STRING                   1           // string
#define TT_LITERAL                  2           // literal
#define TT_NUMBER                   3           // number
#define TT_NAME                     4           // name
#define TT_PUNCTUATION              5           // punctuation
#endif
/*
typedef struct pc_token_s
{
	int type;
	int subtype;
	int intvalue;
	float floatvalue;
	char string[MAX_TOKENLENGTH];
} pc_token_t;
*/
// data is an in/out parm, returns a parsed out token

void    COM_MatchToken( char**buf_p, char *match );

void    Swap_Init( void );


#define random()    ( ( rand() & 0x7fff ) / ( (float)0x7fff ) )
#define crandom()   ( 2.0 * ( random() - 0.5 ) )

qboolean Assert_MyHandler(const char* exp, const char *filename, int line, const char *function, const char *fmt, ...);


#define assert ASSERT
#define assertx XASSERT
#define ASSERT_HANDLER(x, f, l, fu, ...) (Assert_MyHandler(x, f, l, fu, __VA_ARGS__))
#define XASSERT(x, ...) (!(x) && ASSERT_HANDLER(#x, __FILE__, __LINE__, __func__, __VA_ARGS__) && (ASSERT_HALT(), 1))
#define ASSERT(x) XASSERT(x, NULL)

// These one causes some complile issues when using both gcc and g++ compilers with plugin handler.
// So I have commented out C++ part and left only C part.
// Worth looking at this if some problems with "abort" will be discovered.
//#ifdef __cplusplus
//#include <cstdlib>
//#define ASSERT_HALT() (std::abort())
//#else
#define ASSERT_HALT() (abort())
//#endif


#include "q_platform.h"
#include "q_math.h"
#include "sys_cod4defs.h"
#include "entity.h"

#endif

