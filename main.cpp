#include "CPUID.h"

#include <iostream>
#include <string>

using namespace std;

void vendorCpuId(void) {
	CPUID cpuID(0); // Get CPU vendor

	string vendor;
	vendor += string((const char*)&cpuID.EBX(), 4);
	vendor += string((const char*)&cpuID.EDX(), 4);
	vendor += string((const char*)&cpuID.ECX(), 4);

	cout << "CPU Vendor = " << vendor << endl;
}

int main(int argc, char* argv[]) {
	CPUID cpuID(1); // Get CPU Info and Feature Bits

	string vendor;
	vendor += string((const char*)&cpuID.EBX(), 4);
	vendor += string((const char*)&cpuID.EDX(), 4);
	vendor += string((const char*)&cpuID.ECX(), 4);

	vendorCpuId();
	cout << "Feature Bits = " << hex << cpuID.ECX() << endl << endl;

	system("pause");
	return 0;
}
