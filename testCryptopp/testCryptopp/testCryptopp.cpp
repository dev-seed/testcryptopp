// testCryptopp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::string dest;
	CryptoPP::FileSource( "test.txt", new CryptoPP::StringSink( dest ) );

	std::cout<< dest<<std::endl;

	return 0;
}

