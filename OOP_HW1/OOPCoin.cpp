#include "OOPCoin.hpp"

//void createBlock(std::ofstream& file);

void readUsers(const char* filePath)
{
    std::ifstream readFile(filePath, std::ios::binary);
    if (!readFile.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
        return;
    }
    
    numUsers = countUsers(USERS_FILE_PATH);
    userArray = new User[numUsers];
    int counter = 0;
    while (counter < numUsers)
    {
        readFile.read(reinterpret_cast<char*>(&userArray[counter]), sizeof(User));
        counter++;
    }
    
    readFile.close();
}

void readTransactions(const char* filePath)
{
    std::ifstream readFile(filePath, std::ios::binary);
    if (!readFile.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
    }
    numTransactions = countTransactions(TRANSACTIONS_FILE_PATH);
    transactionArray = new Transaction[numTransactions];
    int counter = 0;
    while (counter < numTransactions)
    {
        readFile.read(reinterpret_cast<char*>(&transactionArray[counter]), sizeof(Transaction));
        counter++;
    }
    
    readFile.close();
}


void readTransactionBlock(const char* filePath)
{
    std::ifstream readFile(filePath, std::ios::binary);
    if (!readFile.is_open())
    {
        std::cout << "Error opening file for reading!" << std::endl;
    }
    numTransactionsBlocks = countTransactionBlocks(TRANSACTON_BLOCK_FILE_PATH);
    transactionBlockArray = new TransactionBlock[numTransactions];
    int counter = 0;
    while (counter < numTransactionsBlocks)
    {
        readFile.read(reinterpret_cast<char*>(&transactionBlockArray[counter]), sizeof(TransactionBlock));
        counter++;
    }
    
    readFile.close();
}


void writeUsers(const char* filepath)
{
    std::ofstream writeFile(filepath, std::ios::binary);
    if (!writeFile.is_open())
    {
        std::cout << "Error opening file for writing!" << std::endl;
    }
    writeFile.write(reinterpret_cast<char*>(userArray), numUsers * sizeof(User));
    writeFile.close();
}

void writeTransactions(const char* filepath)
{
    std::ofstream writeFile(filepath, std::ios::binary);
    if (!writeFile.is_open())
    {
        std::cout << "Error opening file for writing!" << std::endl;
    }
    writeFile.write(reinterpret_cast<char*>(transactionArray), numTransactions * sizeof(Transaction));
    writeFile.close();
}


void writeTransactionsBlocks(const char* filepath)
{
    std::ofstream writeFile(filepath, std::ios::binary);
    if (!writeFile.is_open())
    {
        std::cout << "Error opening file for writing!" << std::endl;
    }
    writeFile.write(reinterpret_cast<char*>(transactionBlockArray),  numTransactionsBlocks * sizeof(TransactionBlock));
    writeFile.close();
}


void createUser(const char name[128], double coins)
{
    
    double new_coins = 420*coins;
    if (numUsers == 0 && numTransactions == 0)
    {
        //first ever user is the Admin
        //users
        strcpy(userArray[numUsers].name , name);
        userArray[numUsers].id = 0;
        //transactions
        transactionArray[numTransactions].sender = 0;
        transactionArray[numTransactions].receiver = 0;
        transactionArray[numTransactions].coins = new_coins;
        transactionArray[numTransactions].time = std::time(NULL);
        std::cout << "First user - system admin! with name " << name << " and id : " << 0 << "\nUser has balance of [" << new_coins << "] OOPCoins" << '\n';
        numUsers++;
        numTransactions++;
        
        return;
    }
    
    //USERS ACTIONS
    User *buffer = new User[numUsers];
    for (int i = 0; i < numUsers; i++)
    {
        strcpy(buffer[i].name, userArray[i].name);
        buffer[i].id = userArray[i].id;
    }
    
    delete []userArray;
    userArray = new User[numUsers + 1];
    numUsers++;
    for (unsigned j = 0; j < numUsers; j++)
    {
        strcpy(userArray[j].name, buffer[j].name);
        userArray[j].id = buffer[j].id;
    }
    delete []buffer;
    
    //TRANSATIONS ACTIONS
    Transaction *tr_buffer = new Transaction[numTransactions];
    for (unsigned i = 0; i < numTransactions; i++)
    {
        tr_buffer[i].sender = transactionArray[i].sender;
        tr_buffer[i].receiver = transactionArray[i].receiver;
        tr_buffer[i].coins = transactionArray[i].coins;
        tr_buffer[i].time = transactionArray[i].time;
    }

    delete []transactionArray;
    transactionArray = new Transaction[numTransactions + 1];
    numTransactions++;
    for (int j = 0; j < numTransactions; j++)
    {
        transactionArray[j].sender = tr_buffer[j].sender;
        transactionArray[j].receiver = tr_buffer[j].receiver;
        transactionArray[j].coins = tr_buffer[j].coins;
        transactionArray[j].time = tr_buffer[j].time;
    }
    delete []tr_buffer;

    //users array changes
    strcpy(userArray[numUsers-1].name , name);
    userArray[numUsers-1].id = (userArray[numUsers-2].id) + 1;

    //transactionArray changes
    transactionArray[numTransactions-1].receiver = (transactionArray[numTransactions-2].receiver) + 1;
    transactionArray[numTransactions-1].sender = transactionArray[numTransactions-2].sender;
    transactionArray[numTransactions-1].coins = new_coins;
    transactionArray[numTransactions-1].time = std::time(NULL);

    std::cout << "Create user with name " << name << " and id : " << userArray[numUsers-1].id << '\n';
    std::cout << "User has [" << new_coins  << "] OOP coins\n";
}


void createBlock() {
    if (numTransactions % 16 == 0 && numTransactionsBlocks == 0) {
        //create a new block
        TransactionBlock block;
        block.id = 0;
        block.prevBlockId = 0;
        block.prevBlockHash = 0;
        block.validTransactions = 0;
        
        //copy transactions to the block
        for (int i = 0; i < 16; i++) {
            if (numTransactions - 16 + i < numTransactions) {
                block.transactions[i] = transactionArray[numTransactions - 16 + i];
                block.validTransactions++;
            }
        }
        
        transactionBlockArray[numTransactionsBlocks] = block;
        numTransactionsBlocks++;
    }
    if (numTransactions % 16 == 0 && numTransactionsBlocks >= 1) {
        //create a new block
        TransactionBlock block;
        block.id = numTransactionsBlocks;
        block.prevBlockId = numTransactionsBlocks - 1;
        block.prevBlockHash = computeHash(reinterpret_cast<const unsigned char*>(&transactionBlockArray[numTransactionsBlocks-1]), sizeof(TransactionBlock));
        block.validTransactions = 0;
        
        //copy transactions to the block
        for (int i = 0; i < 16; i++) {
            if (numTransactions - 16 + i < numTransactions) {
                block.transactions[i] = transactionArray[numTransactions - 16 + i];
                block.validTransactions++;
            }
        }
        
        transactionBlockArray[numTransactionsBlocks] = block;
        numTransactionsBlocks++;
    }
}


void removeUser(char *name)
{
    int index = -1;
    for (unsigned i = 0; i < numUsers; i++)
    {
        if (strcmp(userArray[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        std::cout << "No such user!\n";
        return;
    }
    
    if(userArray[0].id == 0 && transactionArray[0].receiver == 0)
    {
        unsigned getCoins = transactionArray[index].coins;
        unsigned adminCoins = transactionArray[0].coins;
        
        transactionArray[0].coins = getCoins + adminCoins;
    }
    
    //create temporary arrays
    User *userBuffer = new User[numUsers - 1];
    Transaction *transactionBuffer = new Transaction[numTransactions - 1];
    
    //copy elements before the user to be removed
    for (unsigned i = 0; i < index; i++) {
        strcpy(userBuffer[i].name, userArray[i].name);
        userBuffer[i].id = userArray[i].id;
    }
    //copy transactions
    for (unsigned i = 0; i < index; i++) {
        transactionBuffer[i].sender = transactionArray[i].sender;
        transactionBuffer[i].receiver = transactionArray[i].receiver;
        transactionBuffer[i].coins = transactionArray[i].coins;
        transactionBuffer[i].time = transactionArray[i].time;
    }
    
    //copy elements after the user to be removed
    for (unsigned i = index + 1; i < numUsers; i++)
    {
        strcpy(userBuffer[i - 1].name, userArray[i].name);
        userBuffer[i - 1].id = userArray[i].id;
    }
    //copy transactions
    for (unsigned i = index + 1; i < numTransactions; i++)
    {
        transactionBuffer[i-1].sender = transactionArray[i].sender;
        transactionBuffer[i-1].receiver = transactionArray[i].receiver;
        transactionBuffer[i-1].coins = transactionArray[i].coins;
        transactionBuffer[i-1].time = transactionArray[i].time;
    }
    
    //delete the original arrays and create new
    delete[] userArray;
    delete[] transactionArray;
    userArray = new User[numUsers - 1];
    transactionArray = new Transaction[numTransactions - 1];
    numUsers--;
    numTransactions--;
    
    //copy elements from the temporary arrays to the new arrays
    for (unsigned i = 0; i < numUsers; i++)
    {
        strcpy(userArray[i].name, userBuffer[i].name);
        userArray[i].id = userBuffer[i].id;
    }
    for (unsigned i = 0; i < numTransactions; i++)
    {
        transactionArray[i].sender = transactionBuffer[i].sender;
        transactionArray[i].receiver =transactionBuffer[i].receiver;
        transactionArray[i].coins = transactionBuffer[i].coins;
        transactionArray[i].time = transactionBuffer[i].time;
    }
    delete[] userBuffer;
    delete[] transactionBuffer;
    
    std::cout << "User with name: " << name <<" removed!\n";
}


void sendCoins(int sender_id, int receiver_id, double amount)
{
    //find the sender and receiver in the user array
    int sender_index = -1;
    int receiver_index = -1;
    for (int i = 0; i < numUsers; i++)
    {
        if (userArray[i].id == sender_id)
        {
            sender_index = i;
        } else if (userArray[i].id == receiver_id)
        {
            receiver_index = i;
        }
    }
    
    //check if both sender and receiver exist in the user array
    if (sender_index == -1 || receiver_index == -1)
    {
        std::cout << "Error: Invalid sender or receiver ID." << std::endl;
        return;
    }
    
    //check if sender has enough balance to send coins
    if (transactionArray[sender_index].coins < amount)
    {
        std::cout << "Error: Insufficient balance." << std::endl;
        return;
    }
    
    //update sender and receiver balances
    transactionArray[sender_index].coins -= amount;
    transactionArray[receiver_index].coins += amount;
    
    //record transaction
    transactionArray[numTransactions].sender = sender_id;
    transactionArray[numTransactions].receiver = receiver_id;
    transactionArray[numTransactions].coins = amount;
    transactionArray[numTransactions].time = std::time(NULL);
    std::cout << "Transaction successful at time " << std::time(NULL) << std::endl;
}


//Note : used selection sort to sort the wealth of the users in a decreasing manner as well as sort their names!
void selectionSort()
{
    for (int i = 0; i < numUsers-1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < numUsers; j++)
        {
            if (transactionArray[j].coins > transactionArray[maxIdx].coins)
            {
                maxIdx = j;
            }
        }
        unsigned temp = transactionArray[i].coins;
        transactionArray[i].coins = transactionArray[maxIdx].coins;
        transactionArray[maxIdx].coins = temp;
        char names[128];
        strcpy(names , userArray[i].name);
        strcpy(userArray[i].name, userArray[maxIdx].name);
        strcpy(userArray[maxIdx].name, names);
    }
}
void wealthiestUsers(unsigned numberOfTopUsers)
{
    if (numberOfTopUsers > numUsers)
    {
        std::cout << "Insufficient amount of users!\n";
    }
    else
    {
        selectionSort();
        
        for (unsigned i = 0; i < numberOfTopUsers; i++)
        {
            std::cout << "User : " << userArray[i].name << " with balance of[" << transactionArray[i].coins << "] coins" <<'\n';
        }
        std::ofstream outFile(WEALTHIEST_USERS_FILE_PATH);
        if (outFile.is_open())
        {
            for (unsigned i = 0; i < numberOfTopUsers; i++)
            {
                outFile << "User : " << userArray[i].name << " with balance of [" << transactionArray[i].coins << "] coins" << '\n';
            }
            outFile.close();
            std::cout << "Data saved in wealthiest_users.txt\n";
        }
        else
        {
            std::cout << "Failed to open wealthiest_users.txt\n";
        }
    }
}


void getBiggestBlocks(int n) {
    double* blockSums = new double[numTransactionsBlocks];
    for (int i = 0; i < numTransactionsBlocks; i++) {
        double sum = 0;
        for (int j = 0; j < transactionBlockArray[i].validTransactions; j++) {
            sum += transactionBlockArray[i].transactions[j].coins;
        }
        blockSums[i] = sum;
    }
    
    for (int i = 0; i < numTransactionsBlocks - 1; i++) {
        for (int j = i + 1; j < numTransactionsBlocks; j++) {
            if (blockSums[i] < blockSums[j]) {
                double tempSum = blockSums[i];
                blockSums[i] = blockSums[j];
                blockSums[j] = tempSum;
                
                TransactionBlock tempBlock = transactionBlockArray[i];
                transactionBlockArray[i] = transactionBlockArray[j];
                transactionBlockArray[j] = tempBlock;
            }
        }
    }
    
    for (int i = 0; i < n && i < numTransactionsBlocks; i++) {
        std::cout << "Top Block " << i + 1 << " has : [" << blockSums[i] << "] coins\n";
    }
    
    std::ofstream outfile(BIGGEST_BLOCKS_FILE_PATH);
    for (int i = 0; i < n && i < numTransactionsBlocks; i++)
    {
        outfile << "Top Block " << i + 1 << " has : [" << blockSums[i] << "] coins\n";
    }
    outfile.close();
    
    delete[] blockSums;
}




void verifyTransactions()
{
    for (int i = 0; i < numTransactionsBlocks; i++)
    {
        TransactionBlock block = transactionBlockArray[i];
        //check that the first block has a prevBlockId of 0 and a prevBlockHash of 0
        if (i == 0 && (block.prevBlockId != 0 || block.prevBlockHash != 0))
        {
            std::cout << "Error: First block has invalid prevBlockId or prevBlockHash\n";;
            return;
        }
        //check that the block has at least 1 transaction
        if (block.validTransactions < 1)
        {
            std::cout << "Error: Block " << block.id << " has no valid transactions\n";
            return;
        }
        if (i > 0 && block.prevBlockHash != computeHash(reinterpret_cast<const unsigned char*>(&transactionBlockArray[i-1]), sizeof(TransactionBlock)))
        {
            std::cout << "Error: Block " << block.id << " has invalid prevBlockHash\n";
            return;
        }
        if (i > 0 && block.prevBlockId != transactionBlockArray[i-1].id)
        {
            std::cout << "Error: Block " << block.id << " has invalid prevBlockId\n";
            return;
        }
    }
    
    std::cout << "All transactions are valid.\n";
    
}


void run()
{
    readUsers(USERS_FILE_PATH);
    readTransactions(TRANSACTIONS_FILE_PATH);
    readTransactionBlock(TRANSACTON_BLOCK_FILE_PATH);
    
    
    //I have somekind of problem that block with index 0 and index 1 get created at the same time, but other stuff are ok - meaning that the first block gets created twice with index 0 and 1, others are completely okay based on testing
    
//    double coins = 1;
//    for (int i = 0; i < 16; i++)
//    {
//        createUser("GucciGuy", coins);
//        createBlock();
//        coins += 1;
//    }
    
    //Note : I HAVE also changed biggest-blocks, wealthiest-users and verify-transaction names, check them they are called BB, WU, VT
    char input[16];
    while (true)
    {
        std::cout << "Enter a command: ";
        std::cin >> input;
        
        if (std::strcmp(input, "create-user") == 0)
        {
            char name[128];
            std::cout << "Enter name: ";
            std::cin >> name;
            double coins;
            std::cout << "Enter leva: ";
            std::cin >> coins;
            if(coins >= 0)
            {
                createUser(name, coins);
                createBlock();
            }
            else
            {
                std::cout << "Invalid coins!";
                break;
            }
        } else if (std::strcmp(input, "remove-user") == 0) {
            char name[128];
            std::cout << "Enter username to remove: ";
            std::cin >> name;
            removeUser(name);
        } else if (std::strcmp(input, "send-coins") == 0) {
            unsigned senderId, receiverId;
            double amount;
            long long time;
            std::cout << "Enter sender ID: ";
            std::cin >> senderId;
            std::cout << "Enter receiver ID: ";
            std::cin >> receiverId;
            std::cout << "Enter coins: ";
            std::cin >> amount;
            time = std::time(NULL);
            sendCoins(senderId, receiverId, amount);
        } else if (std::strcmp(input, "BB") == 0) {
            unsigned number;
            std::cout << "Input how many of the top blocks do you want : ";
            std::cin >> number;
            getBiggestBlocks(number);
            break;
        } else if (std::strcmp(input, "exit") == 0) {
            std::cout << "Shutting down...Changes saved\n";
            //Save all the data and delete every dynamic array
            writeUsers(USERS_FILE_PATH);
            writeTransactionsBlocks(TRANSACTON_BLOCK_FILE_PATH);
            writeTransactions(TRANSACTIONS_FILE_PATH);
            break;
        } else if(std::strcmp(input, "WU") == 0) {
            unsigned topUsers;
            std::cout << "Input how many of the top wealthiest users you want : ";
            std::cin >> topUsers;
             wealthiestUsers(topUsers);
            break;
        } else if(std::strcmp(input, "VT") == 0) {
            verifyTransactions();
        }
        else
        {
            std::cout << "Invalid command!\n";
            break;
        }
    }
}

int main()
{
    run();
    //delete arrays to free memory
    delete []userArray;
    delete []transactionArray;
    delete []transactionBlockArray;
    return 0;
}
