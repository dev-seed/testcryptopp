#pragma once

using namespace CryptoPP;

template<class Mode>
std::string Encrypt(Mode &Encryptor, const std::string &PlainText)
{
	std::string CipherText;

	StringSource( PlainText, true,
		new StreamTransformationFilter( Encryptor, 
		new Base64Encoder( new StringSink( CipherText ), false ), BlockPaddingSchemeDef::ZEROS_PADDING
		)
		);

	return CipherText;
};

template <class Mode>
std::string Decrypt(Mode &Decryptor, const std::string &CipherText)
{
	std::string PlainText;

	StringSource( CipherText, true,
		new Base64Decoder(
		new StreamTransformationFilter( Decryptor, new StringSink( PlainText ), BlockPaddingSchemeDef::ZEROS_PADDING )
		)
		);

	return PlainText;
}


template<class Mode>
std::string ECBEncrypt(byte *Key, const std::string &PlainText)
{
	ECB_Mode<Mode>::Encryption Encryptor(Key, Mode::DEFAULT_KEYLENGTH);
	
	return Encrypt( Encryptor, PlainText );
};

template<class Mode>
std::string ECBDecrypt(byte *Key, const std::string &CipherText)
{
	ECB_Mode<Mode>::Decryption Decryptor(Key, Mode::DEFAULT_KEYLENGTH);

	return Decrypt(Decryptor, CipherText);
};


