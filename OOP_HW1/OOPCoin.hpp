#ifndef OOPCoin_hpp
#define OOPCoin_hpp

#include <iostream>
#include <fstream>
#include <cstring>


//Note : put your file paths here, I use Xcode for mac and thats why I use this kind of method, in case there is a better way please write me feedback!

const char USERS_FILE_PATH[128] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/OOP_HW1/OOP_HW1/users.dat";
const char TRANSACTIONS_FILE_PATH[128] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/OOP_HW1/OOP_HW1/transactions.dat";
const char TRANSACTON_BLOCK_FILE_PATH[128] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/OOP_HW1/OOP_HW1/blocks.dat";
const char WEALTHIEST_USERS_FILE_PATH[128] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/OOP_HW1/OOP_HW1/wealthiest_users.txt";
const char BIGGEST_BLOCKS_FILE_PATH[128] = "/Users/dzhemshenolov/Documents/FMI/OOP at FMI/OOP_HW1/OOP_HW1/biggest_blocks.txt";

//Note : I HAVE also changed biggest-blocks, wealthiest-users and verify-transaction names, check them they are called BB, WU, VT

//Note : I have somekind of problem that block with index 0 and index 1 get created at the same time, but other stuff are ok - meaning that the first block gets created twice with index 0 and 1, others are completely okay based on testing


unsigned computeHash(const unsigned char *memory, int length)
{
    unsigned hash = 0xbeaf;
    
    for (int c = 0; c < length; c++)
    {
        hash += memory[c];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    
    return hash;
}

struct User
{
    unsigned id;
    char name[128];
};

struct Transaction
{
    unsigned sender;
    unsigned receiver;
    double coins;
    long long time;
};

struct TransactionBlock
{
    unsigned id;
    unsigned prevBlockId;
    unsigned prevBlockHash;
    int validTransactions;
    Transaction transactions[16];
};

//counter of the number of users
unsigned countUsers(const char* filePath)
{
    std::ifstream inputStream(filePath, std::ios::binary);
    if (!inputStream || !inputStream.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
        return 0;
    }
    inputStream.seekg(0, std::ios::end);
    unsigned streamPtr = (unsigned)inputStream.tellg();
    
    unsigned count = streamPtr / sizeof(User);
    
    inputStream.close();
    
    return count;
}

//counter transactions
unsigned countTransactions(const char* filePath)
{
    std::ifstream inputStream(filePath, std::ios::binary);
    if (!inputStream || !inputStream.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
        return 0;
    }
    inputStream.seekg(0, std::ios::end);
    unsigned streamPtr = (unsigned)inputStream.tellg();
    
    unsigned count = streamPtr / sizeof(Transaction);
    
    inputStream.close();
    
    return count;
}

//counter of the number of transactions blocks
unsigned countTransactionBlocks(const char* filePath)
{
    std::ifstream inputStream(filePath, std::ios::binary);
    if (!inputStream || !inputStream.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
        return 0;
    }
    inputStream.seekg(0, std::ios::end);
    unsigned streamPtr = (unsigned)inputStream.tellg();
    
    unsigned count = streamPtr / sizeof(TransactionBlock);
    
    inputStream.close();
    
    return count;
}

//dynamic arrays
User* userArray = nullptr;

Transaction* transactionArray = nullptr;

TransactionBlock* transactionBlockArray = nullptr;

//number of users/tr. blocks
unsigned numUsers = 0; //number of users count
unsigned numTransactions = 0; //number of transactions of the users -- should be the same numbers as users
unsigned numTransactionsBlocks = 0; //number of transactions count

#endif
