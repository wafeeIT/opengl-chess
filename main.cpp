#include <iostream>
#include <GLUT/glut.h>

using namespace std;
/* Change to <GL/glut.h> on Linux systems */

float OrthoHeight;
float OrthoWidth;
float WindowHeight;
float WindowWidth;

float BlockDistance;

#define PawnIndex   8
#define PieceType   8
#define Properties  3

#define XCoordinate 0
#define YCoordinate 1
#define Valid       2
#define Background  2

#define Color       2
#define ColorBlack  0
#define ColorWhite  1

#define RookLeft    0
#define KnightLeft  1
#define BishopLeft  2
#define Queen       3
#define King        4
#define BishopRight 5
#define KnightRight 6
#define RookRight   7

class BoardPieces
{
    
public:
    
    int Pawns[PawnIndex][Properties][Color];    
    int OtherPieces[PieceType][Properties][Color];
    
    char OtherPiecesPath[PieceType][Color][Background][500];
    char PawnPath[PawnIndex][Color][Background][500];
    
    BoardPieces()
    {
        for(int Count = 0; Count<8; Count++)
        {
            Pawns[Count][Valid][ColorBlack] = 1;
            Pawns[Count][Valid][ColorWhite] = 1;
            OtherPieces[Count][Valid][ColorBlack] = 1;
            OtherPieces[Count][Valid][ColorWhite] = 1;
            
            Pawns[Count][XCoordinate][ColorBlack] = -400 + Count * 100;
            Pawns[Count][YCoordinate][ColorBlack] = 200;
            Pawns[Count][XCoordinate][ColorWhite] = -400 + Count * 100;
            Pawns[Count][YCoordinate][ColorWhite] = -300;
            
            OtherPieces[Count][XCoordinate][ColorBlack] = -400 + Count * 100;
            OtherPieces[Count][YCoordinate][ColorBlack] = 300;
            OtherPieces[Count][XCoordinate][ColorWhite] = -400 + Count * 100;
            OtherPieces[Count][YCoordinate][ColorWhite] = -400; 
            
            strcpy(PawnPath[Count][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Pawn White.raw");
            strcpy(PawnPath[Count][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Pawn White.raw");
            strcpy(PawnPath[Count][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Pawn Black.raw");
            strcpy(PawnPath[Count][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Pawn Black.raw");
        }
        
        strcpy(OtherPiecesPath[RookLeft][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Rook White.raw");
        strcpy(OtherPiecesPath[RookRight][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Rook White.raw");        
        strcpy(OtherPiecesPath[KnightLeft][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Knight White.raw");
        strcpy(OtherPiecesPath[KnightRight][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Knight White.raw");        
        strcpy(OtherPiecesPath[BishopLeft][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Bishop White.raw");
        strcpy(OtherPiecesPath[BishopRight][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Bishop White.raw");        
        strcpy(OtherPiecesPath[Queen][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White Queen White.raw");
        strcpy(OtherPiecesPath[King][ColorWhite][ColorWhite],"/Users/bhargav/Desktop/Final/White King White.raw");
        
        strcpy(OtherPiecesPath[RookLeft][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Rook Black.raw");
        strcpy(OtherPiecesPath[RookRight][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Rook Black.raw");        
        strcpy(OtherPiecesPath[KnightLeft][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Knight Black.raw");
        strcpy(OtherPiecesPath[KnightRight][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Knight Black.raw");        
        strcpy(OtherPiecesPath[BishopLeft][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Bishop Black.raw");
        strcpy(OtherPiecesPath[BishopRight][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Bishop Black.raw");        
        strcpy(OtherPiecesPath[Queen][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White Queen Black.raw");
        strcpy(OtherPiecesPath[King][ColorWhite][ColorBlack],"/Users/bhargav/Desktop/Final/White King Black.raw");
        
        strcpy(OtherPiecesPath[RookLeft][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Rook Black.raw");
        strcpy(OtherPiecesPath[RookRight][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Rook Black.raw");        
        strcpy(OtherPiecesPath[KnightLeft][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Knight Black.raw");
        strcpy(OtherPiecesPath[KnightRight][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Knight Black.raw");        
        strcpy(OtherPiecesPath[BishopLeft][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Bishop Black.raw");
        strcpy(OtherPiecesPath[BishopRight][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Bishop Black.raw");        
        strcpy(OtherPiecesPath[Queen][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black Queen Black.raw");
        strcpy(OtherPiecesPath[King][ColorBlack][ColorBlack],"/Users/bhargav/Desktop/Final/Black King Black.raw");
        
        strcpy(OtherPiecesPath[RookLeft][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Rook White.raw");
        strcpy(OtherPiecesPath[RookRight][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Rook White.raw");        
        strcpy(OtherPiecesPath[KnightLeft][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Knight White.raw");
        strcpy(OtherPiecesPath[KnightRight][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Knight White.raw");        
        strcpy(OtherPiecesPath[BishopLeft][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Bishop White.raw");
        strcpy(OtherPiecesPath[BishopRight][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Bishop White.raw");        
        strcpy(OtherPiecesPath[Queen][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black Queen White.raw");
        strcpy(OtherPiecesPath[King][ColorBlack][ColorWhite],"/Users/bhargav/Desktop/Final/Black King White.raw");        
            
    }
    
}Piece;

void DrawBoard()
{
    GLuint MyTexture;
        
    FILE* Pointer = fopen("/Users/bhargav/Desktop/Pieces/TestBoard.raw", "rb"); 
    char* Data = (char*) malloc (512 * 512 * 3);
    fread(Data, 512*512*3, 1, Pointer);
    fclose(Pointer);
       
    glColor3f(1,1,1);
    glGenTextures( 1, &MyTexture );
    glBindTexture( GL_TEXTURE_2D, MyTexture ); 
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); 
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,  GL_NEAREST );   
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, Data);
    free( Data ); 
       
    glBegin (GL_QUADS); 
    glTexCoord2d(1.0,1.0); glVertex2d(-400.0,-400.0);   
    glTexCoord2d(0.0,1.0); glVertex2d(-400+800.0,-400.0); 
    glTexCoord2d(0.0,0.0); glVertex2d(-400+800.0,-400+800.0);
    glTexCoord2d(1.0,0.0); glVertex2d(-400,-400+800.0);
    glEnd();
    
}

void DrawPiece(char* PieceName, float XBegin, float YBegin)
{
    GLuint MyTexture;
    
    int XOffset = 100;
    int YOffset = 100;
    
    FILE* Pointer = fopen(PieceName, "rb"); 
    char* Data = (char*) malloc (256*256*3);
    fread(Data, 256*256*3, 1, Pointer);
    fclose(Pointer);
    
    glGenTextures( 1, &MyTexture );
    glBindTexture( GL_TEXTURE_2D, MyTexture ); 
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );    
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,  GL_LINEAR );  
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, Data); 
    free( Data ); 
    
    glBegin (GL_QUADS); 
    glTexCoord2d(1.0,1.0); glVertex2d(XBegin, YBegin );   
    glTexCoord2d(0.0,1.0); glVertex2d(XBegin + XOffset, YBegin ); 
    glTexCoord2d(0.0,0.0); glVertex2d(XBegin + XOffset, YBegin + YOffset);
    glTexCoord2d(1.0,0.0); glVertex2d(XBegin, YBegin + YOffset );
    glEnd(); 
    
}

void MyDisplay()
{

    glClear(GL_COLOR_BUFFER_BIT);    
    glEnable( GL_TEXTURE_2D ); 
    
    DrawBoard();
    
    for(int Count = 0 ; Count < 8 ; Count++ )
    {
        if((Piece.OtherPieces[Count][XCoordinate][ColorWhite] + Piece.OtherPieces[Count][YCoordinate][ColorWhite]) % 200 == ColorBlack)
            DrawPiece(Piece.OtherPiecesPath[Count][ColorWhite][ColorBlack], Piece.OtherPieces[Count][XCoordinate][ColorWhite], Piece.OtherPieces[Count][YCoordinate][ColorWhite]); 
        else
            DrawPiece(Piece.OtherPiecesPath[Count][ColorWhite][ColorWhite], Piece.OtherPieces[Count][XCoordinate][ColorWhite], Piece.OtherPieces[Count][YCoordinate][ColorWhite]);
        
        if((Piece.OtherPieces[Count][XCoordinate][ColorBlack] + Piece.OtherPieces[Count][YCoordinate][ColorBlack]) % 200 == ColorBlack)
            DrawPiece(Piece.OtherPiecesPath[Count][ColorBlack][ColorBlack], Piece.OtherPieces[Count][XCoordinate][ColorBlack], Piece.OtherPieces[Count][YCoordinate][ColorBlack]); 
        else
            DrawPiece(Piece.OtherPiecesPath[Count][ColorBlack][ColorWhite], Piece.OtherPieces[Count][XCoordinate][ColorBlack], Piece.OtherPieces[Count][YCoordinate][ColorBlack]);
        
        if((Piece.Pawns[Count][XCoordinate][ColorWhite] + Piece.Pawns[Count][YCoordinate][ColorWhite]) % 200 == ColorBlack)
            DrawPiece(Piece.PawnPath[Count][ColorWhite][ColorBlack], Piece.Pawns[Count][XCoordinate][ColorWhite], Piece.Pawns[Count][YCoordinate][ColorWhite]); 
        else
            DrawPiece(Piece.PawnPath[Count][ColorWhite][ColorWhite], Piece.Pawns[Count][XCoordinate][ColorWhite], Piece.Pawns[Count][YCoordinate][ColorWhite]);
        
        if((Piece.Pawns[Count][XCoordinate][ColorBlack] + Piece.Pawns[Count][YCoordinate][ColorBlack]) % 200 == ColorBlack)
            DrawPiece(Piece.PawnPath[Count][ColorBlack][ColorBlack], Piece.Pawns[Count][XCoordinate][ColorBlack], Piece.Pawns[Count][YCoordinate][ColorBlack]); 
        else
            DrawPiece(Piece.PawnPath[Count][ColorBlack][ColorWhite], Piece.Pawns[Count][XCoordinate][ColorBlack], Piece.Pawns[Count][YCoordinate][ColorBlack]);
    }
      
    glFlush();
    
}

void MyReshape(int Width, int Height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    
    if(Width<=Height)
    {
        gluOrtho2D(-500, 500, -500 * (double)Height/Width, 500 * (double)Height/Width);
        OrthoWidth = 1000;
        OrthoHeight = 1000 * (double)Height/Width;        
    }
    else
    {
        gluOrtho2D(-500* (double)Width/Height, 500* (double)Width/Height, -500, 500);
        OrthoWidth = 1000 * (double)Width/Height;
        OrthoHeight = 1000; 
    }    
    glMatrixMode(GL_MODELVIEW);  
    
    WindowWidth = Width;
    WindowHeight = Height;
    BlockDistance = 100 * Height/OrthoHeight;    
    glViewport(0, 0, Width, Height);    
    glutPostRedisplay();
}

void WindowInitializations()
{    
    glClearColor(0,0,0,1);
    glutFullScreen();    
}


void MyMouse(int Button, int State, int X, int Y)
{   
    if(Button == GLUT_LEFT && State == GLUT_DOWN)
    {
        cout<<"Ortho : "<<OrthoWidth<<" "<<OrthoHeight<<endl;
        cout<<"Screen : "<<WindowWidth<<" "<<WindowHeight<<endl;
        cout<<X<<" "<<Y<<endl;
    }
}

int main(int argc, char** argv)
{    
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);	
	glutCreateWindow("Chess v1.0");
    
    WindowInitializations();
       
	glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMouseFunc(MyMouse);    
	glutMainLoop();
    return 0;
}