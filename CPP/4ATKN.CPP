  //4ATKN.CPP
  //Aitken�������󷽳̸�
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  atkn
  {
  private: 
           int Max;
		   double  x, eps;
  public:
	       atkn(double x0, double es, int m)//�ṩ���ĳ�ֵ������Ҫ��������������
		    { x = x0;  eps = es; Max = m; }
		   void atkn_root ();        //ִ��Aitken������
           void output ();         //��������ļ�����ʾ
		   double func (double);   //���㷽����˺�����(x)ֵ
  };

  void atkn::atkn_root ()     //ִ��Aitken������
  { 
	  int flag,k;
      double u,v,x0;
      k=0; x0=x; flag=0;
      while ((flag==0)&&(k!=Max))
      { 
		  k=k+1; 
          u=func (x0); v=func (u);
          if (fabs(u-v)<eps) { x0=v; flag=1; }
          else x0=v-(v-u)*(v-u)/(v-2.0*u+x0);
      }
      x=x0;
	  if (k == Max)
		  cout <<"\n������������" <<endl;
  }

  void atkn::output ()       //��������ļ�����ʾ
  {
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  fout <<endl <<x <<endl;
	  cout <<endl <<"x = " <<x <<endl;
	  fout.close ();
  }

  double atkn::func(double x)    //���㷽����˺�����(x)ֵ
  {
	  double y;
	  y = 6.0 - x*x;
	  return y;
  }

  void main ()      //������
  {
	  atkn  root(0.0, 0.000001, 20); 
	                    //�������󣬲������ĳ�ֵ������Ҫ��������������
	  root.atkn_root ();    //ִ��Aitken������
	  root.output ();     //��������ļ�����ʾ
  }

//x = 2