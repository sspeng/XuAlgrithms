  //6G_MTCL.CPP
  //Monte-Carlo������һά����
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  g_mtcl
  {
  private: 
		   double  a, b, integ, r;
  public:
	       g_mtcl (double aa,double bb)  //˳���ṩa,bֵ�Ĺ��캯��
		   { a = aa; b = bb; }
		   void integration ();    //ִ��Monte-Carlo��
           void output ();         //�������ֵ���ļ�����ʾ
		   double func (double);   //���㱻������ֵ
           double rnd ();          //����һ�������
  };

  void g_mtcl::integration ()  //ִ��Monte-Carlo��
  { 
	  int m;
      double d,x,s;
      r=1.0; s=0.0; d=10000.0;
      for (m=0; m<=9999; m++)
      { 
		  x=a+(b-a)*rnd();
          s=s+func(x)/d;
      }
      s=s*(b-a);
      integ = s;
  }

  double g_mtcl::rnd ()      //����һ�������
  { 
	  int m;
      double s,u,v,p;
      s=65536.0; u=2053.0; v=13849.0;
      m=(int)(r/s); r=r-m*s;
      r=u*r+v; m=(int)(r/s);
      r=r-m*s; p=r/s;
      return(p);
  }

  void g_mtcl::output ()       //�������ֵ���ļ�����ʾ
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

  double g_mtcl::func (double x)
  {  return (x*x+sin(x)); }

  void main ()      //������
  {
	  g_mtcl  solution (2.5, 8.4); 
	                        //��������˳���ṩa,b��ֵ
	  solution.integration ();    //ִ��Monte-Carlo��
	  solution.output ();    //�������ֵ���ļ�����ʾ
  }
