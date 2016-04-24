#ifndef XOY_H
#define XOY_H

#include <QObject>
#include <QtGui>
#include <math.h>

class QXoY : public QObject{
private:
//* куда рисуем*/
   QPixmap          *Pxmp;
   QLabel           *lblOut;
   QRect            Rect;
   int              Width,Height;
   //* Параметры системы координат */
   double FMinX,  FMaxX; //Границы по оси OX
   double FMinY,  FMaxY; //Границы по оси OY
   double FdX, FdY;      //Шаги по осям
   double Fx0, Fy0;      //� еальные координаты точки пересечения осей.
   int    Sx0, Sy0;      //Экранные координаты точки пересечения осей.
   int    Fkx, Fky;      //Число точек в половине ед. масштаба
   char   FOX_on,FOY_on;
//Границы по оси OX
   double MinX;
   double MaxX;
//Границы по оси OY
   double MinY;
   double MaxY;
//Цена делений по осям
   double dY;
   double dX;

public:
            QXoY();
            QXoY(QLabel *lbl);
   void     SetMinX(double MinX);
   void     SetMaxX(double MaxX);
   void     SetMinY(double MinY);
   void     SetMaxY(double MaxY);
   void     SetdX(double dX);
   void     SetdY(double dY);
   void     InitXoY(void);
   void     ShowAxis(void);
   double   ScrnXToReal(int X);
   double   ScrnYToReal(int Y);
   int      XToScrn(double X);
   int      YToScrn(double Y);
   void     ShowFn(double(*Fn)(double));
   void     ShowFnmas(int,int,double*,double**);
   void     ShowFnmas(int,double*,double*);
};

#endif // XOY_H

