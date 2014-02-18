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


	std::string MACedString;
	std::string password = "password";

	CryptoPP::StringSource ss
	( 
		destString, 
		true,
		new CryptoPP::DefaultEncryptorWithMAC
		(
			//"password",
			(byte*)password.data(),
			password.size(),
			new CryptoPP::HexEncoder
			( 
				new CryptoPP::StringSink( MACedString ) ,
				true,
				4,
				":"
			)
		)
	);

	std::cout << MACedString<< std::endl;

	std::string deMACedString;
	CryptoPP::StringSource
	(
		MACedString,
		true,
		new CryptoPP::HexDecoder
		(
			new CryptoPP::DefaultDecryptorWithMAC
			(
				(byte*)password.data(),
				password.size(),
				new CryptoPP::FileSink( "output.txt" )
			)
		)
	);

	//std::cout << deMACedString << std::endl;

	system("pause");

	return 0;
}

