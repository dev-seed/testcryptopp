// testCryptopp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::string destString, destHexCode;
	CryptoPP::FileSource( "test.txt", true, new CryptoPP::StringSink( destString ) );
	CryptoPP::FileSource( "test.txt", true, 
		new CryptoPP::HexEncoder( new CryptoPP::StringSink( destHexCode ) ,
			true,
			4,
			":"
			) 
		);

	std::cout<< destString<<std::endl<<std::endl;
	std::cout<< destHexCode<<std::endl<<std::endl;


	system("pause");

	return 0;
}

