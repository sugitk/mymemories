/*                          */
/* 円周率の計算 C++ version */
/*                          */

#include <iostream.h>

// M*4 が 桁数
#define M 256 

class CMpa // Class multiple-precision arithmetic
{
	int a[M];
public:
	CMpa();

	CMpa operator+(CMpa obj);
	CMpa operator-(CMpa obj);
	CMpa operator*(int n);
	CMpa operator/(int n);
	CMpa operator=(CMpa obj);

	int get_element(int n);

	CMpa cmpa_arctan(int n);	// arctan(1/5) -> CMpa::arctan(5)
};

CMpa::CMpa()
{
	for(int i=0;i<M;i++) a[i]=0;
}

CMpa CMpa::operator+(CMpa obj)
{
	CMpa temp;

	int kuriagari = 0;
	int add;

	for(int i=M-1;i>=0;i--)
	{
		add = a[i] + obj.a[i] + kuriagari;
		if(add > 10000)
		{
			temp.a[i] = add - 10000;
			kuriagari = 1;
		}
		else
		{
			temp.a[i] = add;
			kuriagari = 0;
		}
	}	

	return temp;
}

CMpa CMpa::operator-(CMpa obj)
{
	CMpa temp;

	int kari = 0;
	int sub;

	for(int i=M-1;i>=0;i--)
	{
		sub = a[i] - kari;
		if(sub < obj.a[i])
		{
			temp.a[i] = sub + 10000 - obj.a[i];
			kari = 1;
		}
		else
		{
			temp.a[i] = sub - obj.a[i];
			kari = 0;
		}
	}

	return temp;
}

CMpa CMpa::operator*(int n)
{
	CMpa temp;

	int kuriagari = 0;
	int mul;

	for(int i=M-1;i>=0;i--)
	{
		mul = a[i] * n + kuriagari;
		if(mul > 10000)
		{
			temp.a[i] = mul % 10000;
			kuriagari = mul / 10000;
		}
		else
		{
			temp.a[i] = mul;
			kuriagari = 0;
		}
	}

	return temp;
}

CMpa CMpa::operator/(int n)
{
	CMpa temp;

	int amari = 0;
	int div;

	for(int i=0;i<M;i++)
	{
		div = a[i] + amari * 10000;
		temp.a[i] = div / n;
		amari = div % n;
	}

	return temp;
}

CMpa CMpa::operator=(CMpa obj)
{
	for(int i=0;i<M;i++)
	{
		a[i] = obj.a[i];	
	}

	return *this;
}

int CMpa::get_element(int n)
{
	return a[n];	
}

void print_CMpa(CMpa obj)
{
	cout << obj.get_element(0) << '.';

	for(int i=1;i<M;i++)
	{
		cout.width(4);
		cout.fill('0');
		cout << obj.get_element(i);
	}
	cout << endl;
}

CMpa CMpa::cmpa_arctan(int n)
{
	CMpa u,v,temp;

	u.a[0] = 1;
	u = u / n;
	temp = u;

	int fugou = -1;
	for(int j=1;j<4*M;j++)
	{
		u = u / n;
		u = u / n;
		v = u / (2*j+1);
		if(fugou == -1)
		{
			temp = temp - v;
			fugou = 1;
		}
		else
		{
			temp = temp + v;
			fugou = -1;
		}
	}

	return temp;
}

int main()
{
	CMpa x;

	print_CMpa((x.cmpa_arctan(5))*16 - (x.cmpa_arctan(239))*4);
	
	return 0;
}
