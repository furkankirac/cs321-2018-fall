#include <iostream>
#include <string>

using namespace std;
unsigned int num_accounts = 0;


struct Account
{
    unsigned int account_id;
    string user_name;

    Account(string user_name, unsigned int account_id):account_id(account_id), user_name(user_name) { }
    Account() { }

    void changeAccountUser(string const input_name);
    void printAccount() const;
};

void Account::changeAccountUser(string const input_name)
{
    this->user_name = input_name;
}

void Account::printAccount() const
{
    printf("User name : %s \t" "account ID : %i\n",
           this->user_name.c_str(),
           this->account_id);
}

Account accounts[10];

void addAccount(string const input_name, unsigned int account_id)
{
    accounts[num_accounts] = Account(input_name, account_id);
    num_accounts++;
}

int main()
{
    printf("\nTest Add account \n");
    //Test change user name witha random account id:
    addAccount("NewUser1", 75);
    accounts[0].printAccount();

    printf("\nTest changeAccountUser \n");
    //Test change user name:
    accounts[0].changeAccountUser("ChangedUser");
    accounts[0].printAccount();

    printf("\nTest Add user \n");
    //Add three more accounts:
    for (unsigned int i = 0; i < 3; ++i)
        addAccount("FirstUser" + std::to_string(i), i*i);

    for(unsigned int i = 0; i<num_accounts;i++)
        accounts[i].printAccount();

    return 0;
}
