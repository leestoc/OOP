//var 1
#include <iostream>
#include <cstring>

class Complex{
	public:
	Complex(double a, double b)
	:	a(a), b(b) {};
	double a;
	double b;
	
	Complex add(const Complex& c){
		return Complex(a+c.a, b+c.b);
	}
	Complex sub(const Complex& c){
		return Complex(a-c.a, b-c.b);
        }
	Complex mul(const Complex& c){
		return Complex(a*c.a-b*c.b, a*c.b+b*c.a);
        }
	Complex div(const Complex& c){
		return Complex((a*c.a+b*c.b)/(c.a*c.a+c.b*c.b), (b*c.a-a*c.b)/(c.a*c.a+c.b*c.b));
        }
	bool equ(const Complex& c){
		return (a==c.a) && (b==c.b);
        }
	Complex conj(){
		return Complex(a, -b);
        }
	bool bth(const Complex& c){
		return (a*a+b*b) > (c.a*c.a+c.b*c.b);
        }
	void print(){
		std::cout << '(' << a << ", " << b << ')';
	}
	Complex exec(const char* command, Complex c) {
		Complex answ(0, 0);
		if(strcmp(command,"a")==0){
			answ = this->add(Complex(c.a, c.b));
		} else if(strcmp(command,"s")==0){
			answ = this->sub(Complex(c.a, c.b));
		} else if(strcmp(command,"m")==0){
			answ = this->mul(Complex(c.a, c.b));
		} else if(strcmp(command,"d")==0){
			answ = this->div(Complex(c.a, c.b));
		} else if(strcmp(command,"c")==0){
			answ = this->conj();
		}
		return answ;
	}
};
