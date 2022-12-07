#pragma once
class ComplexNumber
{
	int numR;
	int numI; //�� ���� ������ ���� � ������ ������� i, �� ��� ����� ��������� �����?
		      //���� ���������� (numI = 3) 3i � char, ������ ������� int �������� => ����������� �����
			  //����� ����� ���: 6 + 1, ��� 6 - �������������� �����, � 1 - ������ ����� � ������ ������ �������� :)
public:
	ComplexNumber(int r, int i) : numR{ r }, numI{ i } {};
	ComplexNumber() : ComplexNumber(1, 0) {};

	//���� ����� � �� ��������, ��� �������
	


	ComplexNumber operator+ (ComplexNumber & p) {
		return ComplexNumber(numR + p.numR, numI + p.numI);
	}
	//��� ��������� ����������� �����, ���������� �������� ����� ����� �� ���������������
	//z1 = 5+4i,  z2 = 1-2i,  z1-z2 = 5+4i-(1-2i) => z1-z2 = 4+6i
	ComplexNumber operator- (ComplexNumber& p) {
		return ComplexNumber(numR + (p.numR*-1), numI + (p.numI*-1));
	} 
	//��� ��������� ����������� ����� ���������� ���� �������� ������, c �������� i^2 = -1
	//z1 = 5+4i, x2 = 1-2i,   z1*z2 = (5+4i)(1-2i) = 5 - 10i + 4 - 8i^2 = 9 - 10i - 8 * -1 = 17 + 10i
	ComplexNumber operator* (ComplexNumber& p) {
		return ComplexNumber(numR * p.numR, numI * numR + (numI * p.numI * -1) + numR * p.numI);
	}
	//��� ������� ��� ���� ������, ������ ����������:
	//������: z1 = 13 + i, x2 = 7 - 6i. z1/z2 = 13 + i / 7 - 6i (�������� ������� a^2-b^2 �������
	//�� �����������, ��� �� ��� ���� a-b, ������ ���������� ��������� ����� �� a+b, �.�. � ������
	//������� �� 7 + 6i) => (13 + i)*(7 + 6i)/(7 - 6i)*(7 + 6i),   (i^2 = -1!) => 
	//z1/z2 = 91+ 7i+ 78i + 6i^2 / 7^2 - (6i)^2 = 91 + 7i + 78i - 6 / 49 - (-36) =
	//85i + 85 / 85 = 1 + i
	ComplexNumber* operator/ (ComplexNumber& p) {
		ComplexNumber tempNumerator(numR * p.numR, numI * p.numR + numI * p.numI + numR *p.numI); //���������
		//numR * p.numR - ����������� �����, numI * p.numR + numI * p.numI( � �� ������� �� -1,
		//��� ��� �� � � ��� ��� �������� ���� (a^2-b^2), ���� �� ������ ����� ���, ����� ����) + numR *p.numI
		ComplexNumber tempDenominator(p.numR * p.numR, p.numI * p.numR + p.numI ^ 2 + p.numR * p.numI);
		//p.numR * p.numR - �������������� �����, p.numI * p.numR + p.numI^2 (�������, ��� ��� (a+b)*(a-b)
		//� ��������� �� -1 �� ����) +p.numR * p.numI - ������ �����
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

