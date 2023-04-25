#include <iostream>
#include <cstring>

class BankAccount
{
public:
    BankAccount();
    BankAccount(const char id[8], const char *name, double balance);
    BankAccount(const BankAccount &other);
    BankAccount &operator=(const BankAccount &other);
    ~BankAccount();
    
    //getters
    const char *getId() const;
    const char *getName() const;
    double getBalance() const;
    
    //setters
    void setId(const char id[8]);
    void setName(const char *name);
    void setBalance(double balance);
    
    void withdrawMoney(double amount);
    void print() const;
private:
    char id[8];
    char *name;
    double balance;
};

BankAccount::BankAccount() : name(nullptr), balance(0)
{
    setName("DEFAULT_NAME");
    strcpy(id, "UNKNOWN");
}


BankAccount::BankAccount(const char id[8], const char *name, double balance) : name(nullptr)
{
    setId(id);
    setName(name);
    setBalance(balance);
}

BankAccount::BankAccount(const BankAccount &other) : balance(other.balance)
{
    strcpy(id, other.id);
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

BankAccount& BankAccount::operator=(const BankAccount &other)
{
    if (this != &other)
    {
        strcpy(id, other.id);
        balance = other.balance;
        delete []name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

BankAccount::~BankAccount()
{
    delete []name;
}

const char * BankAccount::getId() const
{
    return id;
}

const char * BankAccount::getName() const
{
    return name;
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::setId(const char *id)
{
    if (strlen(id) != 7)
    {
        std::cout << "Invalid id\n";
        strcpy(this->id, "INVALID");
    }
    strcpy(this->id, id);
}

void BankAccount::setName(const char *name)
{
    if (name == nullptr)
    {
        return;
    }
    if (this->name == nullptr)
    {
        delete []this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void BankAccount::setBalance(double balance)
{
    if (balance <= 0 )
    {
        this->balance = 0;
    }
    this->balance = balance;
}

void BankAccount::withdrawMoney(double amount)
{
    if (amount > balance)
    {
        std::cout << "Insufficient balance!\n";
        return;
    }
    balance -= amount;
}

void BankAccount::print() const
{
    std::cout << "Id" << id << '\n';
    std::cout << "Name" << name << '\n';
    std::cout << "Balance" << balance << '\n';
}

int main()
{
    return 0;
}

