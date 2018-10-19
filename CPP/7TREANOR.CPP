  //7TREANOR.CPP
  //Treanor����
  #include  <iostream>
  #include  <iomanip>
  #include  <fstream>
  #include  <cmath>
  using namespace std;
  class  treanor
  {
  private: 
	       int n, k;
		   double  t, h, *y, **z;
		   double  *d, *p, *w, *q, *r;
  public:
	       treanor (int nn, int kk)
		   {
			   int i;
			   n = nn; k = kk;
               y = new double[n];   //��̬�����ڴ�
	           d = new double[n];
	           p = new double[n];
	           w = new double[4*n];
	           q = new double[4*n];
	           r = new double[4*n];
	           z = new double*[n];
	           for (i=0; i<n; i++) { z[i] = new double[k]; }
		   }
	       void  input ();         //���ļ��������ݳ�Աt,h
		                      //�Լ�n��δ֪��������ʼ��t���ĺ���ֵ
		   void solution ();    //ִ��Treanor����
           void output ();        //���k�����ֵ���
		                          //��δ֪����ֵ���ļ�����ʾ
		   void func (double,double*,double*);   
		                         //����΢�ַ������и������Ҷ˺���ֵ
		   ~treanor ()
		   { 
			   int i;
			   for (i=0; i<n; i++) { delete [] z[i]; }
			   delete [] z;
			   delete [] y, d, p, w, q, r;
		   }
  };

  void treanor::input ()     //���ļ��������ݳ�Աt,h
		                      //�Լ�n��δ֪��������ʼ��t���ĺ���ֵ
  {
	  int  i;
	  char str1[20];
	  cout <<"\n�����ļ���:  ";
	  cin >>str1;
	  ifstream  fin (str1);
	  if (!fin)
	  { cout <<"\n���ܴ�����ļ� " <<str1 <<endl; exit(1); }
      fin >>t >>h;        //����t,h
      for (i=0; i<n; i++)  fin >>y[i];  
	                            //����n��δ֪��������ʼ��t���ĺ���ֵ	  
	  fin.close ();
  }

  void treanor::solution ()  //ִ��Treanor����
  { 
	  int j, i;
      double a,s,aa,bb,dd,g,dy,dy1;
	  a = t;
	  for (i=0; i<k; i++)
	  {
		  t = a + i*h;
          for (j=0; j<=n-1; j++) w[j]=y[j];
          func (t,y,d);
          for (j=0; j<=n-1; j++)
		  { 
			  q[j]=d[j]; y[j]=w[j]+h*d[j]/2.0;
              w[n+j]=y[j];
		  }
          s=t+h/2.0;
          func (s,y,d);
          for (j=0; j<=n-1; j++)
		  { 
			  q[n+j]=d[j];
              y[j]=w[j]+h*d[j]/2.0;
              w[n+n+j]=y[j];
		  }
          func (s,y,d);
          for (j=0; j<=n-1; j++) q[n+n+j]=d[j];
          for (j=0; j<=n-1; j++)
		  { 
			  aa=q[n+n+j]-q[n+j];
              bb=w[n+n+j]-w[n+j];
              if (-aa*bb*h>0.0)
			  { 
				  p[j]=-aa/bb; dd=-p[j]*h;
                  r[j]=exp(dd);
                  r[n+j]=(r[j]-1.0)/dd;
                  r[n+n+j]=(r[n+j]-1.0)/dd;
                  r[3*n+j]=(r[n+n+j]-1.0)/dd;
			  }
              else p[j]=0.0;
              if (p[j]<=0.0) g=q[n+n+j];
              else
			  { 
				  g=2.0*(q[n+n+j]-q[j])*r[n+n+j];
                  g=g+(q[j]-q[n+j])*r[n+j]+q[n+j];
			  }
              w[3*n+j]=w[j]+g*h;
              y[j]=w[3*n+j];
		  }
          s=t+h;
          func (s,y,d);
          for (j=0; j<=n-1; j++) q[3*n+j]=d[j];
          for (j=0; j<=n-1; j++)
		  { 
			  if (p[j]<=0.0)
			  { 
				  dy=q[j]+2.0*(q[n+j]+q[n+n+j]);
                  dy=(dy+q[n+n+n+j])*h/6.0;
			  }
              else
			  { 
				  dy=-3.0*(q[j]+p[j]*w[j])+2.0*(q[n+j]
                                          +p[j]*w[n+j]);
                  dy=dy+2.0*(q[n+n+j]+p[j]*w[n+n+j]);
                  dy=dy-(q[n+n+n+j]+p[j]*w[n+n+n+j]);
                  dy=dy*r[n+n+j]+q[j]*r[n+j];
                  dy1=q[j]-q[n+j]-q[n+n+j]+q[n+n+n+j];
                  dy1=dy1+(w[j]-w[n+j]-w[n+n+j]+w[n+n+n+j])*p[j];
                  dy=(dy+4.0*dy1*r[n+n+n+j])*h;
			  }
              y[j]=w[j]+dy;
		  }
	      for (j=0; j<n; j++)  z[j][i] = y[j];
	  }
      t = a;
  }

  void treanor::output ()   //���k�����ֵ���
	                      //��δ֪����ֵ���ļ�����ʾ
  {
	  int i, j;
	  char str2[20];
	  cout <<"\n����ļ���:  ";
	  cin >>str2;
	  ofstream fout (str2);
	  if (!fout)
	  { cout <<"\n���ܴ�����ļ� " <<str2 <<endl; exit(1); }
      for (i=0; i<k; i++)
	  {
		  cout <<"t = " <<t+(i+1)*h <<endl;
		  for (j=0; j<n; j++)
		  {
			  fout <<z[j][i] <<"   ";
			  cout <<"y(" <<j <<")=" <<setw(12) <<z[j][i] <<"  ";
		  }
		  fout <<endl;  cout <<endl;
	  }
	  fout.close ();
  }

  void treanor::func (double t, double y[], double d[])
  {
	  d[0] = -21*y[0] + 19*y[1] -20*y[2];
	  d[1] = 19*y[0] - 21*y[1] + 20*y[2];
	  d[2] = 40*y[0] - 40*y[1] - 40*y[2];
  }

  void main ()      //������
  {
	  treanor  s(3, 10);           //��������
	  s.input ();        //���ļ��������ݳ�Աt,h
		                 //�Լ�n��δ֪��������ʼ��t���ĺ���ֵ
	  s.solution ();    //ִ��Treanor����
	  s.output (); //���k�����ֵ��ϵ�δ֪����ֵ���ļ�����ʾ
  }
