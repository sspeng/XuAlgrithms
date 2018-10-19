  //7DFTE.CPP
  //������΢�ַ��̱�ֵ����
  #include  <iostream>
  #include  <iomanip>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  dfte
  {
  private: 
	       int n;
		   double  a, b, ya, yb, *y, u, v, w, f;
		   double  *g, *d;
  public:
	       dfte (int nn)
		   {
			   n = nn;
               y = new double[n];     //��̬�����ڴ�
	           d = new double[2*n];
	           g = new double[6*n];	
		   }
	       void  input ();       //���ļ��������ݳ�Աa,b,ya,yb
		   void solution ();    //ִ�����޲�ַ�
		   void trde (int,double*,double*); //ִ��׷�Ϸ�
           void output ();        //���n���Ⱦ���ɢ����
		                          //��δ֪����ֵ���ļ�����ʾ
		   void func (double);   
		                  //�������΢�ַ����еĺ���u(x),v(x),w(x),f(x)
		   ~dfte ()
		   { delete [] y, g, d;  }
  };

  void dfte::input ()     //���ļ��������ݳ�Աa,b,ya,yb
  {
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
      fin >>a >>b >>ya >>yb;        //����a,b,ya,yb  
	  fin.close ();
  }

  void dfte::solution ()   //ִ�����޲�ַ�
  { 
	  int i,k,nn;
      double h,x;
      h=(b-a)/(n-1.0); nn=2*n-1;
      g[0]=1.0; g[1]=0.0;
      y[0]=ya; y[n-1]=yb;
      g[3*n-3]=1.0; g[3*n-4]=0.0;
      for (i=2; i<=n-1; i++)
      { 
		  x=a+(i-1)*h;
          func (x);
          k=3*(i-1)-1;
          g[k]=u-h*v/2.0;
          g[k+1]=h*h*w-2.0*u;
          g[k+2]=u+h*v/2.0;
          y[i-1]=h*h*f;
      }
      trde(n,g,y);
      h=h/2.0;
      g[0]=1.0; g[1]=0.0;
      d[0]=ya; d[nn-1]=yb;
      g[3*nn-3]=1.0; g[3*nn-4]=0.0;
      for (i=2; i<=nn-1; i++)
      { 
		  x=a+(i-1)*h;
          func (x);
          k=3*(i-1)-1;
          g[k]=u-h*v/2.0;
          g[k+1]=h*h*w-2.0*u;
          g[k+2]=u+h*v/2.0;
          d[i-1]=h*h*f;
      }
      trde(nn,g,d);
      for (i=2; i<=n-1; i++)
      { 
		  k=i+i-1;
          y[i-1]=(4.0*d[k-1]-y[i-1])/3.0;
      }
  }

  void dfte::trde (int n, double b[], double d[])  //ִ��׷�Ϸ�
  { 
	  int k,j,m;
      double s;
      m= 3*n-2;
      for (k=0;k<=n-2;k++)
      { 
		  j=3*k; s=b[j];
          if (fabs(s)+1.0==1.0)
          { 
			  cout <<"\n������ʧ�ܣ��޽�. " <<endl;
			  return;
		  }
          b[j+1]=b[j+1]/s;
          d[k]=d[k]/s;
          b[j+3]=b[j+3]-b[j+2]*b[j+1];
          d[k+1]=d[k+1]-b[j+2]*d[k];
      }
      s=b[3*n-3];
      if (fabs(s)+1.0==1.0)
      { 
		  cout <<"\n������ʧ�ܣ��޽�. " <<endl;
		  return;
	  }
      d[n-1]=d[n-1]/s;
      for (k=n-2;k>=0;k--)
          d[k]=d[k]-b[3*k+1]*d[k+1];
  }


  void dfte::output ()    //���n���Ⱦ���ɢ����
		                          //��δ֪����ֵ���ļ�����ʾ
  {
	  int i;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
      for (i=0; i<n; i++)
	  {
		  cout <<"x = " <<a+i*(b-a)/(n-1) <<"     " <<"y = " <<y[i] <<endl;
		  fout <<a+i*(b-a)/(n-1) <<"     " <<y[i] <<endl;
	  }
	  fout.close ();
  }

  void dfte::func (double x)
  {
	  u = -1.0;
	  v = 0.0;
	  w = 2.0/(x*x);
	  f = 1.0/x;
  }

  void main ()      //������
  {
	  dfte  s(11);           //��������
	  s.input ();        //���ļ��������ݳ�Աa,b,ya,yb
	  s.solution ();    //ִ�����޲�ַ�
	  s.output ();      //���n���Ⱦ���ɢ����
		                          //��δ֪����ֵ���ļ�����ʾ
  }
