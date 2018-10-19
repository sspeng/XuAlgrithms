  //6FFTS.CPP
  //�䲽�����������
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  ffts 
  {
  private: 
		   double  a, b, eps, integ;
  public:
	       ffts (double aa, double bb, double es)//˳���ṩa,b,epsֵ�Ĺ��캯��
           { a = aa; b = bb; eps = es; }
		   void integration ();    //ִ�б䲽�����������
           void output ();         //�������ֵ���ļ�����ʾ
		   double func (double);   //���㱻������ֵ
  };

  void ffts::integration ()       //ִ�б䲽�����������
  { 
	  int n,k;
      double fa,fb,h,t1,p,s,x,t;
      fa=func (a);  fb=func (b);
      n=1; h=b-a;
      t1=h*(fa+fb)/2.0;
      p=eps+1.0;
      while (p>=eps)
      { 
		  s=0.0;
          for (k=0;k<=n-1;k++)
          { 
			  x=a+(k+0.5)*h;
              s=s+func (x);
          }
          t=(t1+h*s)/2.0;
          p=fabs(t1-t);
          t1=t; n=n+n; h=h/2.0;
      }
      integ = t;
  }

  void ffts::output ()       //�������ֵ���ļ�����ʾ
  {
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  fout <<integ <<endl;  cout <<"����ֵ = " <<integ <<endl;
	  fout.close ();
  }

  double ffts::func (double x)
  {  return exp(-x*x); }

  void main ()      //������
  {
	  ffts  solution(0.0, 1.0, 0.000001); //��������˳���ṩa, b, epsֵ
	  solution.integration ();    //ִ�б䲽�����������
	  solution.output ();    //�������ֵ���ļ�����ʾ
  }
