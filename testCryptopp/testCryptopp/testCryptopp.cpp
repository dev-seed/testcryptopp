// testCryptopp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::string dest;
	CryptoPP::FileSource( "test.txt", new CryptoPP::StringSink( dest ) );

	std::cout<< dest<<std::endl;

	return 0;
}

