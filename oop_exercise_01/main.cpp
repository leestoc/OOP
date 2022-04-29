/*
Кочисов Алексей М8О-201Б-20
Комплексное число в алгебраической форме представляются парой действительных чисел (a, b), где a – действительная часть, b – мнимая часть. Реализовать класс Complex для работы с комплексными числами. Обязательно должны быть присутствовать операции
-         сложения add, (a, b) + (c, d) = (a + c, b + d);
-         вычитания sub, (a, b) – (c, d) = (a – c, b – d);
-         умножения mul, (a, b) ´ (c, d) = (ac – bd, ad + bc);
-         деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2);
-         сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
-         сопряженное число conj, conj(a, b) = (a, –b).
Реализовать операции сравнения модулей.
*/
#include <iostream>
#include <string>
#include "Complex.cpp"
#include <cstdio>
#include <set>
#include "Read_input.cpp"

int main(){
	char a[] = "You can use\n\
--add:\t a (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--subtraction:\t s (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--conjuction:\t c (real part of num) (imagin part of num)\n\
--multiply:\t m (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--division:\t d (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--equivalent:\t e (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--if num1 bigger than num2:\t bth (real part of num1) (imagin part of num1) (real part of num2) (imagin part of num2)\n\
--exit\n";
	Complex c1(0,0), c2(0,0);
	char ch(' ');
	char command[20] = {0};
	std::set<std::string> valid_commands = {"c", "a", "s", "m", "d", "e", "bth", "exit"};
	std::cout << a;
	do {
		bool exit = false;
		do{
			read_return_t answer = get_command(valid_commands, command);
			switch(answer) {
				case END_OF_FILE: return 0;
				case END_OF_LINE: continue;
				case VALID_INPUT: exit = true; break;
				case INVALID_INPUT:
					do ch=getchar(); while((ch != EOF) && (ch != '\n'));
					std::cout << "wrong input" << std::endl;
					if(ch == EOF) return 0;
					else break;
				}
		} while(!exit);
		if(static_cast<std::string>(command) == "exit") return 0;
		if((get_value<double>(c1.a) != VALID_INPUT) || (get_value<double>(c1.b) != VALID_INPUT)) {
			do ch = getchar(); while((ch != EOF) && (ch != '\n'));
			std::cout << "wrong input" << std::endl;
			if(ch == EOF) return 0;
			continue;
		}
		if(static_cast<std::string>(command) != "c") {
			if((get_value<double>(c2.a) != VALID_INPUT) || (get_value<double>(c2.b) != VALID_INPUT)) {
				do ch=getchar(); while((ch != EOF) && (ch != '\n'));
				std::cout << "wrong input" << std::endl;
				if(ch == EOF) return 0;
				continue;
			}
		}

		c1.print();
		std::cout << '\t' << command << '\t';
		if(static_cast<std::string>(command) != "c") {
			c2.print();
			std::cout << '\t';
		}
		std::cout << '\t' << '=' << '\t';

		if(static_cast<std::string>(command) == "c") {
			c1.conj().print();
		} else if (static_cast<std::string>(command) == "bth") {
			std::cout << c1.bth(c2) << std::endl;
		} else if(static_cast<std::string>(command) == "e") {
			std::cout << c1.equ(c2) << std::endl;
		} else {
			c1.exec(command, c2).print();
		}
		std::cout << std::endl;
	} while(true);
	return 0;
}
