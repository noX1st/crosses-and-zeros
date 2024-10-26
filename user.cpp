#include "user.h"

User::User() {}

User::User(const QString& username, const QString& email, const QString& password, const QDate& birthday_)
    : username(username), password(password), email(email), birthday(birthday_), winGames(0), userRating(0.0) {}

User::User(const User& other)
    : username(other.username), password(other.password), email(other.email), birthday(other.birthday), winGames(other.winGames), userRating(other.userRating) {}

const QString User::get_username() const
{
    return username;
}

const QString User::get_password() const
{
    return password;
}

const QString User::get_email() const
{
    return email;
}

const QDate User::get_birthday() const
{
    return birthday;
}

 int User::get_winGames() const
{
    return winGames;
}

 double User::get_userRating() const
{
    return userRating;
}

void User::set_username(const QString& username_)
{
    username = username_;
}

void User::set_password(const QString& password_)
{
    password = password_;
}

void User::set_email(const QString& email_)
{
    email = email_;
}

void User::set_birthday(const QDate& birthday_)
{
    birthday = birthday_;
}

void User::set_winGames(const int winGames_)
{
    winGames = winGames_;
}

void User::set_userRating(const double userRating_)
{
    userRating = userRating_;
}

User& User::operator++()
{
    ++winGames;
    return *this;
}

User User::operator++(int)
{
    User temp = *this;
    ++winGames;
    return temp;
}

User& User::operator--()
{
    --winGames;
    return *this;
}

User User::operator--(int)
{
    User temp = *this;
    --winGames;
    return temp;
}

User& User::operator+(double addRating)
{
    userRating += addRating;
    return *this;
}

User& User::operator-(double decreaseRating)
{
    userRating -= decreaseRating;
    return *this;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        username = other.username;
        password = other.password;
        email = other.email;
        birthday = other.birthday;
        userRating = other.userRating;
        winGames = other.winGames;
    }
    return *this;
}
