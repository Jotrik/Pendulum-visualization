#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#define g 9.81
#define pi 3.14159265358979323846
#define metr 37.938105

class Pendulum
{
protected:
	int X;
	int Y;
	int Color;
	int L;
	int R;
	double Fi,W;
public:
	Pendulum(int, int, int, int, int, double);
	int GetL();
	int GetC();
	double GetW();
	double CalculateW();
	void PutColor(int);
	void Show();
	void Hide();
	void TurnF(double, float);
};

void Pendulum ::PutColor(int Color) { this -> Color=Color; }
int Pendulum ::GetC() { return (Color);}
int Pendulum ::GetL() { return (L); }
double Pendulum ::GetW() { return (W); }


double Pendulum ::CalculateW()
{
   W=sqrt(g/(L/metr));
   return (W);
}

Pendulum:: Pendulum(int X, int Y, int R, int L, int Color, double Fi)
{
	this ->X=X;
	this ->Y=Y;
	this->R=R;
	this -> L=L;
	this -> Color=Color;
	this -> Fi=Fi;
}

void Pendulum ::Show()
{
	int TempColor;
	int X1,Y1;
	int X2,Y2;
	TempColor=getcolor();
	setcolor(Color);
	X1=X;
	Y1=Y;
	X2=X+L*cos(Fi);
	Y2=Y+L*sin(Fi);
	line(X1,Y1,X2,Y2);
	circle(X2+R*cos(Fi),Y2+R*sin(Fi),R);
	setcolor(TempColor);
}

void Pendulum:: Hide()
{
	int TempColor;
	TempColor=GetC();
	PutColor(getbkcolor());
	Show();
	PutColor(TempColor);
}

void Pendulum::TurnF(double DFi, float t)
{
	Hide();
	Fi  = 0.6*sin(DFi*t)+pi/2;
	Show();
}

int main()
{
    clock_t time1, time2;
	int r = 10;
	int l = 110;
	int c= 12;
	int x = 90;
	int d = 65;
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	setbkcolor(15);

if(errorcode!=grOk)
	{
			cout<<"Grphics error:"<<grapherrormsg(errorcode)<<endl;
			cout<<"Press any key..."<<endl;
			getch();
			return(1);
	}

 setcolor(15);

 Pendulum L1(x,3,r,l,c,pi/2);
 Pendulum L2(x+d,3,r,l,c,pi/2);
 Pendulum L3(x+2*d,3,r,l,c,pi/2);
 Pendulum L4(x+3*d,3,r,l,c,pi/2);
 Pendulum L5(x+4*d,3,r,l,c,pi/2);
 Pendulum L6(x+5*d,3,r,l,c,pi/2);
 Pendulum L7(x+6*d,3,r,l,c,pi/2);
 Pendulum L8(x+7*d,3,r,l,c,pi/2);

 Pendulum L9(x,140,r,l,c,pi/2);
 Pendulum L10(x+d,140,r,l,c,pi/2);
 Pendulum L11(x+2*d,140,r,l,c,pi/2);
 Pendulum L12(x+3*d,140,r,l,c,pi/2);
 Pendulum L13(x+4*d,140,r,l,c,pi/2);
 Pendulum L14(x+5*d,140,r,l,c,pi/2);
 Pendulum L15(x+6*d,140,r,l,c,pi/2);
 Pendulum L16(x+7*d,140,r,l,c,pi/2);

 Pendulum L_1(800,140,0,900,8,-3.142);
 Pendulum L_2(800,3,0,900,8,-3.142);

 L1.CalculateW();
 L2.CalculateW();
 L3.CalculateW();
 L4.CalculateW();
 L5.CalculateW();
 L6.CalculateW();
 L7.CalculateW();
 L8.CalculateW();
 L9.CalculateW();
 L10.CalculateW();
 L11.CalculateW();
 L12.CalculateW();
 L13.CalculateW();
 L14.CalculateW();
 L15.CalculateW();
 L16.CalculateW();

 L1.Show();
 L2.Show();
 L3.Show();
 L4.Show();
 L5.Show();
 L6.Show();
 L7.Show();
 L8.Show();
 L9.Show();
 L10.Show();
 L11.Show();
 L12.Show();
 L13.Show();
 L14.Show();
 L15.Show();
 L16.Show();
 L_1.Show();
 L_2.Show();
 
 getch();
 time1 = clock();

 while(!kbhit())
{
  time2 = clock();
  L_1.Show();
  L_2.Show();

  if ((time2-time1)/CLOCKS_PER_SEC > 0.3)
  {
    L1.TurnF(L1.GetW(), (time2-time1)/CLOCKS_PER_SEC-0.3);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 0.6)
  {
    L2.TurnF(L2.GetW(), (time2-time1)/CLOCKS_PER_SEC-0.6);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 0.9)
  {
    L3.TurnF(L3.GetW(), (time2-time1)/CLOCKS_PER_SEC-0.9);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 1.2)
  {
    L4.TurnF(L4.GetW(), (time2-time1)/CLOCKS_PER_SEC-1.2);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 1.5)
  {
    L5.TurnF(L5.GetW(), (time2-time1)/CLOCKS_PER_SEC-1.5);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 1.8)
  {
    L6.TurnF(L6.GetW(), (time2-time1)/CLOCKS_PER_SEC-1.8);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 2.1)
  {
    L7.TurnF(L7.GetW(), (time2-time1)/CLOCKS_PER_SEC-2.1);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 2.4)
  {
    L8.TurnF(L8.GetW(), (time2-time1)/CLOCKS_PER_SEC-2.4);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 2.7)
  {
    L9.TurnF(L9.GetW(), (time2-time1)/CLOCKS_PER_SEC-2.7);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 3.0)
  {
    L10.TurnF(L10.GetW(), (time2-time1)/CLOCKS_PER_SEC-3.0);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 3.3)
  {
    L11.TurnF(L11.GetW(), (time2-time1)/CLOCKS_PER_SEC-3.3);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 3.6)
  {
    L12.TurnF(L12.GetW(), (time2-time1)/CLOCKS_PER_SEC-3.6);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 3.9)
  {
    L13.TurnF(L13.GetW(), (time2-time1)/CLOCKS_PER_SEC-3.9);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 4.2)
  {
    L14.TurnF(L14.GetW(), (time2-time1)/CLOCKS_PER_SEC-4.2);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 4.5)
  {
    L15.TurnF(L15.GetW(), (time2-time1)/CLOCKS_PER_SEC-4.5);
  }
  if ((time2-time1)/CLOCKS_PER_SEC > 4.8)
  {
    L16.TurnF(L16.GetW(), (time2-time1)/CLOCKS_PER_SEC-4.8);
  }
 	delay(20);
}

 getch();
 closegraph();
 return(0);
}
