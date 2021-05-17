#include <iostream>
#include <string>

std::string encrypt_caesar(std::string words, char hash_number);
std::string decrypt_caesar(std::string hash, char hash_number);

const char hash_number = 25;
const char alphabet = 26;


int main(void)
{
	std::cout << "Enter worls: " << std::endl;
	std::string words;
	std::getline(std::cin, words);

	std::string hash = encrypt_caesar(words, hash_number);
	std::cout << std::endl << "Your hash: " << hash << std::endl << std::endl;
	std::string rehash = decrypt_caesar(hash, hash_number);
	std::cout << "Your rehash: " << rehash << std::endl << std::endl;

	if (rehash == words) std::cout << "!!!Success encryption!!!";
	else std::cout << "!!!FAIL!!!";
	return 0;
}

std::string encrypt_caesar(std::string words, char hash_number)
{
	const char border_az = 90 - hash_number;
	const char border_AZ = 122 - hash_number;
	for (int i = 0; i < words.length(); i++)
	{
		if (words[i] >= 65 and words[i] <= 90)
		{
			if (words[i] <= border_az)
			{
				words[i] += hash_number;
				continue;
			}
			else words[i] = words[i] + hash_number - alphabet;
		}
		if (words[i] >= 97 and words[i] <= 122)
		{
			if (words[i] <= border_AZ)
			{
				words[i] += hash_number;
				continue;
			}
			else words[i] = words[i] + hash_number - alphabet;
		}
	}
	return words;
}

std::string decrypt_caesar(std::string hash, char hash_number)
{
	const char border_az = 65 + hash_number;
	const char border_AZ = 97 + hash_number;
	for (int i = 0; i < hash.length(); i++)
	{
		if (hash[i] >= 65 and hash[i] <= 90)
		{
			if (hash[i] >= border_az)
			{
				hash[i] -= hash_number;
				continue;
			}
			else hash[i] = hash[i] - hash_number + alphabet;
		}
		if (hash[i] >= 97 and hash[i] <= 122)
		{
			if (hash[i] >= border_AZ)
			{
				hash[i] -= hash_number;
				continue;
			}
			else hash[i] = hash[i] - hash_number + alphabet;
		}
	}
	return hash;
}
