#include <omp.h>

#include "qxoy.h"

QXoY::QXoY(){
}
//----------------------------------------------------------------------------------------------------------------
QXoY::QXoY(QLabel *lbl){
    lblOut  = lbl;
    Rect    = lblOut->rect();
    Pxmp    = new QPixmap(lblOut->size());
    FMaxX  = 10.0;
    FMaxY  = 10.0;
    FMinX  = -10.0;
    FMinY  = -10.0;
    FdX    = 1.0;
    FdY    = 1.0;
    FOX_on = 1;
    FOY_on = 1;
    InitXoY();
}
//----------------------------------------------------------------------------------------------------------------
void QXoY::InitXoY(void){
  int   Width  = Rect.width();
  int   Height = Rect.height();

  Fkx = Width/(ceil(2*FMaxX/FdX)-floor(2*FMinX/FdX));  // 2Fkx - число точек на 1 ед. по оси OX
  if (!Fkx) Fkx=1;
  Fky = Height/(ceil(2*FMaxY/FdY)-floor(2*FMinY/FdY)); // 2Fky - число точек на 1 ед. по оси OY
  if (!Fky) Fky=1;
  if ((FMaxX*FMinX<0)&&(FMaxY*FMinY<0)){ // если 1 и 2
    Fx0 = 0.0;
    Fy0 = 0.0;
    Sx0 = (Width%Fkx)/2+abs(Fkx*floor(2*FMinX/FdX));
    Sy0 = Height-(Height%Fky)/2-abs(Fky*floor(2*FMinY/FdY));
    FOX_on = 1;
    FOY_on = 1;
  }else{
    if (FMaxX*FMinX<0){ // если 1 и не 2
      Fx0 = 0.0;
      Fy0 = 0.5*FdY*(floor(2*FMinY/FdY)+1);
      Sx0 = (Width%Fkx)/2+abs(Fkx*floor(2*FMinX/FdX));
      Sy0 = Height-(Height%Fky)/2-Fky;
      FOX_on = 0;
      FOY_on = 1;
    }else{
      if (FMaxY*FMinY<0){ // если не 1 и 2
        Fx0 = 0.5*FdX*(floor(2*FMinX/FdX)+1);
        Fy0 = 0.0;
        Sx0 = (Width%Fkx)/2+Fkx;
        Sy0 = Height-(Height%Fky)/2-abs(Fky*floor(2*FMinY/FdY));
        FOX_on = 1;
        FOY_on = 0;
      }else{ // если не 1 и не 2
        Fx0 = 0.5*FdX*(floor(2*FMinX/FdX)+1);
        Fy0 = 0.5*FdY*(floor(2*FMinY/FdY)+1);
        Sx0 = (Width%Fkx)/2+Fkx;
        Sy0 = Height-(Height%Fky)/2-Fky;
        FOX_on = 0;
        FOY_on = 0;
      }
    }
  }
  ShowAxis();
}
//-------------------------------------------------- End InitXoY ----------------------------------------------------
void QXoY::ShowAxis(void){

    int I,K,hArr,Thw,X0,Y0,fntHeight,bfWidth;
    double J;
    QString Buf,fStr;
    QPainter pntr;
    int   Width  = Rect.width();
    int   Height = Rect.height();

    fntHeight   = lblOut->fontMetrics().height();
    hArr= fntHeight/3;
    pntr.begin(Pxmp);
    pntr.eraseRect(Rect);
    if (FOX_on){
    //� исуем ось X
    pntr.drawLine(0,Sy0,Width,Sy0);
    pntr.drawLine(Width-3*hArr, Sy0-hArr,Width, Sy0);
    pntr.drawLine(Width-3*hArr,Sy0+hArr,Width, Sy0);
    Y0=Sy0;
  }else Y0=0;
  //� исуем ось X вправо
  J=FdX;
  hArr=0;
  while (J<1){
    J*=10;
    hArr++;
  }
  Buf=QString::number(hArr);
  hArr=fntHeight/4;
  K = (Width % Fkx)/2;
  J = 0.5*FdX*floor(2*FMinX/FdX);
  I = ((int)floor(2*FMinX/FdX))%2;
  bfWidth = lblOut->fontMetrics().width(Buf);
  while (K < Width-bfWidth){
    if (I){
      if (FOX_on){
        pntr.drawLine(K,Y0,K,Y0+hArr);
      }else{
        if(FMaxY<=0){
          pntr.drawLine(K,Y0,K,Y0+hArr);
        }else{
          pntr.drawLine(K,Height-hArr,K,Height);
        }
      }
      I=0;
    }else{
      Buf=QString::number(J);
      bfWidth = lblOut->fontMetrics().width(Buf);
      Thw=bfWidth/2;
      if (FOX_on){
        pntr.drawLine(K,Y0,K,Y0+2*hArr);
        if ((Thw<Fkx)&&(Width-K>Thw)&&(K>Thw)){
          if ((Height-Y0-2*hArr>fntHeight)&&(K!=Sx0)){
            pntr.drawText(K-Thw,Y0+6*hArr,Buf);
          }
        }
      }else{
        if(FMaxY<=0){
          pntr.drawLine(K,Y0,K,Y0+2*hArr);
          if ((Thw<Fkx)&&(Width-K>Thw)&&(K>Thw)){
            if ((Height-Y0-2*hArr>fntHeight)&&(K!=Sx0)){
              pntr.drawText(K-Thw,Y0+6*hArr,Buf);
            }
          }
        }else{
          pntr.drawLine(K,Height,K,Height-2*hArr);
          if ((Thw<Fkx)&&(Width-K>Thw)&&(K>Thw)){
            if (K!=Sx0){
              pntr.drawText(K-Thw,Height-6*hArr-fntHeight,Buf);
            }
          }
        }
      }
      I=1;
    }
    J += 0.5*FdX;
    K += Fkx;
  }

  hArr=fntHeight/3;
  if (FOY_on){
    //� исуем ось Y
    pntr.drawLine(Sx0,Height,Sx0,0);
    pntr.drawLine(Sx0-hArr,3*hArr,Sx0,0);
    pntr.drawLine(Sx0+hArr,3*hArr,Sx0,0);
    X0=Sx0;
  }else X0=Width;

  //� исуем ось Y вверх
  J=FdY;
  hArr=0;
  while (J<1){
    J*=10;
    hArr++;
  }
  Buf=QString::number(hArr);
  K = Height-(Height%Fky)/2;
  J = 0.5*FdY*floor(2*FMinY/FdY);
  I= ((int)floor(2*FMinY/FdY))%2;
  hArr=fntHeight/4;
  while (K>fntHeight){
    if (I){
      if (FOY_on){
        pntr.drawLine(X0-hArr,K,X0,K);
      }else{
        if (FMaxX<=0){
          pntr.drawLine(X0-hArr,K,X0,K);
        }else{
          pntr.drawLine(0,K,hArr,K);
        }
      }
      I=0;
    }else{
      Buf=QString::number(J);
      bfWidth = lblOut->fontMetrics().width(Buf);
      Thw=fntHeight/4;
      if (FOY_on){
         pntr.drawLine(X0-2*hArr,K,X0,K);
        if (Thw<Fky){
          if ((Height-K>Thw)&&(K>Thw)&&(X0-bfWidth-3*hArr>0)&&(K!=Sy0)){
              pntr.drawText(X0-bfWidth-3*hArr,K+Thw,Buf);
          }
        }
      }else{
        if(FMaxX<=0){
          pntr.drawLine(X0-2*hArr,K,X0,K);
          if (Thw<Fky){
            if ((Height-K>Thw)&&(K>Thw)&&(X0-bfWidth-3*hArr>0)&&(K!=Sy0)){
              pntr.drawText(X0-bfWidth-3*hArr,K+Thw,Buf);
            }
          }
        }else{
          pntr.drawLine(0,K,2*hArr,K);
          if (Thw<Fky){
            if ((Height-K>Thw)&&(K>Thw)&&(K!=Sy0)){
              pntr.drawText(bfWidth+3*hArr,K+Thw,Buf);
            }
          }
        }
      }
      I=1;
    }
    J += 0.5*FdY;
    K -= Fky;
  }
  pntr.end();
  lblOut->setPixmap(*Pxmp);
  lblOut->update();
}
//----------------------------------------------------- End of ShowAxis() ---------------------------------
double QXoY::ScrnXToReal(int X){

  double Zn;
  Zn  = X-Sx0;
  Zn /= 2*Fkx;
  Zn *= FdX;
  Zn += Fx0;
  return  Zn;
}
//----------------------------------------------------------------------------------------------------------
double QXoY::ScrnYToReal(int Y){

  double Zn;
  Zn  = Sy0-Y;
  Zn /= 2*Fky;
  Zn *= FdY;
  Zn += Fy0;
  return Zn;
}
//----------------------------------------------------------------------------------------------------------
int QXoY::XToScrn(double X){

  double Zn;
  Zn = (X-Fx0)/FdX;
  Zn *= 2*Fkx;
  Zn += Sx0;
  return Zn;
}
//----------------------------------------------------------------------------------------------------------
int QXoY::YToScrn(double Y){

  double Zn;
  Zn = (Fy0-Y)/FdY;
  Zn *= 2*Fky;
  Zn += Sy0;
  return Zn;
}
//----------------------------------------------------------------------------------------------------------
void QXoY::ShowFn(double(*Fn)(double)){

  int K,F,FinX;
  double x,L;
  QPainter pntr;

  K= XToScrn(FMinX);
  FinX=XToScrn(FMaxX);
  x = ScrnXToReal(K);
  L = Fn(x);
  F = YToScrn(L);
  pntr.begin(Pxmp);
  pntr.drawPoint(K,F);
  {
  int k;
 // #pragma omp parallel shared (pntr) private(k, x, L, F)
  {
  //#pragma omp parallel for
  for (k = XToScrn(FMinX) + 1; k < FinX + 1; ++k){
    x = ScrnXToReal(k);
    L = Fn(x);
    F = YToScrn(L);
    pntr.drawPoint(k,F);
  };
  }
  }
  pntr.end();
  lblOut->setPixmap(*Pxmp);
  lblOut->update();
}

void QXoY::ShowFnmas(int N,int dim,double *x,double **y){
  QPainter pntr;
  pntr.begin(Pxmp);
  {
      for(int i=0;i<N;i++)
      {
          if(i==0)pntr.setPen(QPen(Qt::black, 2));
          if(i==1)pntr.setPen(QPen(Qt::red, 2));
          if(i==2)pntr.setPen(QPen(Qt::blue, 2));
          for(int j=0;j<dim;j++)
          {pntr.drawLine(XToScrn(x[j]),YToScrn(y[i][j]),XToScrn(x[j+1]),YToScrn(y[i][j+1]));
             //pntr.drawLine(XToScrn(0.0),YToScrn(1.5),XToScrn(1.0),YToScrn(3.5));
          }
      }
  };
  pntr.end();
  lblOut->setPixmap(*Pxmp);
  lblOut->update();
}

void QXoY::ShowFnmas(int dim,double *x,double *y, Qt::GlobalColor color){
  QPainter pntr;
  pntr.begin(Pxmp);
  {
      pntr.setPen(QPen(color, 2));
      for(int j=0;j<dim;j++)
      {
          pntr.drawPoint(XToScrn(x[j]),YToScrn(y[j]));
      }
  };
  pntr.end();
  lblOut->setPixmap(*Pxmp);
  lblOut->update();
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetdX(double dX){

  double dx,x,Zn;
  int N;
  if (FMaxX-FMinX>dX){
    dx=fabs(dX);
    N=ceil(2*FMaxX/dx)-floor(2*FMinX/dx);
    if (Width/N<lblOut->fontMetrics().width("n")){
         dx=(FMaxX-FMinX)/4.0;
    }
  }else dx=(FMaxX-FMinX)/4.0;
  x = dx;
  if (x<1){
    while (x<1) x*=10.0;
    Zn=floor(x);
    while (dx<1){Zn/=10.0; dx*=10.0;}
  }else{
    Zn=floor(x);
  }
  FdX=Zn;
  InitXoY();
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetdY(double dY){

  double dy,y,Zn;
  int N;
  if (FMaxY-FMinY > dY){
    dy=fabs(dY);
    N=ceil(2*FMaxY/dy)-floor(2*FMinY/dy);
    if (Width/N<lblOut->fontMetrics().height()){
         dy=(FMaxY-FMinY)/4.0;
    }
  }else dy=(FMaxY-FMinY)/4.0;
  y = dy;
  if (y<1){
    while (y<1) y*=10.0;
    Zn=floor(y);
    while (dy<1){Zn/=10.0; dy*=10.0;}
  }else{
    Zn=floor(y);
  }
  FdY=Zn;
  InitXoY();
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetMinX(double MinX){

  int N;
  QMessageBox msgBox;
  msgBox.setText("The value MinX can not be more MaxX!");
  if (FMaxX>MinX){
    FMinX=MinX;
    N=ceil(2*FMaxX/FdX)-floor(2*FMinX/FdX);
    if ((Width/N<lblOut->fontMetrics().width("n"))||(N==1)){
      SetdX((FMaxX-FMinX)/4.0);
    }else InitXoY();
  }else{
      msgBox.exec();
  }
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetMaxX(double MaxX){

  int N;
  QMessageBox msgBox;
  msgBox.setText("The value MaxX can not be less MinX!");
  if (FMinX<MaxX){
    FMaxX=MaxX;
    N=ceil(2*FMaxX/FdX)-floor(2*FMinX/FdX);
    if ((Width/N<lblOut->fontMetrics().width("n"))||(N==1)){
         SetdX((FMaxX-FMinX)/4.0);
    }else InitXoY();
  }else{
    msgBox.exec();
  }
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetMinY(double MinY){

  int N;
  QMessageBox msgBox;
  msgBox.setText("The value MinY can not be more MaxY!");
  if (FMaxY>MinY){
    FMinY=MinY;
    N=ceil(2*FMaxY/FdY)-floor(2*FMinY/FdY);
    if ((Width/N<lblOut->fontMetrics().width("n"))||(N==1)){
      SetdY((FMaxY-FMinY)/4.0);
    }else InitXoY();
  }else{
    msgBox.exec();
  }
}
//----------------------------------------------------------------------------------------------------------
void QXoY::SetMaxY(double MaxY){

  int N;
  QMessageBox msgBox;
  msgBox.setText("The value MaxX can not be less MinX!");
  if (FMinY<MaxY){
    FMaxY=MaxY;
    N=ceil(2*MaxY/FdY)-floor(2*FMinY/FdY);
    if ((Width/N<lblOut->fontMetrics().width("n"))||(N==1)){
         SetdY((FMaxY-FMinY)/4.0);
    }else InitXoY();
  }else{
    msgBox.exec();
  }
}
//----------------------------------------------------------------------------------------------------------
