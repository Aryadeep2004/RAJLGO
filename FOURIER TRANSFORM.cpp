#include<iostream>
#include<complex>
using namespace std;
const double pi=acos(-1);
complex<double> *fft(complex<double> *s,int n,bool invert)
{
	complex<double> *a=new complex<double>[n];
	if (n==1)
    {
		a[0]=s[0];
	}
	else
    {
		complex<double> *x=new complex<double>[n/2];
		complex<double> *y=new complex<double>[n/2];
		for(int i=0;i<n/2;++i)
        {
			x[i]=s[2*i];
			y[i]=s[2*i+1];
		}
		complex<double> *b=fft(x,n/2,invert);
		complex<double> *c=fft(y,n/2,invert);
		delete [] x;
		delete [] y;
		double theta=2 * pi / n* ((invert)?-1:1);
		complex<double> p(1),w(cos(theta),sin(theta));
		for(int i=0;i<n/2;i++)
        {
			complex <double> term=p*c[i];
			a[i]=b[i]+term;
			a[i+n/2]=b[i]-term;
			if(invert)	
        {
			a[i]/=2;
			a[i/2]/=2;
			
		}
		    p=p*w;
	}
		
		
}
	return a;
	
}

int main()
{
	int n;
	cout<<"enter no of frequencies";
	cin>>n;
	complex<double> *s=new complex<double>[n];
	for(int i=0;i<n;i++)
    {
		cin>>s[i];
     }
	
	complex<double> *res=fft(s,n,false);
	for(int i=0;i<n;i++)
        {
		cout<<res[i];
	}
	
}

