/* Complex.java
 * last modified 96/08/07 ver. 0.2
 *
 *
 * constructors
 *      Complex();
 *      Complex(double,double);
 *
 * methods
 *      conj();abs();
 *      plus();minus();multiply();divide();
 *      ComplextoString();StringtoComplex();
 */

/* TODO
 *
 * StringtoComplex()をつくる
 *
 * もっとmethodを作りたいが資料は京都に置いてある ^^;;
 */


public class Complex {

	//constructors
	double Re,Im;
	Complex(double u,double v){Re = u; Im = v;}
	Complex(){ this(0.0,0.0); }

	//methods
	public Complex conj(){		//conjugate(a)
		Complex c = new Complex();
		c.Re = Re;
		c.Im = Im * (-1.0);
		return c;
	}

	public double abs(){			//|a|
		return Math.sqrt( Re*Re + Im*Im );
	}

	public Complex plus(Complex a,Complex b){	//a+b
		Complex c = new Complex();
		c.Re = a.Re + b.Re;
		c.Im = a.Im + b.Im;
		return c;
	}

	public Complex minus(Complex a,Complex b){	//a-b
		Complex c = new Complex();
		c.Re = a.Re - b.Re;
		c.Im = a.Im - b.Im;
		return c;
	}

	public Complex multiply(Complex a,Complex b){	//a*b
		Complex c = new Complex();
		c.Re = a.Re * b.Re - a.Im * b.Im;
		c.Im = a.Re * b.Im + a.Im * b.Re;
		return c;
	}

	public Complex divide(Complex a,Complex b){	//a/b
		Complex c = new Complex();
		c = multiply(a,b.conj());
		double d = b.Re * b.Re + b.Im * b.Im;
		c.Re = c.Re / d;
		c.Im = c.Im / d;
		return c;
	}

	public String ComplextoString(){
		if(Im == 1.0){
			if(Re == 0.0){
				return "i";
			}
			return Double.toString(Re)+"+i";
		}else if(Im == -1.0){
			if(Re == 0.0){
				return "-i";
			}
			return Double.toString(Re)+"-i";
		}else if(Im == 0.0){
			return Double.toString(Re);
		}else if(Im < 0.0){
			if(Re == 0.0){
				return Double.toString(Im)+"i";
			}
			return Double.toString(Re)+Double.toString(Im)+"i";
		}
		return Double.toString(Re)+"+"+Double.toString(Im)+"i";
	}

	//public Complex StringtoComplex(String s){
	//}
}

