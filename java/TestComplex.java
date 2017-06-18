/* TestComplex.java
 * last modified 96/08/07 ver. 0.2
 */

/*
 * usage:
 * > java TestComplex
 */

public class TestComplex {

	public static void main(String args[]){

		Complex a,b,c,d,e;
		a = new Complex(3.0,1.0);
		b = new Complex(2.0,-1.0);
		c = new Complex();
		d = new Complex();
		e = new Complex();
	
		c = c.multiply(a,b);
		d = d.divide(a,b);
		e = a.conj();
	
		System.out.println("a= "+ a.ComplextoString());
		System.out.println("b= "+ b.ComplextoString());
		System.out.println("a*b= "+ c.ComplextoString());
		System.out.println("a/b= "+ d.ComplextoString());

		System.out.println("conj(a)= "+ e.ComplextoString());
		System.out.println("abs(a)= "+ a.abs());
	}
}
