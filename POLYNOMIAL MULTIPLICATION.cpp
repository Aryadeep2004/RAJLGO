#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
const double PI = acos(-1);
complex<double>* FFT(complex<double>* S, int N, bool invert)
{
    complex<double>* A = new complex<double>[N];
    if (N == 1)
    {
        A[0] = S[0];
        return A;
    }
    else
    {
        complex<double>* X = new complex<double>[N / 2];
        complex<double>* Y = new complex<double>[N / 2];
        for (int i = 0; i < N / 2; ++i)
        {
            X[i] = S[2 * i];
            Y[i] = S[2 * i + 1];
        }
        complex<double>* B = FFT(X, N / 2, invert);
        complex<double>* C = FFT(Y, N / 2, invert);
        delete[] X;
        delete[] Y;
        double theta = 2 * PI / N * (invert ? -1 : 1);
        complex<double> P(1), W(cos(theta), sin(theta));
        for (int i = 0; i < N / 2; ++i)
        {
            complex<double> term = P * C[i];
            A[i] = B[i] + term;
            A[i + N / 2] = B[i] - term;
            if (invert) {
                A[i] /= 2;
                A[i + N/2] /= 2;
            }
            P = P * W;
        }
        delete[] B;
        delete[] C;
        return A;
    }
}
void pm(double p[],double q[],int x,int y)
{
    int n=1;
    while (n<x+y-1)n*=2;
    complex<double> *a=new complex<double>[n];
    complex<double> *b=new complex<double>[n];
    for(int i=0;i<n;++i)
    {
        a[i]=(i<x)?complex<double>(p[i],0):0;
        b[i]=(i<y)?complex<double>(q[i],0):0;
    }
    complex<double> *fa=FFT(a,n,false);
    complex<double> *fb=FFT(b,n,false);
    delete[] a;
    delete[] b;
    for(int i=0;i<n;++i)
    {
        fa[i]*=fb[i];
    }
    delete[] fb;
    complex<double> *ifa=FFT(fa,n,true);
    double res[n];
    for(int i=0;i<n;i++)
    {
        res[i]=ifa[i].real();
    }
    cout<<"result";
    for(int i=0;i<x+y-1;i++)
    {
        cout<<res[i];
    }
}
int main() 
{
    int x,y;
    cout<<"enter size of 1st poly";
    cin>>x;
    cout<<"enter size of 2nd poly";
    cin>>y;
    double *t=new double[x];
    double *u=new double[y];
    cout<<"enter eles of 1st poly";
    for(int i=0;i<x;i++)
    {
        cin>>t[i];
    }
    cout<<"enter eles of 2nd poly";
    for(int i=0;i<y;i++)
      {
        cin>>u[i];
    }
    pm(t,u,x,y);
    return 0;
}

