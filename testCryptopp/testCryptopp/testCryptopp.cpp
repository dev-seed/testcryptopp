// testCryptopp.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	byte Key[CryptoPP::AES::DEFAULT_KEYLENGTH] = {0,};
	
	std::string PlainText = "s";
	std::string CipherText;
	std::string DecipheredText;

	std::cout<<"PlainText:"<<PlainText<<"\tsize:"<<PlainText.length()<<std::endl;

	CipherText = ECBEncrypt<CryptoPP::AES>(Key, PlainText);

	std::cout<<"CipherText:"<<CipherText<<"\tsize:"<<CipherText.length()<<std::endl;

	DecipheredText = ECBDecrypt<CryptoPP::AES>(Key, CipherText);

	std::cout<<"DecryptedText:"<<DecipheredText<<"\tsize:"<<DecipheredText.length()<<std::endl;



	system("pause");

	return 0;
}

