  //4SNSE.CPP
  //�ݶȷ��������Է�����
  #include  <iostream>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  snse
  {
  private: 
           int n, Max;
		   double  *x, eps;
		   double  *f, **df, F, *dF;
  public:
	       snse (int nn)
		   {
			   int i;
			   n = nn;
               x = new double[n];   //��̬�����ڴ�
	           f = new double[n];
	           dF = new double[n];
	           df = new double*[n];
	           for (i=0; i<n; i++)  df[i] = new double[n];
		   }
	       void input ();          //���ļ����뾫��Ҫ��eps������������Max
		                           //�Լ����һ���ֵ
		   void snse_root ();      //ִ���ݶȷ�
           void output ();         //��������Է������һ��⵽�ļ�����ʾ
		   void func (double *);   //���㷽�������˺���ֵf�Լ�ƫ����ֵdf
		   ~snse ()
		   {
			   int k;
			   for (k=0; k<n; k++)  { delete [] df[k]; }
			   delete [] df;
			   delete [] x, f, dF;
		   }
  };

  void snse::input ()      //���ļ����뾫��Ҫ��eps������������Max
	                       //�Լ����һ���ֵ
  {
	  int  i;
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
	  fin >>eps;  fin >>Max;        //����eps��Max
	  for (i=0; i<n; i++)  fin>>x[i];     //�����ֵ
	  fin.close ();
  }

  void snse::snse_root ()         //ִ���ݶȷ�
  { 
	  int count,j,k;
      double d,s;
      count=Max;
	  func (x);
	  for (k=0; k<n; k++)
	  {
		  dF[k] = 0.0;
		  for (j=0; j<n; j++)
			  dF[k] = dF[k] + f[j]*df[j][k];
		  dF[k] = 2*dF[k];
	  }
      F = 0.0;
	  for (k=0; k<n; k++)  F = F+f[k]*f[k];
      while ((F>=eps)&&(count!=0))
      { 
		  count=count-1;
          d=0.0;
          for (k=0; k<=n-1; k++) d=d+dF[k]*dF[k];
          if (d+1.0==1.0) 
		  { 
			  cout <<"\n���������ֲ���ֵ�㣡�ı��ֵ����." <<endl;
			  return;
		  }
          s=F/d;
          for (j=0; j<=n-1; j++) x[j]=x[j]-s*dF[j];
          func (x);
	      for (k=0; k<n; k++)
		  {
		      dF[k] = 0.0;
		      for (j=0; j<n; j++)
			      dF[k] = dF[k] + f[j]*df[j][k];
		      dF[k] = 2*dF[k];
		  }
          F = 0.0;
	      for (k=0; k<n; k++)  F = F+f[k]*f[k];
      }
	  cout <<"\nʵ�ʵ�������Ϊ��" <<Max-count <<endl;
      if (count == 0)
		  cout <<"\nû�����㾫��Ҫ�����ܲ�������" <<endl;
  }

  void snse::output ()       //��������Է������һ��⵽�ļ�����ʾ
  {
	  int k;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
	  fout <<endl;  cout <<endl;
	  for (k=0; k<n; k++)
	  {
		  fout <<x[k] <<"   ";
		  cout <<x[k] <<"   ";
	  }
	  fout <<endl;  cout <<endl;
	  fout.close ();
  }

  void snse::func (double *x)//���㷽�������˺���ֵf�Լ�ƫ����ֵdf
  {
	  f[0] = x[0] - 5*x[1]*x[1] + 7*x[2]*x[2] + 12;
	  f[1] = 3*x[0]*x[1] +x[0]*x[2] - 11*x[0];
	  f[2] = 2*x[1]*x[2] + 40*x[0];
	  df[0][0] = 1;
	  df[0][1] = 10*x[1];
	  df[0][2] = 14*x[2];
	  df[1][0] = 3*x[1] + x[2] -11;
	  df[1][1] = 3*x[0];
	  df[1][2] = x[0];
	  df[2][0] = 40;
	  df[2][1] = 2*x[2];
	  df[2][2] = 2*x[1];
  }

  void main ()      //������
  {
	  snse  root(3); 
	  root.input ();      //���ļ����뾫��Ҫ��eps������������Max
	                       //�Լ����һ���ֵ
	  root.snse_root ();    //ִ���ݶȷ�
	  root.output ();      //��������Է������һ��⵽�ļ�����ʾ
  }

//1.00019   5.00043   -4.00039
//ʵ�ʵ���281��