#pragma once
class ComplexNumber
{
	int numR;
	int numI; //По сути должна быть и мнимая единица i, но как тогда возращать число?
		      //Либо переводить (numI = 3) 3i в char, однако функция int теряется => комплексное число
			  //Будет иметь вид: 6 + 1, где 6 - действительное число, а 1 - мнимая часть с мнимой мнимой единицей :)
public:
	ComplexNumber(int r, int i) : numR{ r }, numI{ i } {};
	ComplexNumber() : ComplexNumber(1, 0) {};

	//Этот класс я не проверял, мне страшно
	


	ComplexNumber operator+ (ComplexNumber & p) {
		return ComplexNumber(numR + p.numR, numI + p.numI);
	}
	//При вычитании комплексных чисел, необходимо изменить знаки числа на противоположные
	//z1 = 5+4i,  z2 = 1-2i,  z1-z2 = 5+4i-(1-2i) => z1-z2 = 4+6i
	ComplexNumber operator- (ComplexNumber& p) {
		return ComplexNumber(numR + (p.numR*-1), numI + (p.numI*-1));
	} 
	//При умножении комплексных чисел необходимо лишь раскрыть скобки, c условием i^2 = -1
	//z1 = 5+4i, x2 = 1-2i,   z1*z2 = (5+4i)(1-2i) = 5 - 10i + 4 - 8i^2 = 9 - 10i - 8 * -1 = 17 + 10i
	ComplexNumber operator* (ComplexNumber& p) {
		return ComplexNumber(numR * p.numR, numI * numR + (numI * p.numI * -1) + numR * p.numI);
	}
	//При делении там бред бредом, однако математика:
	//Пример: z1 = 13 + i, x2 = 7 - 6i. z1/z2 = 13 + i / 7 - 6i (Применяя формулу a^2-b^2 смотрим
	//На знаменатель, где мы уже имее a-b, значит необходимо домножить дробь на a+b, т.е. в данном
	//Примере на 7 + 6i) => (13 + i)*(7 + 6i)/(7 - 6i)*(7 + 6i),   (i^2 = -1!) => 
	//z1/z2 = 91+ 7i+ 78i + 6i^2 / 7^2 - (6i)^2 = 91 + 7i + 78i - 6 / 49 - (-36) =
	//85i + 85 / 85 = 1 + i
	ComplexNumber* operator/ (ComplexNumber& p) {
		ComplexNumber tempNumerator(numR * p.numR, numI * p.numR + numI * p.numI + numR *p.numI); //Числитель
		//numR * p.numR - натуральное число, numI * p.numR + numI * p.numI( я не умножил на -1,
		//так как мы и и так уже изменяем знак (a^2-b^2), если же такого числа нет, будет нуль) + numR *p.numI
		ComplexNumber tempDenominator(p.numR * p.numR, p.numI * p.numR + p.numI ^ 2 + p.numR * p.numI);
		//p.numR * p.numR - действительная часть, p.numI * p.numR + p.numI^2 (Квадрат, так как (a+b)*(a-b)
		//И умножение на -1 не надо) +p.numR * p.numI - мнимая часть
		ComplexNumber* tempArr = new ComplexNumber[2];
		tempArr[0] = tempNumerator;
		tempArr[1] = tempDenominator;
		return tempArr;
	}

	int getNumR() {
		return numR;
	}
	int getNumI() {
		return numI;
	}
};

