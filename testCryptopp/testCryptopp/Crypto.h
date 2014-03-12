#pragma once

using namespace CryptoPP;

template<class CryptoModeDecryptor>
void Encrypt(CryptoModeDecryptor &Encryptor, byte* PlainData, size_t SizeOfPlainData, __out byte* CipherData, size_t SizeOfCipherData)
{
	ArraySource( PlainData, SizeOfPlainData, true,
		new StreamTransformationFilter( Encryptor, 
		new Base64Encoder( new ArraySink( CipherData, SizeOfCipherData ), false ), BlockPaddingSchemeDef::NO_PADDING
		)
	);
};

template <class CryptoModeDecryptor>
void Decrypt(CryptoModeDecryptor &Decryptor, byte *CipherData, size_t SizeOfCipherData, __out byte *PlainData, size_t SizeOfPlainData)
{
	ArraySource( CipherData, SizeOfCipherData, true,
		new Base64Decoder(
		new StreamTransformationFilter( Decryptor, new ArraySink( PlainData, SizeOfPlainData ), BlockPaddingSchemeDef::NO_PADDING )
		)
	);
}

template<class CryptoMode>
void CBCEncrypt(byte *Key, byte* IV, byte *PlainData, size_t SizeOfPlainData, __out byte *CipherData, size_t SizeOfCipherData)
{
	CBC_Mode<CryptoMode>::Encryption Encryptor(Key, CryptoMode::DEFAULT_KEYLENGTH, IV);

	Encrypt( Encryptor, PlainData, SizeOfPlainData, CipherData, SizeOfCipherData );
}

template<class CryptoMode>
void CBCDecrypt( byte *Key, byte* IV, byte *CipherData, size_t SizeOfCipherData, __out byte *PlainData, size_t SizeOfPlainData )
{
	CBC_Mode<CryptoMode>::Decryption Decryptor(Key, CryptoMode::DEFAULT_KEYLENGTH, IV);

	Decrypt( Decryptor, CipherData, SizeOfCipherData, PlainData, SizeOfPlainData );
}

template<class CryptoMode>
void ECBEncrypt(byte *Key, byte *PlainData, size_t SizeOfPlainData, __out byte *CipherData, size_t SizeOfCipherData)
{
	ECB_Mode<CryptoMode>::Encryption Encryptor(Key, CryptoMode::DEFAULT_KEYLENGTH);
	
	Encrypt( Encryptor, PlainData, SizeOfPlainData, CipherData, SizeOfCipherData  );
};

template<class CryptoMode>
void ECBDecrypt(byte *Key, byte *CipherData, size_t SizeOfCipherData, __out byte *PlainData, size_t SizeOfPlainData)
{
	ECB_Mode<CryptoMode>::Decryption Decryptor(Key, CryptoMode::DEFAULT_KEYLENGTH);

	return Decrypt(Decryptor, CipherData, SizeOfCipherData, PlainData, SizeOfPlainData);
};


