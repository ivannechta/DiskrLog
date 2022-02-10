#pragma once
#include "Number.h"
class DiscrLog {
private:
	Number A;
	Number P,Y;	
	int Power;
public:
	DiscrLog(Number p,Number y) {		
		A = Number((char*)"1");
		P = p;
		Y = y;
		Power = 0;	
	}

	int Snosim() {
		int i = 0;
		while (A.GetSize() < P.GetSize()) {
			A << 0; i++;
		}
		return i;
	}

	void Divide() {		

		while (A != Y) {
			if (A.GetSize()<P.GetSize()){ 
				A << 0; Power++;
			}
			else {				
				A = (A + P);				
				-A;				
			}
		}
	}

	inline int GetPower() {
		return 1 + Power;
	}

};
