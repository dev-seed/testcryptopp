// testCryptopp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	//////////////////////////////////////////////////////////////////////////
	//			File Encrypt/Decrypt Test
	//////////////////////////////////////////////////////////////////////////
	std::string password = "password";

	CryptoPP::FileSource
		( 
		"testinput.xml", 
		true,
		new CryptoPP::DefaultEncryptorWithMAC
		(
		//"password",
		(byte*)password.data(),
		password.size(),
		new CryptoPP::HexEncoder
		( 
		new CryptoPP::FileSink( "testoutput.dat" )
		)
		)
	);


	CryptoPP::FileSource
		(
		"testoutput.dat",
		true,
		new CryptoPP::HexDecoder
		(
			new CryptoPP::DefaultDecryptorWithMAC
			(
				(byte*)password.data(),
				password.size(),
				new CryptoPP::FileSink( "output.xml" )
			)
		)
	);





	/*
	*	//////////////////////////////////////////////////////////////////////////
	//		Source/Sink and MAC TEST
	//////////////////////////////////////////////////////////////////////////
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
	//////////////////////////////////////////////////////////////////////////
	*/





	/*
	//////////////////////////////////////////////////////////////////////////
	//		AES TEST
	//////////////////////////////////////////////////////////////////////////
	byte Key[CryptoPP::AES::DEFAULT_KEYLENGTH] = {0,};
	byte IV[CryptoPP::AES::BLOCKSIZE] = {0xFF, };

	printf("temp AES BlockSize : %d\n\n", CryptoPP::AES::BLOCKSIZE);

	byte PlainData[1024] = { 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11,  };

	byte CipherData[1408] = {0,};

	byte DecipheredData[1024] = {0,};

	std::string tempString;

	HexEncoder encoder1;
	encoder1.Put( PlainData, sizeof(PlainData) );
	encoder1.MessageEnd();
	word64 tempSize = encoder1.MaxRetrievable();
	if ( tempSize )
	{
		tempString.resize((size_t)tempSize);
		encoder1.Get( (byte*)tempString.data(), tempString.size() );
	}

	printf("PlainData(%s)\nMaxRetrievableSize(%llu)\nsizeof(data)(%u)\nstring.size()(%u)\n\n",
			tempString.c_str(), tempSize, sizeof(PlainData), tempString.size());


	ECBEncrypt<CryptoPP::AES>(Key, PlainData, sizeof(PlainData), CipherData, sizeof(CipherData));
	//CBCEncrypt<CryptoPP::AES>( Key, IV,  PlainData, sizeof(PlainData), CipherData, sizeof(CipherData));;

	tempString.clear();
	HexEncoder encoder2;
	encoder2.Put( CipherData, sizeof(CipherData) );
	encoder2.MessageEnd();
	tempSize = encoder2.MaxRetrievable();
	if ( tempSize )
	{
		tempString.resize((size_t)tempSize);
		encoder2.Get( (byte*)tempString.data(), tempString.size() );
	}

	printf("CipherData(%s)\nMaxRetrievableSize(%llu)\nsizeof(data)(%u)\nstring.size()(%u)\n\n",
		tempString.c_str(), tempSize, sizeof(CipherData),tempString.size());


	



	ECBDecrypt<CryptoPP::AES>(Key, CipherData, sizeof(CipherData), DecipheredData, sizeof(DecipheredData));
	//CBCDecrypt<CryptoPP::AES>( Key, IV, CipherData, sizeof(CipherData), DecipheredData, sizeof(DecipheredData));
	
	tempString.clear();
	HexEncoder encoder3;
	encoder3.Put( DecipheredData, sizeof(DecipheredData) );
	encoder3.MessageEnd();
	tempSize = encoder3.MaxRetrievable();
	if ( tempSize )
	{
		tempString.resize((size_t)tempSize);
		encoder3.Get( (byte*)tempString.data(), tempString.size() );
	}

	//std::cout << "DecipheredData : "<< tempString<< "\tRetrievableSize :" << tempSize <<std::endl;
	printf("DecipheredData(%s)\nMaxRetrievableSize(%llu)\nsizeof(data)(%u)\nstring.size()(%u)\n\n",
		tempString.c_str(), tempSize, sizeof(DecipheredData),tempString.size());
	//////////////////////////////////////////////////////////////////////////
	*/




	system("pause");

	return 0;
}

